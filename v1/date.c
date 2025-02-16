/* File        : date.c */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "date.h"

/*********** Operasi Primitif ************/
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
void CreateDate (date * D){
	SetTgl (01, &(* D));
	SetBln (01, &(* D));
	SetThn (1900, &(* D));
}

/******* Selector komponen **********/
/* Mengambil bagian Tgl dari date */
int GetTgl (date D){
	return(D.Tgl);
	
}

/* Mengambil bagian Bln dari date */
int GetBln (date D){
	return(D.Bln);
}

/* Mengambil bagian Thn dari date */
int GetThn (date D){
	return(D.Thn);
}


/****** Pengubah komponen ******/
/* Memberi nilai untuk Tgl */
void SetTgl (int NewTgl, date * D){
	(* D).Tgl = NewTgl;
}

/* Memberi nilai untuk Bln */
void SetBln (int NewBln, date * D){
	(* D).Bln = NewBln;
}

/* Memberi nilai untuk Thn */
void SetThn (int NewThn, date * D){
	(* D).Thn = NewThn;
}


/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
void ReadDate (date * D){
	int ktgl,kbln,kthn;
	printf("Tanggal : ");
	scanf("%d", &ktgl);
	printf("Bulan : ");
	scanf("%d", &kbln);
	printf("Tahun : ");
	scanf("%d", &kthn);
	SetTgl(ktgl, D);
	SetBln(kbln, D);
	SetThn(kthn, D);
	if(!isValid(* D)){
		exit(0);
	}
}

/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
boolean isValid(date D){
	if ((GetThn(D) < 1900)||(GetThn(D) > 30000)||(GetBln(D) < 1) ||(GetBln(D) > 12)||(GetTgl(D) < 1)||(GetTgl(D) > getEndDate(D)))
		return (false);
	else
		return (true);
}

/* Print nilai D dengan format dd/mm/yyyy */
void PrintObj (date D){
	printf ("%d/%d/%d\n", GetTgl(D), GetBln(D), GetThn(D));
}

/****** Operator Relasional ******/
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
boolean isKabisat (date D){
	int kabisat=GetThn(D);
	if(kabisat%4==0){
		return true;
	}
	else{
		return false;
	}
}

/***** Predikat lain *******/
/* Memberikan tanggal terakhir dari sebuah bulan */
int getEndDate (date D){
	int bulan=GetBln(D);
	if(bulan<=7){
		if(bulan==2){
			if(isKabisat(D)){
				return 29;
			}
			else{
				return 28;
			}
		} else if(bulan%2==0){
			return 30;
		}else{
			return 31;
		}
	}
	else{
		if(bulan%2==0){
			return 31;
		}
		else{
			return 30;
		}
	}
}

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
void DateBefore (date D){
	int tgl1,bln1,thn1;
	tgl1=GetTgl(D);
	bln1=GetBln(D);
	thn1=GetThn(D);

	tgl1-=1;
	if(tgl1==0){
		int akhirbulan;
		bln1-=1;
		if(bln1<=7){
			if(bln1==2){
				if(thn1%4==0){
					akhirbulan=29;
				}
				else{
					akhirbulan=28;
				}
			} else if(bln1%2==0){
				akhirbulan= 30;
			}else{
				akhirbulan= 31;
			}
		}
		else{
			if(bln1%2==0){
				akhirbulan =31;
			}
			else{
				akhirbulan= 30;
			}
		}
	tgl1=akhirbulan;

	if(bln1==0){
		tgl1=31;
		bln1=12;
		thn1-=1;
	}
	}

	printf("\nsebelum tanggal : ");
	PrintObj (D);
	printf("adalah tanggal ");
	printf("%d/%d/%d\n\n",tgl1,bln1,thn1);
}

/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
void NextDate (date D){
	int tgl,bln,thn;
	tgl=GetTgl(D);
	bln=GetBln(D);
	thn=GetThn(D);
	int akhirbulan=getEndDate(D);
	tgl+=1;
	if(tgl>akhirbulan){
		tgl=1;
		bln+=1;
		if(bln==13){
			tgl=1;
			bln=1;
			thn+=1;
		}
	}
	printf("\nsetelah tanggal : ");
	PrintObj (D);
	printf("adalah tanggal ");
	printf("%d/%d/%d\n\n",tgl,bln,thn);
}

/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
void DifferenceDate (date D1, date D2){
	int tgl1,bln1,thn1,count=0;
	tgl1=GetTgl(D1);
	bln1=GetBln(D1);
	thn1=GetThn(D1);

	int tgl2,bln2,thn2;
	tgl2=GetTgl(D2);
	bln2=GetBln(D2);
	thn2=GetThn(D2);

	if(thn1<thn2){
		int temp1,temp2,temp3;
		temp1=thn1;
		temp2=bln1;
		temp3=tgl1;
		thn1=thn2;
		bln1=bln2;
		tgl1=tgl2;
		thn2=temp1;
		bln2=temp2;
		tgl2=temp3;
	}
	else if (bln1<bln2){
		int temp1,temp2,temp3;
		temp1=thn1;
		temp2=bln1;
		temp3=tgl1;
		thn1=thn2;
		bln1=bln2;
		tgl1=tgl2;
		thn2=temp1;
		bln2=temp2;
		tgl2=temp3;
	}

	else if(tgl1<tgl2){
		int temp1,temp2,temp3;
		temp1=thn1;
		temp2=bln1;
		temp3=tgl1;
		thn1=thn2;
		bln1=bln2;
		tgl1=tgl2;
		thn2=temp1;
		bln2=temp2;
		tgl2=temp3;
	}

	while(tgl1!=tgl2 || bln1!=bln2 || thn1!=thn2){
		tgl1-=1;
		if(tgl1==0){
			int akhirbulan;
			bln1-=1;
			if(bln1<=7){
				if(bln1==2){
					if(thn1%4==0){
						akhirbulan=29;
					}
					else{
						akhirbulan=28;
					}
				} else if(bln1%2==0){
					akhirbulan= 30;
				}else{
					akhirbulan= 31;
				}
			}
			else{
				if(bln1%2==0){
					akhirbulan =31;
				}
				else{
					akhirbulan= 30;
				}
			}
		tgl1=akhirbulan;

		if(bln1==0){
			tgl1=31;
			bln1=12;
			thn1-=1;
		}
		}
		count+=1;
	}

	printf("selisih antara");
	PrintObj(D1);
	printf(" dan ");
	PrintObj(D2);
	printf("adalah\n");
	printf("%d", count);

	/*
	while(D1.Tgl!=D2.Tgl && D1.Bln!=D2.Thn && D1.Thn!=D2.Thn){
		//while (!isValid(D1)){
			//while(getEndDate(D1)<D1.Bln){}	
	//}
	if(D1.thn>D2.thn){
		;
	}
		
	DateBefore(D1);
	if((D1.Tgl==D2.Tgl && D1.Bln==D2.Thn && D1.Thn==D2.Thn)){
		break;
	}
	DateAfter(D2);
	}
	*/
}

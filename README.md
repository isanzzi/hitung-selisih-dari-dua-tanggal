# Aplikasi Perhitungan Selisih Dua Tanggal

Aplikasi ini merupakan program untuk melakukan berbagai operasi pada tanggal (date), terutama untuk menghitung selisih antara dua buah tanggal. Program ini diimplementasikan menggunakan Abstract Data Type (ADT) Date dalam bahasa C.

## Struktur Project

Project ini terdiri dari beberapa file:

- **boolean.h** - Header file untuk menangani tipe data boolean
- **date.h** - Header file yang berisi spesifikasi modul ADT Date
- **date.c** - Implementasi dari ADT Date
- **mdate.c** - Program utama (main) yang menjadi driver untuk menggunakan ADT Date

## Fitur

Program ini menyediakan beberapa fitur untuk manipulasi tanggal:

1. Membuat objek tanggal dengan nilai default (01/01/1900)
2. Membaca input tanggal dari keyboard
3. Validasi tanggal
4. Menampilkan tanggal dalam format dd/mm/yyyy
5. Mengecek tahun kabisat
6. Menampilkan tanggal sebelumnya dari tanggal tertentu
7. Menampilkan tanggal berikutnya dari tanggal tertentu
8. Menghitung selisih antara dua tanggal

## Cara Kompilasi

Untuk mengkompilasi program ini, gunakan GCC (GNU Compiler Collection):

```bash
gcc mdate.c date.c -o date_calculator
```

## Cara Penggunaan

Setelah berhasil dikompilasi, jalankan program dengan cara:

```bash
./date_calculator
```

Program akan melakukan hal-hal berikut:

1. Membuat tanggal default dan menampilkannya
2. Meminta pengguna memasukkan tanggal pertama (D2)
3. Menampilkan informasi apakah tahun tersebut kabisat
4. Menampilkan tanggal sebelum dan sesudah tanggal yang dimasukkan
5. Meminta pengguna memasukkan tanggal kedua (D3)
6. Menghitung dan menampilkan selisih antara kedua tanggal
7. Memberikan opsi untuk mencoba lagi

## Format Input Tanggal

Saat diminta memasukkan tanggal, input harus dalam format:

- Tanggal: 1-31 (tergantung bulan)
- Bulan: 1-12
- Tahun: 1900-30000

Jika tanggal yang dimasukkan tidak valid, program akan meminta input ulang.

## Batasan

- Tahun yang valid adalah antara 1900 hingga 30000
- Program menganggap tahun kabisat adalah tahun yang habis dibagi 4

## Contoh Penggunaan

```
maka D1 bernilai : 1/1/1900

Tanggal : 15
Bulan : 3
Tahun : 2023

maka D2 bernilai:15/3/2023
2023 adalah tahun Kabisat

Sebelum tanggal : 15/3/2023
adalah tanggal 14/3/2023

Setelah tanggal : 15/3/2023
adalah tanggal 16/3/2023

Tanggal : 20
Bulan : 4
Tahun : 2023
setelah perintah BacaDate(&D3), maka d3 bernilai : 20/4/2023
selisih antara15/3/2023 dan 20/4/2023
adalah
37 hari

Coba lagi? (y/t)
```

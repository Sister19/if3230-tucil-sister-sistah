# Tugas Kecil 3 : CUDA

Program Paralelisasi dalam bahasa C dengan menggunakan teknologi CUDA untuk melakukan transformasi Fourier diskrit dua dimensi (2D DFT) pada matriks input. DFT adalah algoritma yang digunakan untuk mengubah sinyal domain waktu menjadi sinyal domain frekuensi.

## Penjelasan Program

Program ini merupakan implementasi dari transformasi Fourier diskrit (DFT) pada platform CUDA untuk mempercepat perhitungan DFT pada data matriks. Program ini menggunakan library Thrust untuk tipe data kompleks.

Pada fungsi dft, setiap thread pada blok yang dijalankan akan menghitung satu elemen dari domain frekuensi. Elemen ini dihitung dengan menjumlahkan kontribusi dari setiap elemen pada domain waktu, sesuai dengan formula DFT.

Setiap thread akan menghitung koefisien frekuensi dengan menggunakan dua variabel k dan l. Kemudian, dilakukan iterasi melalui elemen matriks menggunakan variabel m dan n. Setiap iterasi menghitung panjang vektor frekuensi, koefisien fase, dan koefisien matriks asli. Selanjutnya, elemen tersebut ditambahkan ke dalam koefisien frekuensi. Hasil akhir dihitung dengan membagi koefisien frekuensi dengan jumlah total elemen dalam matriks.

Di dalam fungsi main(), matriks input dibaca dari stdin dan kemudian disalin ke dalam memori GPU menggunakan cudaMemcpy(). Kemudian, fungsi dft dijalankan pada GPU dengan ukuran blok dan grid yang sesuai. Hasil DFT diambil dari GPU menggunakan cudaMemcpy() dan dicetak di stdout.

Terakhir, memori GPU dibersihkan dengan cudaFree().


Dalam program ini, matriks input dibagi menjadi beberapa blok, di mana setiap blok diproses oleh satu blok pada GPU. Setiap thread pada blok tersebut kemudian menghitung satu elemen pada domain frekuensi, sehingga setiap elemen dihitung secara paralel. Dengan memproses elemen secara paralel, program dapat mengurangi waktu eksekusi secara signifikan, terutama pada matriks yang sangat besar. Selain itu, program juga menggunakan skema pengiriman data asinkronus antara CPU dan GPU, sehingga pengiriman data dapat dilakukan secara efisien.

## References

 - [CUDA Documentation](https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/)
 - [Materi Kelas](https://cdn-edunex.itb.ac.id/38097-Parallel-and-Distributed-Systems-Parallel-Class/73155-Distributed-Memory-System/1643769784185_IF3230-03-DistributedMemory-2022.pdf)


## Authors

- 13520118 Mohamad Daffa Argakoesoemah
- 13520143 Muhammad Gerald Akbar Giffera
- 13520145 Steven Gianmarg H. Siahaan
- 13520158 Azmi Alfatih Shalahuddin

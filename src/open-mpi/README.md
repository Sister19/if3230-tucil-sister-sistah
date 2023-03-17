
# Tugas Kecil 1 : Open MPI

Paralelisasi algoritma DFT menggunakan library open MPI pada bahasa pemrograman C, pada program paralel ini tugas untuk algoritma DFT dapat dibagi secara seimbang di masing-masing processor yang ada pada komputer, sehingga dapat mengurangi waktu yang diperlukan untuk menjalankan program dan melakukan perhitungan. 


## Penjelasan Program

Program ini memanfaatkan library open MPI untuk memparalelisasi algortima DFT yang ada, secara garis besar program akan membaca input berupa matriks yang direpresntasikan dalam TextFile. Lalu untuk proses perhitungan DFT, program akan membagi processor yang tersedia untuk menghitung sebagian dari matriks sehingga perhitungan DFT bisa dijalankan secara paralel. Setelah mendapatkan nilai untuk masing-masing bagian matriks, nantinya program juga akan menghitung total dari nilai-nilai yang diperoleh dari masing-masing processor, beberapa fungsi open MPI yang dimanfaatkan sebagai berikut:

- `MPI_Reduce` => Untuk menghitung total perhitungan dari tiap processor
- `MPI_Bcast` => Mengirim informasi dari satu processor ke processor lainnya
- `MPI_Comm_size` => Memperoleh informasi jumlah processor yang tersedia
- `MPI_Comm_rank` => Memperoleh informasi processor yang sedang berjalan
## References

 - [MPI Documentation](https://www.mpich.org/static/docs/v3.3/www3/)
 - [Materi Kelas](https://cdn-edunex.itb.ac.id/38097-Parallel-and-Distributed-Systems-Parallel-Class/73155-Distributed-Memory-System/1643769784185_IF3230-03-DistributedMemory-2022.pdf)


## Authors

- 13520118 Mohamad Daffa Argakoesoemah
- 13520143 Muhammad Gerald Akbar Giffera
- 13520145 Steven Gianmarg H. Siahaan
- 13520158 Azmi Alfatih Shalahuddin


## Screenshots


**Dijalankan pada Windows11 - WSL 2 Ubuntu 20.04 - Core i5-1035GP4 CPU @1.1GHz,1498 Mhz**

 TestCase             | Hasil Serial                                                      | Hasil Paralel | 
| ----------------- | ------------------------------------------------------------------ | ------- |
| 32.txt | <img width="475" alt="32 Serial" src="https://user-images.githubusercontent.com/88304745/222876667-ec2a664e-d3e3-461d-9c22-b8bb1c1eba34.png"> |<img width="702" alt="32 Open-MPI" src="https://user-images.githubusercontent.com/88304745/222876743-21424f84-d67a-40ac-9c21-1cc9459653ae.png"> |
| 64.txt | <img width="475" alt="64 Serial" src="https://user-images.githubusercontent.com/88304745/222876747-48735b23-dba2-468c-af06-47b6eafd3a00.png"> |<img width="702" alt="64 Open-MPI" src="https://user-images.githubusercontent.com/88304745/222876751-45fa425e-8bd5-4442-815d-7e8714b25061.png"> |
| 128.txt | <img width="475" alt="128 Serial" src="https://user-images.githubusercontent.com/88304745/222876756-28c3780a-35d5-413b-a9e9-7996b07fa4f5.png"> |<img width="702" alt="128 Open-MPI" src="https://user-images.githubusercontent.com/88304745/222876757-822afda4-3cab-4794-a7e1-5ec3a55ae235.png"> |
| 256.txt | <img width="475" alt="256 Serial 2023-02-24 at 22 30 08" src="https://user-images.githubusercontent.com/88304745/222876773-94089e52-4fe2-46b7-a08a-bca898811d55.png"> |<img width="702" alt="256 Open-MPI" src="https://user-images.githubusercontent.com/88304745/222876780-3f69abb7-ee9b-4560-aa66-efd114f6c05c.png"> |

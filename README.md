# Game Teka-Teki Silang C++

Game Teka-Teki Silang C++ adalah sebuah permainan interaktif yang menantang yang dirancang dengan menggunakan bahasa pemrograman C++. Game ini menguji pengetahuan dan keterampilan pemain dalam mencari dan mengisi kata-kata dalam sebuah grid berbentuk kotak.

Dalam game ini, pemain diberikan petunjuk berupa definisi atau deskripsi kata-kata yang harus mereka temukan dalam grid. Pemain kemudian dapat mengisi jawaban mereka secara horizontal atau vertikal pada kotak-kotak yang tersedia. Semakin banyak kata yang berhasil ditemukan, semakin tinggi skor yang dapat dicapai. Dengan grafis sederhana dan antarmuka yang mudah digunakan, game ini menawarkan pengalaman bermain yang menyenangkan dan menantang bagi pecinta teka-teki dan kata-kata.

# Instalasi
1. Pastikan komputer Anda telah terpasang kompiler C++ yang sesuai, seperti GCC (untuk sistem operasi Linux) atau MinGW (untuk sistem operasi Windows). Jika belum terpasang, Anda dapat menginstalnya dengan mengikuti instruksi yang tersedia di situs resmi masing-masing kompiler.
2. Unduh atau salin kode sumber game teka-teki silang ke direktori atau folder yang diinginkan di komputer Anda.
3. Buka terminal atau command prompt di komputer Anda dan arahkan ke direktori yang berisi kode sumber game teka-teki silang. Anda dapat menggunakan perintah cd untuk berpindah direktori.
4. Setelah berada di direktori yang tepat, kompilasi kode sumber game dengan perintah berikut (gunakan perintah yang sesuai dengan kompiler yang Anda gunakan):
- Untuk GCC (Linux):
  g++ main.cpp -o teka-teki-silang

- Untuk MinGW (Windows):
  g++ main.cpp -o teka-teki-silang.exe

Perintah ini akan mengkompilasi file main.cpp menjadi file eksekusi yang dapat dijalankan.

5. Setelah kompilasi selesai, Anda akan memiliki file teka-teki-silang (atau teka-teki-silang.exe jika Anda menggunakan MinGW) sebagai hasilnya.
6. Jalankan game teka-teki silang dengan perintah berikut:
- Untuk GCC (Linux):
  ./teka-teki-silang

- Untuk MinGW (Windows):
  teka-teki-silang.exe

Pastikan Anda mengikuti langkah-langkah ini dengan hati-hati dan memastikan kompiler C++ telah terinstal dengan benar. Jika terdapat pesan kesalahan saat kompilasi atau saat menjalankan game, periksa kembali langkah-langkah instalasi dan pastikan semua dependensi dan konfigurasi yang diperlukan telah terpenuhi.

# Petunjuk Bermain
1. Ketika pertama kali dijalankan, program akan menampilkan menu permainan. Terdapat 2 menu yaitu Bermain dan Score.
2. Gunakan tombol panah pada keyboard untuk memindahkan kursor, Enter untuk memilih menu.
3. Menu Bermain :
   - Program akan diminta untuk memasukkan nama dari User.
   - Setelah nama ditambahkan, program akan menampilkan petunjuk permainan.
   - Program akan menampilkan soal dan box tempat mengisi jawaban. Setiap box mewakili 1 karakter dari jawaban.
   - Terdapat 10 soal yaitu 5 soal Menurun dan 5 soal Mendatar.
   - Setiap soal yang benar akan bernilai 10 poin maksimal 100.
   - Ketika User selesai mengisi soal, data dari user akan disimpan berupa Linked List yang berisi score dan nama pemain.

4. Menu Score :
   - Program akan menampilkan score dari user secara descending sesuai dengan banyak user yang bermain.
  
5. Selesai.


### Jawaban Terdapat Pada Program

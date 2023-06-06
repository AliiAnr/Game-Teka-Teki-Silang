#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define EXIT 27
#define ENTER 13

int pemain=0;
string vertical_key[5],horizontal_key[5];
int vision_menu[2] = {0};
int cursor_menu[2] = {0};
int move_menu[2] = {0};
int cursor[10][10] = {0};
int vision[10][10] = {0};
//int moveing[10][10] = {0};
char temp;
struct player{
	string pemain;
	int skor;
	player *next;
}*head,*tail,*cur, *newNode, *bermain;

void line(){
   cout<<"====================================================="<<endl;
}

struct answer{
   char key[10][10];
   string verticalKey[5] = {"ALGORITMA", "MOD", "PSEUDOCODE", "AND", "BOOLEAN"};
   string horizontalKey[5] = {"LOGIS", "RAM", "EULER", "DOUBLE", "CHAR"};
}answr;

void reset_value(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			answr.key[i][j]=0;
			cursor[i][j]=0;
		}
	}
	for(int i=0;i<5;i++){
		vertical_key[i]="";
		horizontal_key[i]="";
	}
}

void sleep(int minisecon) {
	clock_t x;
	x = clock() + minisecon * CLOCKS_PER_SEC/1000;
	while (clock() < x) {
	}
}

void tambahpemain(string nama){
	 	if(head==NULL){
	 		head= new player();
			head->pemain=nama;
			head->skor=0;
			head->next= NULL;
			tail=head;
		 	}
		 else {
			newNode= new player();
			newNode->pemain=nama;
			newNode->skor=0;
			newNode->next=NULL;
			tail->next=newNode;
			tail=newNode;
		 	}
		 	cout<<endl;
}

int check(){
   int cek = 0;
   //verticalkey
   for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
         if (i >= 0 && i < 9 && j == 0){
            vertical_key[0] += answr.key[i][j]; 
         }else if (i > 3 && i < 7 && j == 2){
            vertical_key[1] += answr.key[i][j];
         }else if (i >= 0 && i <= 9 & j == 4){
            vertical_key[2] += answr.key[i][j];
         }else if (i > 5 && i < 9 && j == 6){
            vertical_key[3] += answr.key[i][j];
         }else if (i >= 0 && i < 7 && j == 9){
            vertical_key[4] += answr.key[i][j];
         }
      }
   }
   //horizontalKey
   for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
         if (i == 1 && j >= 0 && j < 5){
            horizontal_key[0] += answr.key[i][j];
         }else if (i == 4 && j >= 0 && j < 3){
            horizontal_key[1] += answr.key[i][j];
         }else if (i == 9 && j > 0 && j < 6){
            horizontal_key[2] += answr.key[i][j];
         }else if (i == 4 && j > 3 && j <= 9 ){
            horizontal_key[3] += answr.key[i][j];
         }else if (i == 6 && j > 3 && j < 8){
            horizontal_key[4] += answr.key[i][j];
         }
      }
   }
   
   for (int i = 0; i < 5; i++){
      if (vertical_key[i] == answr.verticalKey[i]){
         cek += 1;
         tail->skor+=10;
      }
      if (horizontal_key[i] == answr.horizontalKey[i]){
         cek += 1;
         tail->skor+=10;
      }
   }
   return cek;
}

void cek (){
   for (int i = 0; i <10; ++i){
      for (int j = 0; j < 10; j++){
         cout<<"jawaban [" <<i<< "]" << "[" <<j<< "] = "<<answr.key[i][j]<<endl;
      }
   }
}

void start();

void space(char length) {
   if (length == 0) {
      cout << " ";
   }
}

void enter() {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if (cursor[i][j] == 1) {
            cout << "Masukkan jawaban = ";
            cin >> answr.key[i][j];
            if (answr.key[i][j] >= 97 && answr.key[i][j] <= 122){
               temp = answr.key[i][j] - 32;
               answr.key[i][j] = temp;
               vision[i][j] = 1;
               system ("cls");
            }
            else if (answr.key[i][j] >=  65 && answr.key[i][j] <= 90){
               vision[i][j] = 1;
               system ("cls");
            }else{
               cout<<"JAWABAN HANYA MENGGUNAKAN 1 KARAKTER KAPITAL !!!"<<endl;
               answr.key[i][j] = 0 ;
               system ("pause");
               system("cls");
            }
         }
      }
   }
}

void cursorUp() {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if ((i > 0 && i <= 8 && j == 0) || (i > 4 && i <= 7 && j == 2) || (i > 0 && i <= 9 && j == 4) || (i > 6 && i <= 8 && j == 6) || (i > 0 && i <= 6 && j == 9)) {
            if (cursor[i][j] == 1) {
               cursor[i - 1][j] = 1;
               cursor[i][j] = 0;
               return;
            }
         }
      }
   }
}

void cursordown() {
   for (int i = 0; i < 10; i++) {
         for (int j = 0; j < 10; j++) {
            if ((i <= 7 && j == 0) || (i > 3 && i < 6 && j == 2) || (i <= 8 && j == 4) || (i >5 && i < 8 && j == 6 ) || (i <= 5 && j == 9)){
               if (cursor[i][j] == 1) {
                  cursor[i + 1][j] = 1;
                  cursor[i][j] = 0;
                  return;
               }
            }
         }
      }
   }

void cursorleft() {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if ((i == 1 && j <= 4) || (i == 4 && j <= 2) || (i == 9 && j > 1 && j <= 5 ) || (i == 4 && j > 4 && j <= 9) || (i == 6 && j > 4 && j <= 7)) {
            if (j - 1 >= 0){
               if (cursor[i][j] == 1) {
                  cursor[i][j - 1] = 1;
                  cursor[i][j] = 0;
                  return;
               }
            }
         }
      }
   }
}

void cursorright() {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if ((i == 1 && j <= 3) || (i == 4 && j <= 1) || (i == 9 && j >= 1 && j <= 4) || (i == 4 && j >= 4 && j <= 8) || (i == 6 && j >= 4 && j <= 6)){
            if (cursor[i][j] == 1) {
                cursor[i][j + 1] = 1;
                cursor[i][j] = 0;
               return;
            }
         }
        
      }
   }
}

void allcursor_menu(int up, int down) {
   if (up == 1) {
      for (int i = 0; i < 2; i++) {
         if (i - 1 >= 0) {
            if (move_menu[i] == 1) {
               move_menu[i - 1] = 1;
               move_menu[i] = 0;
               return;
            }
         }
      }
   }
   if (down == 1) {
      for (int i = 0; i < 2; i++) {
         if ((i + 1) <= 1) {
               if (move_menu[i] == 1) {
                  move_menu[i + 1] = 1;
                  move_menu[i] = 0;
                  return;
               }
         }
      }
   }
}

void print(){
	cur=head;
			while(cur!=NULL){
			cout<<"Nama Peserta: "<<cur->pemain<<endl;
			cout<<"Score Peserta: "<<cur->skor<<endl<<endl;
			cur= cur->next;
			
		}
}

void score(){
	int nilai;
	string nama;
	
	for(int a=0; a<=pemain; a++){
         if(pemain>1){	
         cur=head;
            while(cur!=tail){
               if(cur->skor < cur->next->skor) {
                  nilai=cur->next->skor;
                  nama=cur->next->pemain;
                  cur->next->skor=cur->skor;
                  cur->next->pemain=cur->pemain;
                  cur->skor=nilai;
                  cur->pemain=nama;
               }
            cur= cur->next;
         }
	   }
	}
	
	cout<<"==============Rekor Peserta============== "<<endl<<endl;
	print();
}

int main() {
   int input ;
   string menu[2]={"|>> Bermain ","|>> Score   "};
   move_menu[1]=1;
   string nama;
   start:
   cout<<"============================================================"<<endl;
   cout<<"==                         TEKA-TEKI                      =="<<endl;
   cout<<"==                          SILANG                        =="<<endl;
   cout<<"==                        INFORMATIKA                     =="<<endl;
   cout<<"============================================================"<<endl;
   cout<<"Created by: Kelompok 22"<<endl<<endl;
   		for(int a=0; a<1; a++){
   			if(move_menu[a]==0){
   				cout<<menu[a]<<endl;
   				cout<<menu[a+1]<<"<<|"<<endl;
			   }else{
   				cout<<menu[a]<<"<<|"<<endl;
   				cout<<menu[a+1]<<endl;
			   }	
   		}
   		
   		input = getch();
   		if (input == 0 || input == 0xE0) {
      	input = getch();
   		}
   		
   	switch (input) {
      case UP_ARROW:
         system("cls");
         allcursor_menu(1,0);
         goto start;
         break;
      case DOWN_ARROW:
         system("cls");
         allcursor_menu(0,1);
         goto start;
         break;
	   case ENTER:
         if(move_menu[0]==1){
            goto lanjut;
         }
		else{
			system("cls");
			score();
			system("pause");
			system("cls");
			goto start;
		}
		break;
	default:
		goto start;
		break;
	}
	lanjut:
	system("cls");
   line();
	cout<<"Masukkan Nama User: ";cin>>nama;
	tambahpemain(nama);pemain++;
	cout<<"NAMA TELAH DITAMBAHKAN, LESTS GO !!! .(#^.^#)."<<endl<<endl;
   back:
   cout << "------------------Petunjuk permainan-----------------"<<endl;
   line ();
   cout << "Tekan CURSOR PANAH untuk bergerak...................." << endl;
   cout << "Setiap 1 jawaban yang benar akan bernilai 10........."<< endl;
   cout << "Tekan ESC untuk mengumpulkan jawaban................." << endl;
   cout << "Tekan ENTER untuk mengisi jawaban...................." << endl;
   line ();
   cout << "------------Tekan ENTER untuk melanjutkan------------"<<endl;
   input = getch();
   if (input == 0 || input == 0xE0) {
      input = getch();
   }
   switch (input) {
      case ENTER:
         cout<<"LOADING";
		   for(int i=0; i<5; i++) {
			sleep(300);
			cout<<".";
		}
         system("cls");
         start();
         goto start;
         break;
      case EXIT:
         cout<<"TERIMA MAKASIH";
         return 0;
         break;
      default:
         cout << "INPUTAN YANG ANDA MASUKKAN SALAH !!!" << endl;
         goto back;
         break;
   }
}
void column_space(int left_column, int right_column) {
   int kolom;
   kolom = (right_column - left_column) - 1;
   for (int i = 0; i < kolom; i++) {
      cout << "      ";
   }
}

void cursor_move(int i, int j){
   cout << "[<";space(answr.key[i][j]);cout << answr.key[i][j] << ">] ";
}

void vision_(int i, int j, int check_1, int check_2){
   if (check_1==1){
      cout << "[ ";space(answr.key[i][j]);cout << answr.key[i][j] << " ] ";
   }
   if(check_2 == 1){
      space(answr.key[i][j]); cout << answr.key[i][j] << " ] ";
   }
}

void start() {
   SetConsoleOutputCP(65001);
   int input, temp = 0; 
   cursor[0][0] = 1;
   
back_1:
	cout<<"NAMA: "<<tail->pemain<<endl<<endl;
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if (i != 1 && j == 0 && i != 9 && i != 4) {  // ALGORITMA
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 0) {
                     cout << "[\xc2\xb9";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 0) {
                     cout << "[\xc2\xb9";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            }
            // \xc2\xb2
            else {
               cursor_move(i,j);
            }
         } else if (i == 1 && j <= 4) {  // LOGIS
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 1 && j == 0) {
                     cout << "[\xc2\xb9";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 1 && j == 0) {
                     cout << "[\xc2\xb9";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            }
            // \xc2\xb2
            else {
               cursor_move(i,j);
            }
         } else if (i == 4 && j <= 1) {  // RAM
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 4 && j == 0) {
                     cout << "[\xc2\xb2";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 4 && j == 0) {
                     cout << "[\xc2\xb2";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            }
            // \xc2\xb2
            else {
               cursor_move(i,j);
            }
         } else if (i != 1 && j == 4 && i != 9 && i != 4 && i != 6) {  // PSEUDOCODE
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 4 || i == 5 || i == 6) {
                     column_space(2, 4);
                  } else {
                     column_space(0, 4);
                  }
                  if (i == 0) {
                     cout << "[\xc2\xb3";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 4 || i == 5 || i == 6) {
                     column_space(2, 4);
                  } else {
                     column_space(0, 4);
                  }
                  if (i == 0) {
                     cout << "[\xc2\xb3";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 4 || i == 5 || i == 6) {
                  column_space(2, 4);
               } else {
                  column_space(0, 4);
               }
               cursor_move(i,j);
            }
         } else if (i >= 4 && j == 2 && i <= 6) {  // MOD
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 5 || i == 6) {
                     column_space(0, 2);
                  }
                  if (i == 4) {
                     cout << "[\xc2\xb2";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 5 || i == 6) {
                     column_space(0, 2);
                  }
                  if (i == 4) {
                     cout << "[\xc2\xb2";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 5 || i == 6) {
                  column_space(0, 2);
               }
               cursor_move(i,j);
            }

         } else if (i == 9 && j >= 1 && j <= 5) {  // EULER
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 9 && j == 1) {
                     column_space(-1, 1);
                  }
                  if (j == 1) {
                     cout << "[\xc2\xb3";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 9 && j == 1) {
                     column_space(-1, 1);
                  }
                  if (j == 1) {
                     cout << "[\xc2\xb3";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 9 && j == 1) {
                  column_space(-1, 1);
               }
               cursor_move(i,j);
            }
         } else if (i == 4 && j >= 4 && j <= 9) {  // DOUBLE
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 4 && j == 4) {
                     column_space(2, 4);
                  }
                  if (j == 4) {
                     cout << "[4";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 4 && j == 4) {
                     column_space(2, 4);
                  }
                  if (j == 4) {
                     cout << "[4";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 4 && j == 4) {
                  column_space(2, 4);
               }
               cursor_move(i,j);
            }

         } else if (i == 6 && j >= 4 && j <= 7 && j != 6) {  // CHAR
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 6 && j == 4) {
                     column_space(2, 4);
                  }
                  if (j == 4) {
                     cout << "[5";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 6 && j == 4) {
                     column_space(2, 4);
                  }
                  if (j == 4) {
                     cout << "[5";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 6 && j == 4) {
                  column_space(2, 4);
               }
               cursor_move(i,j);
            }
         } else if (j == 6 && i >= 6 && i <= 8) {  // AND
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 7 || i == 8) {
                     column_space(4, 6);
                  }
                  if (i == 6) {
                     cout << "[4";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 7 || i == 8) {
                     column_space(4, 6);
                  }
                  if (i == 6) {
                     cout << "[4";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 7 || i == 8) {
                  column_space(4, 6);
               }
               cursor_move(i,j);
            }
         } else if (j == 9 && i >= 0 && i <= 6 && i != 4) {  // BOOLEAN
            if (cursor[i][j] == 0) {
               if (vision[i][j] == 0) {
                  if (i == 6) {
                     column_space(7, 9);
                  } else {
                     column_space(4, 9);
                  }
                  if (i == 0) {
                     cout << "[5";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               } else if (vision[i][j] == 1) {
                  if (i == 6) {
                     column_space(7, 9);
                  } else {
                     column_space(4, 9);
                  }
                  if (i == 0) {
                     cout << "[5";
                     vision_ (i,j,0,1);
                  } else {
                     vision_ (i,j,1,0);
                  }
               }
            } else {
               if (i == 6) {
                  column_space(7, 9);
               } else {
                  column_space(4, 9);
               }
               cursor_move(i,j);
            }
         }
      }
      cout << endl<< endl;
   }
   
   cout<<"MENURUN"<<endl;
   cout<<"1. Urutan langkah-langkah logis untuk menyelesaikan masalah"<<endl;
   cout<<"2. Operator sisa hasil bagi"<<endl;
   cout<<"3. Algoritma yang bentuknya sangat mirip dengan bahasa pemrograman (terstruktur seperti pascal)"<<endl;
   cout<<"4. Operator yang hanya bernilai benar apabila kedua nilai benar"<<endl;
   cout<<"5. Tipe data yang hanya memiliki dua nilai logika"<<endl<<endl;
   cout<<"MENDATAR"<<endl;
   cout<<"1. Algoritma harus memiliki sifat yang...agar dapat dijangkau oleh akal fikiran kita"<<endl;
   cout<<"2. ....Berfungsi untuk menyimpan hasil kompilasi program"<<endl;
   cout<<"3. Lintasan yang memiliki hanya dua buah derajat berjumlah ganjil"<<endl;
   cout<<"4. Tipe data yang dapat menyimpan nilai dengan angka desimal lebih banyak"<<endl;
   cout<<"5. Tipe data penyimpan karakter"<<endl; 
back_2:
   input = getch();
   if (input == 0 || input == 0xE0) {
      input = getch();
   }
   switch (input) {
      case UP_ARROW:
         system("cls");
         cursorUp();
         goto back_1;
         break;
      case DOWN_ARROW:
         system("cls");
         cursordown();
         goto back_1;
         break;
      case LEFT_ARROW:
         system("cls");
         cursorleft();
         goto back_1;
         break;
      case RIGHT_ARROW:
         system("cls");
         cursorright();
         goto back_1;
         break;
      case ENTER:
         enter();
         goto back_1;
         break;
      case EXIT:
         system("cls");
         temp = check();
            if (temp > 0){
               temp *= 10;
               line ();
               cout<<"-----------------------SELAMAT-----------------------"<<endl;
               cout<<"SCORE AKHIR ANDA ADALAH = "<<temp<<endl;
            }else{
               line ();
               cout<<"------------SCORE AKHIR ANDA ADALAH = "<<temp<<" -------------"<<endl;
               cout<<"----------SEMOGA BERUNTUNG DILAIN WAKTU HEHE---------"<<endl;
            }
            reset_value();
            cout<<endl;
         system("pause");
         system("cls");
         break;
      default:
         cout << "===INPUTAN TIDAK SESUAI===" << endl;
         goto back_2;
         break;
   }
   
}
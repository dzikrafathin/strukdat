#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

// Struct data yang akan digunakan untuk menyimpan data pada container stack
typedef struct{
	int nim;
	double nilai;
}nilaiMatkul;

// Struct container dari stack
typedef struct elmt *alamatelmt;
typedef struct elmt{
	nilaiMatkul kontainer;
	alamatelmt next;
}elemen;

//struct dari sebuah stack
typedef struct{
	elemen* top;
}stack;

//Prosedur untuk membuat sebuah stack kosong
void createEmpty(stack *S){
	(*S).top = NULL;
}
//Prosedur untuk mengecek kekosongan stack
int isEmpty(stack S){
	bool hasil = false;
	//jika top stack bernilai NULL maka stack kosong return true
	if(S.top == NULL){
		hasil = true;
	}
	
	return hasil;
}
//prosedur untuk menghitung jumlah elemen stack
int countElement(stack S){
	int hasil = 0;
	
	if(S.top != NULL){
		/*STACK TIDAK KOSONG*/
		elemen *bantu;
		
		//inisialisasi
		//hitung dari elemen paling atas terlebih dahulu
		bantu = S.top;
		
		//lakukan pengulangan untuk menghitung jumlah dari stack
		//selama elemen bantu tidak NULL
		while(bantu != NULL){
			//Proses
			hasil = hasil + 1;
			
			//iterasi
			bantu = bantu -> next;
		}
	}
	return hasil;
}

//Prosedur untuk menambahkan elemen baru pada stack
void push(int nim, double nilai, stack *S){
	//inisialisasi elemen baru
	elemen *baru;
	//kemudian elemen baru diisi dengan data dari parameter
	baru = new elemen;
	baru->kontainer.nim = nim;
	baru->kontainer.nilai = nilai;
	
	if((*S).top == NULL){
		//jika list kosong
		//maka elemen selanjutnya tidak ada. NULL
		baru->next = NULL;
	}else{
		//jika list tidak kosong
		//elemen selanjutnya adalah elemen top yang lama
		baru->next = (*S).top;
	}
	//ganti elemen top dengan elemen baru
	(*S).top = baru;
	baru = NULL;
}

//prosedur untuk menghapus elemen stack paling atas
void pop(stack *S){
	if((*S).top != NULL){
		//Jika list bukan stack kosong
		elemen *hapus = (*S).top;
		//Jika jumlah elemen hanya 1 maka stack menjadi kosong
		if(countElement(*S) == 1){
			(*S).top == NULL;
		}else{
			//jika lebih dari satu, elemen top stack diganti dengan elemen dibawah top
			(*S).top = (*S).top->next;
		}
		
		hapus->next = NULL;
		delete hapus;
	}else{
		printf("stack kosong");
	}
}

//prosedur untuk menampilkan semua elemen stack
void printStack(stack S){
	if(S.top != NULL){
		printf("--------------isi stack----------------\n");
		// dimulai dari elemen top stack
		elemen *bantu = S.top;
		int i = 1;
		
		while(bantu != NULL){
			//tampilkan isi container dari masing-masing elemen stack
			printf("elemen ke-%d\n", i);
			printf("NIM: %d\n", bantu->kontainer.nim);
			printf("Nilai: %.2f\n", bantu->kontainer.nilai);
			
			//iterasi
			//kemudian lanjut pada elemen stack berikutnya
			bantu = bantu->next;
			i = i + 1;
		}
		printf("--------------------------------------\n");
	}else{
		//proses ketika stack kosong
		printf("stack kosong\n");
	}
}

int main(){
	//deklarasi membuat stack
	stack S;
	

	//stack dibuat dan dikosongkan
	createEmpty(&S);
	//lihat semua isi dari elemen stack
	printStack(S);
	
	printf("==========================================\n");
	//melakukan push data kedalam stack
	push(123, 90, &S);
	push(124, 80, &S);
	push(125, 70, &S);
	//menampilkan isi dari stack
	printStack(S);
	
	printf("==========================================\n");
	//melakukan pop data keluar dari stack
	pop(&S);
	pop(&S);
	//menampilkan isi dari stack
	printStack(S);
	
	printf("==========================================\n");
	
	return 0;
}
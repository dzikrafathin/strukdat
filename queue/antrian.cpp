#include<iostream>
#include<string.h>

using namespace std;

// Struct data yang akan digunakan untuk menyimpan data pada container stack

typedef struct{
	int nim;
	double nilai;
}nilaiMatkul;

//struct container dari queue
typedef struct elmt *alamatelmt;
typedef struct elmt{
	nilaiMatkul kontainer;
	alamatelmt next;
	int prioritas;
}elemen;

//stuct dari sebuah queue
typedef struct{
	elemen *first;
	elemen *last;
}queue;

//prosedur untuk membuat queue kosong
void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}
//prosedur untuk mengecek kekosongan queue
int isEmpty(queue Q){
	bool hasil = false;
	
	if(Q.first == NULL){
		hasil = true;
	}
	
	return hasil;
}

//prosedur untuk menghitung elemen queue
int countElement(queue Q){
	int hasil = 0;
	
	if(Q.first != NULL){
		/*QUEUE TIDAK KOSONG*/
		elemen *bantu;
		
		//inisialisasi
		bantu = Q.first;
		
		while(bantu != NULL){
			//Proses
			hasil = hasil + 1;
			
			//iterasi
			bantu = bantu->next;
		}
	}
	return hasil;
}
//prosedur untuk menambah elemen baru pada queue
void add(int nim, double nilai, queue *Q){
	//inisialisasi elemen baru
	elemen *baru;
	//mengisi container dengan data
	baru = new elemen;
	baru->kontainer.nim = nim;
	baru->kontainer.nilai = nilai;
	baru->next = NULL;
	
	if((*Q).first == NULL){
		(*Q).first = baru;
	}else{
		(*Q).last->next = baru;
	}
	
	(*Q).last = baru;
	baru = NULL;
}

//prosedur untuk menghapus elemen dari queue
void del(queue *Q){
	if((*Q).first != NULL){
		//Jika list bukan queue kosong
		elemen *hapus = (*Q).first;
		//jika jumlah elemen hanya satu maka queue menjadi kosong
		if(countElement(*Q) == 1){
			(*Q).first == NULL;
			(*Q).last == NULL;
		}else{
			//elemen first akan dihapus dan digantikan dengan elemen dibelakangnya
			(*Q).first = (*Q).first->next;
			hapus->next = NULL;
		}
		
		delete hapus;
	}
}
//prosedur untuk menampilkan semua elemen queue
void printQueue(queue Q){
	if(Q.first != NULL){
		printf("--------------isi queue----------------\n");
		//dimulai dari elemen pertama queue
		elemen *bantu = Q.first;
		int i = 1;
		
		//perulangan untuk menampilkan seluruh elemen pada queue
		while(bantu != NULL){
			//menampilkan elemen queue satu per satu
			printf("elemen ke-%d\n", i);
			printf("NIM: %d\n", bantu->kontainer.nim);
			printf("Nilai: %.2f\n", bantu->kontainer.nilai);
			printf("------------------------------------\n");
			//iterasi
			//pindah ke elemen queue berikutnya
			bantu = bantu->next;
			i = i + 1;
		}
	}else{
		//proses ketika queue kosong
		printf("queue kosong\n");
	}
}

int main(){
	//deklarasi queue
	queue Q;
	//buat queue dan mengosongkan isinya
	createEmpty(&Q);
	//menampilkan semua isi dari queue
	printQueue(Q);
	
	printf("==========================================\n");
	//menambahkan elemen baru pada queue
	add(123, 90, &Q);
	add(124, 80, &Q);
	add(125, 70, &Q);
	printQueue(Q);
	
	printf("==========================================\n");
	//proses menghapus elemen queue
	del(&Q);
	del(&Q);
	printQueue(Q);
	
	printf("==========================================\n");
	
	return 0;
}
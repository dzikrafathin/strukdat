#include <iostream>
#include <cstdio>

using namespace std;

// Membuat tipe data baru nilai matakuliah
typedef struct{
	int nim;
	int nilai;
}nilaiMatkul;

typedef struct elmt *alamatelmt;

//Tipe data elemen pada link list yang terdiri dari
//kontainer tempat menyimpan data, dan pointer next yang akan menunjuk
//alamat memori dari elemen selanjutnya
typedef struct elmt{
	nilaiMatkul kontainer;
	alamatelmt next;
}elemen;

//Struct untuk membuat list
typedef struct{
	elemen *first;
}list;

//Prosedur untuk membuat sebuah list
void createList(list *L){
    //Element list pertama diisi dengan NULL atau masih kosong
	(*L).first = NULL;
}

//Prosedur untuk menghitung jumlah elemen list
int countElement(list L){ 
    //Init hasil = 0
	int hasil = 0;
	
    //Jika elemen list yang pertama NULL (kosong) maka hasilnya
    //list tidak memiliki pengikut
	if(L.first != NULL){
		//variabel pointer untuk menyimpan 
        //alamat memori sementara
		elemen *bantu;
		//pointer diisi dengan alamat
        //memori elemen list pertama
		bantu = L.first;
		
        //lakukan perulangan untuk mencari ujung dari elemen 
        //link list, selama belum berisi null
		while (bantu != NULL){
            //jika next belum NULL maka hasil akan bertambah tambah
			hasil = hasil + 1;
			//kemudian pointer bantu diarahkan kembali ke elemen list selanjutnya (next)
			bantu = bantu->next;
		}
	}
    //output hasil jumlah elemen
	return hasil;
}

//fungsi untuk mencari ujung elemen link list
int emptyElement(list L){
	int hasil = 0;
	//jika elemen pertama saja sudah kosong maka 
    //asumsi bahwa list sudah tidak berisi
	if(L.first != NULL){
        //variabel ponter untuk menyimpan alamat memori sementara
		elemen *bantu;
		//pointer akan diarahkan pada element list yang pertama
		bantu = L.first;
		//lakukan perulangan sampai menemukan ujung dari elemen list
		while(bantu != NULL){
            //jika belum mencapai ujung maka hasil akan terus bertambah
			hasil = hasil + 1;
			//pointer bantu kembali diarahkan ke elemen list selanjutnya
			bantu = bantu->next;
		}
	}
    //hasil keluaran hasil
	return hasil;
}

//prosedur untuk menambahkan sebuah elemen pada 
//urutan link list pertama
void addFirst(int nim, int nilai, list *L){
    //membuat sebuah elemen baru terlebih dahulu
	elemen *baru;
	//kemudian elemen diisi dengan data yang diinginkan
	baru = new elemen;
	baru->kontainer.nim = nim;
	baru->kontainer.nilai = nilai;

	if((*L).first == NULL){ 
        //jika pada elemen list pertama ternyata masih kosong
        //maka elemen selanjutnya pada elemen baru diisikan dengan NULL atau
        //elemen kosong
		baru->next = NULL;
	}else{
		//jika ternyata sudah ada elemen yang menempati maka elemen lama akan
        //diletakan setelah elemen baru
		baru->next = (*L).first;
	}
    //element list yang pertama akan diisi dengan elemen baru
	(*L).first = baru;
    //menghancurkan elemen baru yang sudah tidak terpakai karena isinya sudah disalin kedalam list
	baru = NULL;
}

//prosedur untuk menambahkan elemen baru setelah suatu elemen
void addAfter(elemen *prev, int nim, int nilai){
    //hanya akan dieksekusi jika elemen sebelumnya yang ditunjuk
    //tidak kosong
	if(prev != NULL){
        //prosedur untuk membuat elemen baru
		elemen *baru;
		baru = new elemen;
		baru->kontainer.nim = nim;
		baru->kontainer.nilai = nilai;
		
		if(prev->next == NULL){
			//jika pada elemen prev setelahnya NULL maka pada elemen baru
            //nextnya akan diisikan NULL
			baru->next = NULL;
		}else{
            //jika ada elemen lain maka pada elemen baru 
            //next nya akan diisi dengan elemen tersebut 
			baru->next = prev->next;
		}
        //elemen prev selanjutnya akan digantikan dengan elemen baru
		prev->next = baru;
		baru = NULL;
	}
}

void addLast(int nim, int nilai, list *L){
//karena hanya mengubah nilai elemen tanpa melempar nilai, maka menggunakan void

	if((*L).first == NULL){
		//proses jika list masih kosong
		addFirst(nim, nilai, L);
	}else{
		//proses jika list telah berisi elemen
		//kita harus mencari elemen terakhir
		//inisialisasi elemen last dari awal first
		elemen *last = (*L).first;
		
		while(last->next != NULL){ //dicari sampai ketemu null
			//iterasi sampai ketemu null
			last = last->next;
		}
		//dilakukan proses penambahan add after dari last yang sudah ditemukan
		addAfter(last, nim, nilai);
	}
}

//prosedur untuk menghapus elemen pertama
void delFirst(list *L){
    //hanya akan dieksekusi jika elemen link list tidak kosong
	if((*L).first != NULL){
        //elemen yang akan dihapus berada pada list pertama
		elemen *hapus = (*L).first;
		
		if(countElement (*L) == 1){
            //jika elemen link list berjumlah 1 atau hanya ada first saja maka
            //link list akan kosong
			(*L).first = NULL;
		}else{
            //jika ada lebih dari 1 maka elemen pertama akan digantikan
            //dengan elemen setelah elemen first
			(*L).first = (*L).first->next;
		}
		hapus->next = NULL;
		delete hapus;
	}else{
		printf("list kosong\n");
	}
}
//prosedur untuk menghapus sebuah elemen setelah elemen tertentu
void delAfter(elemen *prev){
	if(prev != NULL){
        //elemen yang akan dihapus adlah elemen setelah dari elemen yang dimaksud
		elemen *hapus = prev->next;
		//jika ternyata sudah kosong maka tidak dieksekusi
		if(hapus != NULL){
			if(hapus->next == NULL){
                //jika elemen yang akan dihapus ternyata setelahnya kosong
                //maka elemen sebelumnya nextnya akan diisi NULL
				prev->next = NULL;
			}else{
                //jika terdapat elemen maka elemen prev nextnya akan diisi nextnya elemen yang dihapus
				prev->next = hapus->next;
			}
			
			hapus->next = NULL;
			delete hapus;
		}
	}
}

//prosedur untuk menghapus elemen terakhir
void delLast(list *L){

	if((*L).first != NULL){
        //jika hanya ada pada elemen pertama maka 
        //eksekusi saja prosedur delFirst
		if(countElement(*L) == 1){
			
			delFirst(L);
		}else{
            //prosedur untuk mencari elemen terakhir pada list
			elemen *last = (*L).first;
			elemen *before_last;
			
			while(last->next != NULL){
				//mencari elemen sebelum elemen terakhir
				before_last = last;
				last = last->next;
			}
			//jika sudah ketemu maka hapus elemen dengan perintah delAfter
			delAfter(before_last);
		}
	}else{
		
		printf("list kosong\n");
	}
}
//prosedur untuk menghapus semua elemen
void delAll(list *L){
	int i;
	if(countElement(*L) != 0){
		for(i=countElement(*L);i>=1;i--){
			//setiap elemen akan dihapus
			delLast(L);
		}
	}
}
//prosedur untuk menampilkan semua elemen
void printElement(list L){
	if(L.first != NULL){
		//pertama dimulai dari element list pertama
		elemen *bantu = L.first;
		int i = 1;
        //lakukan perulangan selama elemen belum berada diujung
		while(bantu != NULL){
			
			printf("elemen ke : %d\n", i);
			printf("nim: %d\n", bantu->kontainer.nim);
			printf("nilai: %d\n", bantu->kontainer.nilai);
			printf("--------------------------\n");
			//setelah selesai lanjut pada elemen selanjutnya
			bantu = bantu->next;
			i = i + 1;
		}
	}else{
		
		printf("list kosong\n");
	}
}

int main(){
	list L;
	
	createList(&L);
	printElement(L);
	printf("================================\n");
	addFirst(11, 80, &L);
	addFirst(12, 85, &L);
	addAfter(L.first, 13, 90);
	addAfter(L.first, 14, 40);
	addLast(15, 50, &L);
	addLast(16, 65, &L);
	printElement(L);
	printf("\n");
	
	printf("================================\n");
	delLast(&L);
	delAfter(L.first);
	delFirst(&L);
	printElement(L);
	printf("\n");
	
	return 0;
}

#include <cstdio>

typedef struct 
{
   int nim;
   double nilai;
} ipk ;

typedef struct el *alel;
typedef struct el {
    ipk kontener;
    alel selanjutnya;
    int prioritas;
} elemen;

typedef struct {
    elemen *pertama;
    elemen *terakhir;
} antrian;

antrian A;

void buatKosong(antrian *A) {
    (*A).pertama = NULL;
    (*A).terakhir = NULL;
}

bool kosongGak(antrian *A) {
    if ((*A).pertama == NULL) {
        return true;
    } else {
        return false;
    }
}

int jumlahData(antrian *A) {
    int hasil = 0;
    if ((*A).pertama != NULL) {
        elemen *bantu;
        bantu = (*A).pertama;
        while (bantu != NULL) {
            hasil++;
            bantu = bantu->selanjutnya;
        }
    }
    return hasil;
}

void tambah(int nim, double nilai, antrian *A) {
    elemen *baru;
    
    baru = new elemen;
    baru->kontener.nim = nim;
    baru->kontener.nilai = nilai;
    baru->selanjutnya = NULL;

    if ((*A).pertama == NULL) {
        (*A).pertama = baru;
    } else {
        (*A).terakhir->selanjutnya = baru;
    }
    (*A).terakhir = baru;
    baru = NULL;
}

void hapus(antrian *A) {
    if ((*A).pertama != NULL) {
        elemen *hapus = (*A).pertama;
        if (jumlahData(A) == 1) {
            (*A).pertama = NULL;
            (*A).terakhir = NULL;
        } else {
            (*A).pertama = (*A).pertama->selanjutnya;
            hapus->selanjutnya = NULL;
        }
        delete hapus;
    }
}

void tambahData(antrian *A) {
    int nim;
    double nilai;
    printf("==== Nambahin Data ====\n");
    printf("NIM = ");
    scanf("%d",&nim);
    printf("Nilai = ");
    scanf("%lf",&nilai);
    tambah(nim,nilai,A);
}

elemen * terbesar(antrian *A) {
    if ((*A).pertama != NULL) {
        elemen *bantu = (*A).pertama;
        elemen *besar = bantu;
        while (bantu != NULL) {
            if (bantu->kontener.nilai > besar->kontener.nilai) {
                besar = bantu;
            }
            bantu = bantu->selanjutnya;
        }
        return besar;
    }
}

elemen * terkecil(antrian *A) {
    if ((*A).pertama != NULL) {
        elemen *bantu = (*A).pertama;
        elemen *kecil = bantu;
        while (bantu != NULL) {
            if (bantu->kontener.nilai < kecil->kontener.nilai) {
                kecil = bantu;
            }
            bantu = bantu->selanjutnya;
        }
        return kecil;
    }
}

void tampilData(antrian *A) {
    if ((*A).pertama != NULL) {
        printf("===== ISI DATA QUEUE ======\n");
        elemen *bantu = (*A).pertama;
        int i = 1;

        while (bantu != NULL) {
            printf("------------------\n");
            printf("Data ke-%d\n",i);
            printf("NIM : %d\n", bantu->kontener.nim);
            printf("Nilai : %lf\n",bantu->kontener.nilai);
            bantu = bantu->selanjutnya;
            i++;
        }

        printf("===========================\n");
    } else {
        printf("EMpty queue");
    }
}

void mainMenu() {
    elemen *besar;
    elemen *kecil;
    int sel = 1;
    while (sel != 6) {
        printf("====== MAIN MENU ======\n");
        printf("1. Lihat\n2. Tambah\n3. Hapus\n4. Terbesar\n5. Terkecil\n6. Keluar\n");
        printf("Masukan pilihan = ");
        scanf("%d",&sel);
        switch (sel)
        {
            case 1:
                tampilData(&A);
                break;
            case 2:
                tambahData(&A);
                break;
            case 3:
                hapus(&A);
                break;
            case 4:
                besar = terbesar(&A);
                printf("==== TERBESAR ====\n");
                printf("NIM  : %d\n",besar->kontener.nim);
                printf("Nilai : %lf\n",besar->kontener.nilai);
                break;
            case 5:
                kecil = terkecil(&A);
                printf("==== TERKECIL ====\n");
                printf("NIM  : %d\n",kecil->kontener.nim);
                printf("Nilai : %lf\n",kecil->kontener.nilai);
                break;
        
            default:
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
    buatKosong(&A);
    tambah(100,68,&A);
    tambah(101,78,&A);
    tambah(102,98,&A);
    tambah(103,77,&A);
    tambah(104,54,&A);
    tambah(105,55,&A);
    tambah(106,93,&A);
    tambah(107,76,&A);
    //tampilData(&A);
    mainMenu();
    return 0;
}

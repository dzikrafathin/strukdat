#include <cstdio>

typedef struct {
    int nim;
    double nilai;
} Ipk;

typedef struct el *eladdr;
typedef struct el {
    Ipk kontener;
    eladdr berikutnya;
} elemen;

typedef struct {
    elemen* atas;
} stack;

stack S;

void buatBaru(stack *S) {
    (*S).atas = NULL;
}

bool kosong(stack S) {
    if (S.atas == NULL) {
        return true;
    } else {
        return false;
    }
}

int hitungJumlah(stack S) {
    int hasil = 0;
    if (S.atas != NULL) {
        el *bantu;
        bantu = S.atas;
        while(bantu != NULL) {
            hasil++;
            bantu = bantu->berikutnya;
        }
    }
    return hasil;
}

void dorong(int nim, double nilai, stack *S) {
    elemen *baru;
    baru = new elemen;
    baru->kontener.nim = nim;
    baru->kontener.nilai = nilai;

    if ((*S).atas == NULL) {
        baru->berikutnya = NULL;
    } else {
        baru->berikutnya = (*S).atas;
    }
    (*S).atas = baru;
    baru = NULL;
}

void lepas(stack *S) {
    if ((*S).atas != NULL) {
        elemen *hapus = (*S).atas;
        if (hitungJumlah(*S) == 1) {
            (*S).atas == NULL;
        } else {
            (*S).atas = (*S).atas->berikutnya;
        }
        hapus->berikutnya = NULL;
        delete hapus;
    } else {
        printf("Empty Stack");
    }
}

void lihatData(stack *S) {
    if ((*S).atas != NULL) {
        printf("======= ISI STACK ========");
        elemen *bantu = (*S).atas;
        int i = 1;
        while (bantu != NULL) {
            printf("---------------------\n");
            printf("Data ke-%d\n",i);
            printf("NIM : %d\n",bantu->kontener.nim);
            printf("Nilai : %lf\n",bantu->kontener.nilai);
            bantu = bantu->berikutnya;
            i++;
        }
        printf("=========================\n");
    } else {
        printf("Empty stack");
    }
}

elemen * terBesar(stack *S) {
    if ((*S).atas != NULL) {
        //int maks, nim;
        elemen *bantu = (*S).atas;
        elemen *maks = bantu;
        while (bantu != NULL) {
            if (bantu->kontener.nilai > maks->kontener.nilai) {
                maks = bantu;
            }
            bantu = bantu->berikutnya;
        }
        return maks;
    } 
}

elemen * terKecil(stack *S) {
    if ((*S).atas != NULL) {
        elemen *bantu = (*S).atas;
        elemen *minim = bantu;
        while (bantu != NULL) {
            if (bantu->kontener.nilai < minim->kontener.nilai) {
                minim = bantu;
            }
            bantu = bantu->berikutnya;
        }
        return minim;
    }
}

void masukinData(stack *S) {
    int nim,nilai;
    printf("==== INPUT DATA ====\n");
    printf("NIM = ");
    scanf("%d",&nim);
    printf("Nilai = ");
    scanf("%d",&nilai);
    dorong(nim,nilai,S);
}


void mainMenu() {
    elemen *tinggi;
    elemen *rendah;
    int sel = 1;
    while (sel != 6) {
        printf("======= MAIN MENU =======\n");
        printf("1. Lihat\n2. Input\n3. Hapus\n4. Tertinggi\n5. Terendah\n6.Keluar\n");
        printf("Masukan pilihan : ");
        scanf("%d",&sel);
        switch (sel)
        {
            case 1:
                lihatData(&S);
                break;
            case 2:
                masukinData(&S);
                break;
            case 3:
                lepas(&S);
                break;
            case 4:
                tinggi = terBesar(&S);
                printf("==== TERTINGGI ====\n");
                printf("NIM : %d\n",tinggi->kontener.nim);
                printf("Nilai : %lf\n",tinggi->kontener.nilai);
                break;
            case 5:
                rendah = terKecil(&S);
                printf("==== TERrENDAH ====\n");
                printf("NIM : %d\n",rendah->kontener.nim);
                printf("Nilai : %lf\n",rendah->kontener.nilai);
                break;
        }
    }
}

int main() {
    
    buatBaru(&S);
    dorong(100,80,&S);
    dorong(101,78,&S);
    dorong(102,87,&S);
    dorong(103,55,&S);
    dorong(104,67,&S);
    dorong(105,91,&S);
    mainMenu();
    return 0;
}
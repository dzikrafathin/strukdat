#include <cstdio>

int num = 2;
int totalPos = 1;

typedef struct {
    int id_duit;
    int jumlah_duit;
} duit;

typedef struct el *el_addr;

typedef struct el {
    duit kontener;
    el_addr selanjutnya;
} elemen;

typedef struct {
    el *pertama;
} daftar;

void buatDaftar(daftar *D) {
    (*D).pertama = NULL;
}

daftar Daftar;

void show_menu();

void isidiPertama(int id_duit, int jumlah_duit, daftar *D) {
    elemen *baru;
    baru = new elemen;
    baru->kontener.id_duit = id_duit;
    baru->kontener.jumlah_duit = jumlah_duit;

    if((*D).pertama == NULL) {
        baru->selanjutnya = NULL;
    } else {
        baru->selanjutnya = (*D).pertama;
    }
    (*D).pertama = baru;
    baru = NULL;
}

void isiSetelah(elemen *sebelumnya, int jumlah_duit, int id_duit) {
    if (sebelumnya != NULL) {
        elemen *baru;
        baru = new elemen;
        baru->kontener.id_duit = id_duit;
        baru->kontener.jumlah_duit = jumlah_duit;
        if (sebelumnya->selanjutnya == NULL) {
            baru->selanjutnya = NULL;
        } else {
            baru->selanjutnya = sebelumnya->selanjutnya;
        }
        sebelumnya->selanjutnya = baru;
        baru = NULL;
    }
}


void isidiUjung(int jumlah_duit, int id_duit, daftar *D) {
    if ((*D).pertama == NULL) {
        isidiPertama(id_duit,jumlah_duit,D);
    } else {
        elemen *ujung = (*D).pertama;
        while(ujung->selanjutnya != NULL) {
            ujung = ujung->selanjutnya;
        }
        isiSetelah(ujung,jumlah_duit,id_duit);
    }
}

void lihatSemuaisi(daftar *D) {
    int num = 1;
    printf("Isi DuitMU\n");
    elemen *sekarang = (*D).pertama;
    while (sekarang != NULL) {
        printf("------------------\n");
        printf("Saldo ke %d\n",num);
        printf("id = %d\n",sekarang->kontener.id_duit);
        printf("jumlah = Rp.%d\n",sekarang->kontener.jumlah_duit);
        sekarang = sekarang->selanjutnya;
        num++;
    }
    show_menu();
}

void nambahDuit(daftar *D) {
    int duit;
    int tambah = 1;
    while (tambah == 1) {
        printf("---- Nambah duit ----\n");
        printf("Masukin duitnya = Rp.");
        scanf("%d",&duit);
        isidiUjung(duit,num,D);
        printf("Lagi gak ? (0/1)");
        scanf("%d",&tambah);
        num++;
    }
    duit = 0;
    elemen *sekarang = (*D).pertama;
    while (sekarang->kontener.id_duit != totalPos) {
        sekarang = sekarang->selanjutnya;
    }
    while (sekarang->selanjutnya != NULL) {
        duit += sekarang->kontener.jumlah_duit;
        sekarang = sekarang->selanjutnya;
    }
    isidiUjung(duit,num,D);
    totalPos = num;
    num++;
    show_menu();
}

void ambilDuit(daftar *D) {
    elemen *sekarang = (*D).pertama;
    while (sekarang->kontener.id_duit != totalPos) {
        sekarang = sekarang->selanjutnya;
    }
    int duit;
    printf("----- Ngambil duit ------\n");
    printf("Ambil brapa = Rp.");
    scanf("%d",&duit);
    sekarang->kontener.jumlah_duit -= duit;
    show_menu();
}

void show_menu() {
    int sel;
    printf("1. Nambah duit\n2. Ambil Duit\n3. Liat daftar duit\n");
    printf("Pilihan : ");
    scanf("%d",&sel);
    if (sel == 1) {
        nambahDuit(&Daftar);
    } else if (sel == 2) {
        ambilDuit(&Daftar);
    } else if (sel == 3) {
        lihatSemuaisi(&Daftar);
    }
}



int main(int argc, char const *argv[])
{
    buatDaftar(&Daftar);
    isidiPertama(1,100,&Daftar);
    lihatSemuaisi(&Daftar);
    show_menu();   
    return 0;
}


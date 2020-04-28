#include <iostream>
#include <cstdio>
using namespace std;

string keluar = "";

typedef struct elmt *alamatelmt;

typedef struct elmt{
    int num;
    alamatelmt next;
} MABA;

typedef struct{
    MABA *pertama;
} daftar;

void buatDaftar(daftar *D) {
    (*D).pertama = NULL;
}

void addPertama(int num, daftar *D) {
    MABA *baru;
    baru = new MABA;
    baru->num = num;
    if ((*D).pertama == NULL) {
        baru->next = NULL;
    } else {
        baru->next = (*D).pertama;
    }
    (*D).pertama = baru;
    baru = NULL;
}

void addAfter(MABA *sebelumnya, int num) {
    MABA *baru;
    baru = new MABA;
    baru->num = num;
    if (sebelumnya->next == NULL) {
        baru->next = NULL;
    } else {
        baru->next = sebelumnya->next;
    }
    sebelumnya->next = baru;
    baru = NULL;
}

void addMABA(int num, daftar *D) {
    
    if ((*D).pertama == NULL) {
        addPertama(num,D);
    } else {
        MABA *terakhir = (*D).pertama;
        while (terakhir->next != NULL) {
            terakhir = terakhir->next;
        }
        addAfter(terakhir,num);
    }
}

int jumlahMABA(daftar D) {
    int res;
    if (D.pertama != NULL) {
        MABA *bantu;
        bantu = D.pertama;
        while (bantu != NULL) {
            res++;
            bantu = bantu->next;
        }
    }
    return res;
}

void delFirst(daftar *D) {
    if (jumlahMABA(*D) != 1) {
        MABA *keluar = (*D).pertama;
        (*D).pertama = (*D).pertama->next;
        keluar->next = NULL;
        delete keluar;
    }
}

void delAfter(MABA *sebelumnya, daftar *D) {
    MABA *keluar = sebelumnya->next;
    if (keluar != NULL) {
        if(keluar->next == NULL) {
            sebelumnya->next = NULL;
        } else {
            sebelumnya->next = keluar->next;
        }
        keluar->next = NULL;
        delete keluar;
    } else {
       delFirst(D);
    }
}

MABA * cariMABA(int pos, int start_point, daftar *D) {
    MABA *dicari = (*D).pertama;
    pos = pos + start_point;
    for (int i=1;i<=pos;i++) {
        dicari = dicari->next;
        if (dicari == NULL) {
            dicari = (*D).pertama;
        }
    }
    return dicari;
}

void putaranKetua(int N, int X, daftar *D, int * arr) {
    buatDaftar(D);
    for (int i=1;i<=N;i++) {
        addMABA(i,D);
    }
    MABA * pemilih; 
    MABA * terpilih;
    int num;
    pemilih = (*D).pertama;
    terpilih = (*D).pertama;
    for (int i=1;i<N;i++) {
        for (int j=1;j<X;j++) {
            if (j != 1) {      
                terpilih = terpilih->next;
            } else {
                terpilih = pemilih->next;
            }
            if (terpilih == NULL) {
                terpilih = (*D).pertama;
            }
            
        }
        if (terpilih->next == NULL) {
            num = (*D).pertama->num;
        } else {
            num = terpilih->next->num;
        }
        *(arr+i) = num;
        delAfter(terpilih,D);
        pemilih = terpilih->next;
        if (pemilih == NULL) {
            pemilih = (*D).pertama;
        }
        //cout << pemilih->num << endl;
    }
    /// -----------------------------------------
}

int main() {
    daftar D;
    int N;
    int X;
    int T;
    printf("Jumlah testcase : ");
    scanf("%d",&T);
    for (int i=0;i<T;i++) {
        printf("Masukan jumlah N MHS : ");
        scanf("%d",&N);
        printf("MHS yang ditunjuk : ");
        scanf("%d",&X);
        int arr[N];
        putaranKetua(N,X,&D,&arr[0]);
        printf("Yang keluar : ");
        for (int i=1;i<N;i++) {
            printf("%d ",arr[i]);
        }
        printf("@\n");
        printf("Ketua : %d\n",D.pertama->num);
    }    
}

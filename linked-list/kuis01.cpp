#include <iostream>
#include <cstdio>

using namespace std;

typedef struct  {
    int id;
    int uang;
} ListSaldo;

typedef struct elmt *alamatelmt;

typedef struct elmt {
    ListSaldo kontainer;
    alamatelmt next;
} elemen;

typedef struct {
    elemen *first;
} list;

void buatList(list *L) {
    (*L).first = NULL;
}

void addFirst(int id, int uang, list *L) {
    elemen *baru;

    baru = new elemen;
    baru->kontainer.id = id;
    baru->kontainer.uang = uang;

    baru->next = NULL;
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *prev, int id, int uang) {
    if (prev != NULL) {
        elemen *baru;
        baru = new elemen;
        baru->kontainer.id = id;
        baru->kontainer.uang = uang;

        baru->next = NULL;
        prev->next = baru;
        baru = NULL;
    }
}

void addLast(int id, int uang, list *L) {
    elemen *last = (*L).first;
    while(last->next != NULL) {
        last = last->next;
    }
    addAfter(last,id,uang);
}

void printElement(list L) {
    elemen *tmp = L.first;
    int i = 1;
    while (tmp != NULL) {
        printf("------------------------\n");
        printf("elemen ke : %d\n",i);
        printf("id : %d\n",tmp->kontainer.id);
        printf("uang : Rp.%d\n",tmp->kontainer.uang);
        tmp = tmp->next;
        i++;
    }
}

void totalin(list *L) {
    elemen *tmp = (*L).first;
    int total = 0;
    int id = 0;
    while (tmp != NULL) {
        id += tmp->kontainer.id;
        total += tmp->kontainer.uang;
        tmp = tmp->next;
    }
    addLast(id,total,L);
}

void printLAST(list *L) {
    elemen *tmp = (*L).first;
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            break;
        } else {
            tmp = tmp->next;
        }    
    }
    printf("------------------------\n");
    printf("TOTAL DUIT ANDA\n");
    printf("id : %d\n",tmp->kontainer.id);
    printf("uang : Rp.%d\n",tmp->kontainer.uang);
}

void ambilDUIT(list *L) {
    elemen *tmp = (*L).first;
    int inputan;
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            break;
        } else {
            tmp = tmp->next;
        }
    }
    while (true) {
        printf("Mau diambil gak duitnya ? (0/1)");
        scanf("%d",&inputan);
        if (inputan == 1) {
            printf("Mau diambil berapa ? :");
            scanf("%d",&inputan);
            if ((tmp->kontainer.uang - inputan) > 0) {
                tmp->kontainer.uang -= inputan;
                printf("------------------------\n");
                printf("Berhasil berhasil hore\n");
                printf("SISA DUIT ANDA\n");
                printf("id : %d\n",tmp->kontainer.id);
                printf("uang : Rp.%d\n",tmp->kontainer.uang);
            } else {
                printf("Transaksi gagal, stok duit abis\n");
                break;
            }
        } else {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    list L;
    buatList(&L);
    printf("====================================\n");
    printf("BANK TRONJAL TRONJOL----\n");
    printf("Status : Masih anget rekeningnya\n");
    printf("====================================\n");
    addFirst(1,100000,&L);
    printElement(L);
    int id = 2;
    while (true) {
        int inputan;
        printf("Mau nabung ngak? (0/1)");
        scanf("%d",&inputan);
        if (inputan == 1) {
            printf("Masukin duit nya : ");
            scanf("%d",&inputan);
            addLast(id,inputan,&L);
        } else {
            break;
        }
        id++;
    }
    printElement(L);
    totalin(&L);
    printLAST(&L);
    ambilDUIT(&L);

    return 0;
}

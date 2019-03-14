#include <cstdio>


void ambil_duit(int *saldo, int n) {
    int trans;
    for (int i=0;i<n;i++) {
        printf("Banyaknya yang ingin diambil Rp. ");
        scanf("%d",&trans);
        *saldo -= trans;
    }
}


int main() {
    int trans, num, saldo = 500000000;

    printf("Saldo Rp. %d \n", saldo);
    printf("Masukan jumlah pengambilan : ");
    scanf("%d",&num);
    ambil_duit(&saldo,num);
    printf("Sisa saldo anda adalah : %d", saldo);
}
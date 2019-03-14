#include <cstdio>

int main() {
    int jml_anak10, jml_anak15, bagi, totalUang, bagiA15, bagiA10, sisaA10, sisaA15, totalA10, totalA15, totalAll, sisaEND;
    bool A15kelebihan, A15cukup, A15kurang, A10kelebihan, A10cukup, A10kurang;
    totalUang = 1000000;

    printf("Input jumlah anak 15 tahun keatas dan jumlah anak 10 tahun sampai 15 tahun : ");
    scanf("%d %d", &jml_anak15, &jml_anak10);

    bagi = totalUang / (jml_anak10+jml_anak15);

    bagiA15 = bagi;
    bagiA10 = bagi;

    if (bagiA15 > 200000) {
        sisaA15 = bagiA15 - 200000;

        bagiA15 = 200000;
        A15kelebihan = true;

    } else if (bagiA15 == 200000) {
        A15cukup = true;
    } else {
        A15kurang = true;
    }

    if (bagiA10 > 100000) {
        sisaA10 = bagiA10 - 100000;
        //totalsisaA10 = sisaA10 * jml_anak10;
        bagiA10 = 100000;
        A10kelebihan = true;
    
    } else if (bagiA10 == 100000) {
        A10cukup = true;
    } else {
        A10kurang = true;
    }

    

    if (A10kelebihan && A15kurang) {
        
        bagiA15 += sisaA10;
        
        //printf("%d\n",bagiA15);
        
    } else if (A15kelebihan && A10kurang) {
        bagiA10 += sisaA15;
        
    }
    //printf("%d\n",bagiA15);
    //printf("%d\n",bagiA10);
    totalA10 = bagiA10 * jml_anak10;
    totalA15 = bagiA15 * jml_anak15;
    totalAll = totalA10 + totalA15;
    sisaEND = totalUang - totalAll;
    printf("Sisa uang sebanyak Rp. %d", sisaEND);
}
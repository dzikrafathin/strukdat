#include <cstdio>

struct waktu {
    int jam;
    int menit;
    int detik;
};

void input_waktu(waktu * t) {
    printf("Masukan jam, menit, detik : ");
    scanf("%d %d %d",&t->jam,&t->menit,&t->detik);
}

int ke_detik(waktu t) {
    return (t.detik + (t.menit * 60) + (t.jam * 3600));
}

void validasi(waktu * t, int n) {
    if (t->jam > 24) {
        printf("Data ke %d, Jam tidak valid. Hasil konversi ke detik : %d\n", n, ke_detik(*t));
    } else if (t->menit > 60) {
        printf("Data ke %d, Menit tidak valid. Hasil konversi ke detik : %d\n", n, ke_detik(*t));
    } else if (t->detik > 60) {
        printf("Data ke %d, Detik tidak valid. Hasil konversi ke detik : %d\n", n, ke_detik(*t));
    } else {
        printf("Data ke %d, Semua valid. Hasil konversi ke detik : %d\n", n, ke_detik(*t));
    }
}

int main() {
    waktu t[3];
    for (int i=0;i<3;i++) {
        input_waktu(&t[i]);
    }
    for (int i=0;i<3;i++) {
        validasi(&t[i],(i+1));
    }
}
#include <cstdio>
#include <cmath>

int euclidian(int xi, int yi, int xj, int yj) {
    return sqrt(abs(pow(xi-xj,2)+pow(yi-yj,2)));
}

int main() {
    int xi, yi, xj, yj, euc;
    printf("Nilai X awal : ");
    scanf("%d",&xi);
    printf("Nilai Y awal : ");
    scanf("%d",&yi);
    printf("Nilai X Akhir : ");
    scanf("%d",&xj);
    printf("Nilai Y Akhir : ");
    scanf("%d",&yj);
    printf("Jarak euclidian : %d", euclidian(xi,yi,xj,yj));
}
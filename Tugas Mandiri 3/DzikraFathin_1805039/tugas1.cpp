#include <cstdio>

struct koordinat {
    int x;
    int y;
};

void input(koordinat * p1) {
    printf("Koordinat X : ");
    scanf("%d",&p1->x);
    printf("Koordinat Y : ");
    scanf("%d",&p1->y);
}

void selection(koordinat * p1) {
    int s;
    printf("Pilihan [0,1,2,3] : ");
    scanf("%d",&s);
    if (s == 0) {
        p1->x = p1->x - 1;
    } else if (s == 1) {
        p1->y = p1->y + 1;
    } else if (s == 2) {
        p1->x = p1->x + 1;
    } else {
        p1->y = p1->y - 1;
    }
}

int main() {
    koordinat p1;
    input(&p1);
    printf("Awal X : %d, Y : %d\n",p1.x,p1.y);
    selection(&p1);
    printf("Akhir X : %d, Y : %d\n",p1.x,p1.y);
}
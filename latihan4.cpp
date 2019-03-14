#include <cstdio>

typedef struct Nilai
{
    char nim[7];
    int nilai;
};

int main() {
    int n, max, min;
    double avg;
    printf("Number of kelas : ");
    scanf("%d",&n);
    Nilai kelasA[n];
    for (int i=0;i<n;i++) {
        printf("Input data %d\n",i+1);
        printf("NIM : ");
        scanf("%s",kelasA[i].nim);
        printf("Nilai : ");
        scanf("%d",&kelasA[i].nilai);
    }
    for (int i=0;i<n;i++) {
        printf("Data ke %d\n",i+1);
        printf("NIM : %s\n",kelasA[i].nim);
        printf("Nilai : %d\n",kelasA[i].nilai);
        avg += (double)kelasA[i].nilai;
    }
    max = kelasA[0].nilai;
    min = kelasA[0].nilai;
    for (int i=0;i<n;i++) {
        if (kelasA[i].nilai > max) {
            max = kelasA[i].nilai;
        }
        if (kelasA[i].nilai < min) {
            min = kelasA[i].nilai;
        }
    }
    avg /= n;
    printf("STATISTIC\n");
    printf("Min : %d\n",min);
    printf("Max : %d\n",max);
    printf("Rata rata : %lf\n",avg);
}
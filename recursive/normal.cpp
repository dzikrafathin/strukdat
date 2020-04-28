#include <cstdio>
#include <ctime>
#include <cmath>

long int fibonnaci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonnaci(n-1) + fibonnaci(n-2);
    }
}

double fibonnaci_solution(int n) {
    double result = 0.447213595*pow(1.618033989,n)+(-0.447213595)*pow(-0.618033989,n);
    return result;
}

int main(int argc, char const *argv[])
{
    int selection;
    clock_t awal, akhir, sec;
    printf("1. Rekursi biasa 2. Solusi rekursi = ");
    scanf("%d",&selection);
    int n;
    printf("Input number n : ");
    scanf("%d",&n);
    awal = clock();
    if (selection == 1) {
        printf("Result = %ld\n",fibonnaci(n));
    } else if (selection == 2) {
        printf("Result = %lf\n",fibonnaci_solution(n));
    }
    akhir = clock();
    sec = akhir - awal;
    printf("Exec time = %lf sec\n",((float)sec)/CLOCKS_PER_SEC);
    return 0;
}

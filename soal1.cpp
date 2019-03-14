#include <cstdio>
#include <cmath>
float average(int n) {
    float temp = 0;
    float input;
    for (int i=0;i<n;i++) {
        printf("Masukan nilai ke %d : ",(i+1));
        scanf("%f",&input);
        temp += input;
    }
    temp /= (float)n;
    return temp;
}

int main() {
    int n;
    float res;
    printf("Masukan jumlah angka : ");
    scanf("%d",&n);
    res = average(n);
    printf("Hasilnya : %f \n",pow(res/10,3));
}
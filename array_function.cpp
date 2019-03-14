#include <cstdio>
using namespace std;

void input_array(int A[], int n) {
    for (int i=0;i<n;i++) {
        printf("Input value of %d : ", i+1);
        scanf("%d",&A[i]);
    }
}

void div_array(int A[], int n) {
    for (int i=0;i<n;i++) {
        A[i] /= 2;
    }
}

void show_array(int A[], int n) {
    for (int i=0;i<n;i++) {
        printf("Value of %d : %d \n",i+1,A[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;
    int A[n];
    input_array(A,n);
    div_array(A,n);
    show_array(A,n);
    return 0;
}

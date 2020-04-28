#include <iostream>
#include <cstdio>

using namespace std;

typedef struct{
    int nomor;
    string nama;
} isi;

typedef struct el *addr_el;

typedef struct el{
    isi kontainer;
    addr_el next;
} elemen;

typedef struct {
    elemen *pertama;
} daftar;

void buatList(daftar *D) {
    (*D).pertama = NULL;
}

int main() {
    
}
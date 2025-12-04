#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct Berita {
    string judulBerita;
    string isiBerita;
    string tanggal;
};

typedef struct Berita infotypeBerita;
typedef struct elmBerita *adrBerita;

struct elmBerita {
    infotypeBerita info;
    adrBerita next;
};

struct ListBerita {
    adrBerita first;
};

void createListBerita(ListBerita &B);
adrBerita allocateBerita(infotypeBerita x);
void insertFirstBerita(ListBerita &B, adrBerita b);
void insertLastBerita(ListBerita &B, adrBerita b);
void deleteFirstBerita(ListBerita &B, adrBerita &b);
void deleteLastBerita(ListBerita &B, adrBerita &b);
void deleteAfterBerita(ListBerita &B, adrBerita prec, adrBerita &b);
adrBerita findBerita(ListBerita B, string judBer);
void showAllBerita(ListBerita B);



#endif // BERITA_H_INCLUDED

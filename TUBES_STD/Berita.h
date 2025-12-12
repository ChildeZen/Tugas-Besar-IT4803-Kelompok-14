#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct Berita {
    string judulBerita;
    string temaBerita;
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

void createListBerita(ListBerita &B); //sudah//
adrBerita allocateBerita(infotypeBerita x); //sudah//
void insertFirstBerita(ListBerita &B, adrBerita b); //sudah//
void insertLastBerita(ListBerita &B, adrBerita b); //sudah//
void insertafterBerita(ListBerita &B, adrBerita prec, adrBerita &b); //sudah//
void deleteFirstBerita(ListBerita &B, adrBerita &b); //sudah//
void deleteLastBerita(ListBerita &B, adrBerita &b); //sudah//
void deleteAfterBerita(ListBerita &B, adrBerita prec, adrBerita &b); //sudah//
adrBerita findBerita(ListBerita B, string judulBerita); //sudah//
void showAllBerita(ListBerita B); //sudah//

//belum Show data child dari parent tertentu//



#endif // BERITA_H_INCLUDED

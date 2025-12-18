#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
#include "Berita.h"


//parent.h atau jurnalis.h

struct Jurnalis {
    string idJurnalis;
    string nama;
    string status;
};

typedef struct Jurnalis infotypeJurnalis;
typedef struct elmJurnalis *adrJurnalis;
typedef struct elmRelasi *adrRelasi;

//relation.h//
struct elmRelasi {
    adrBerita info;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

//jurnalis.h//
struct elmJurnalis {
    infotypeJurnalis info;
    adrJurnalis next;
    adrJurnalis prev;
    ListRelasi Berita;
};

struct ListJurnalis {
    adrJurnalis first;
    adrJurnalis last;
};

//relasi//
void createList(ListRelasi &L);
void insertFirst(ListRelasi &L, adrRelasi P);
void insertLast(ListRelasi &L, adrRelasi P);
void insertAfter(adrRelasi Prec, adrRelasi P);
void deleteFirst(ListRelasi &L, adrRelasi &P);
void deleteLast(ListRelasi &L, adrRelasi &P);
void deleteAfter(adrRelasi &Prec, adrRelasi &P);

adrRelasi alokasi(adrBerita C);
void dealokasi(adrRelasi &R);
void connectJurnalisBerita(ListJurnalis &J, ListBerita B, string namaJurnalis, string judulBerita);

void showJurnalisWithBerita(ListJurnalis J);
void showJurnalisByBerita(ListJurnalis J, adrBerita target);
void showJurnalisByJudulBerita(ListJurnalis J, ListBerita B, string judul);
int countJurnalisByBerita(ListJurnalis J, adrBerita target);
void editRelasiBerita(adrJurnalis p, adrBerita lama, adrBerita baru);

adrRelasi findElmRelasi(adrJurnalis J, adrBerita B);//mencari elemen relasi//
void showBeritaByJurnalis(ListJurnalis J, string namaJurnalis); //Show data child dari parent tertentu//
void printAllBeritaWithJurnalis(ListBerita LB, ListJurnalis LJ); //Show data child beserta data parent yang masing-masing child miliki//
void countRelasiJurnalis(ListJurnalis J); //Count relaation dari setiap element parent//
int countBeritaTanpaJurnalis(ListBerita B, ListJurnalis J); //count berita tanpa relasi dengan jurnalis//
void disconnectJurnalisBerita(ListJurnalis &J, ListBerita B, string namaJurnalis, string judulBerita);

//untuk study case sendiri//
void deleteJurnalisLengkap(ListJurnalis &J, string nama);
void deleteBeritaAman(ListBerita &B, ListJurnalis &J, string judul);






//jurnalis//
void createListJurnalis(ListJurnalis &J);
adrJurnalis allocateJurnalis(infotypeJurnalis x);
void insertFirstJurnalis(ListJurnalis &J, adrJurnalis p);
void insertLastJurnalis(ListJurnalis &J, adrJurnalis p);
void insertAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis p);
void deleteFirstJurnalis(ListJurnalis &J, adrJurnalis &p);
void deleteLastJurnalis(ListJurnalis &J, adrJurnalis &p);
void deleteAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis &p);
adrJurnalis findJurnalisByid(ListJurnalis J, string idJurnalis);
adrJurnalis findJurnalisByName(ListJurnalis J, string name);
adrJurnalis findJurnalisByBidang(ListJurnalis J, string bidang);
adrJurnalis findJurnalisByStatus(ListJurnalis J, string status);
void showAllJurnalis(ListJurnalis J);

adrJurnalis findJurnalisByName(ListJurnalis J, string name);



#endif // JURNALIS_H_INCLUDED

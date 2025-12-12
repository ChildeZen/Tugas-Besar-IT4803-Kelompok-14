#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
#include "jurnalis.h"
#include "Berita.h"


//parent.h atau jurnalis.h

struct Jurnalis {
    int idJurnalis;
    string nama;
    string bidang;
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


void createList(ListRelasi &L);
void insertFirst(ListRelasi &L, adrRelasi P);
void insertLast(ListRelasi &L, adrRelasi P);
void insertAfter(adrRelasi Prec, adrRelasi P);
void deleteFirst(ListRelasi &L, adrRelasi &P);
void deleteLast(ListRelasi &L, adrRelasi &P);
void deleteAfter(ListRelasi Prec, adrRelasi &P);


adrRelasi alokasi(adrBerita C);
void dealokasi(adrRelasi &P);
adrRelasi findElm(ListRelasi L, adrBerita C);
void printInfo(ListRelasi L);

void createListJurnalis(ListJurnalis &J);
adrJurnalis allocateJurnalis(infotypeJurnalis x);
void insertFirstJurnalis(ListJurnalis &J, adrJurnalis p);
void insertLastJurnalis(ListJurnalis &J, adrJurnalis p);
void insertAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis p);
void deleteFirstJurnalis(ListJurnalis &J, adrJurnalis &p);
void deleteLastJurnalis(ListJurnalis &J, adrJurnalis &p);
void deleteAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis &p);
adrJurnalis findJurnalis(ListJurnalis J, string idJurnalis);
void showAllJurnalis(ListJurnalis J);



#endif // JURNALIS_H_INCLUDED

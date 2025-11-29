#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct Jurnalis {
    string idJurnalis;
    string nama;
};

typedef struct Jurnalis infotypeJurnalis;
typedef struct elmJurnalis *adrJurnalis;

struct elmJurnalis {
    infotypeJurnalis info;
    adrJurnalis next;
    adrJurnalis prev;
};

struct ListJurnalis {
    adrJurnalis first;
    adrJurnalis last;
};

void createListJurnalis(ListJurnalis &J);
adrJurnalis allocateJurnalis(infotypeJurnalis x);
void deallocateJurnalis(adrJurnalis &p);
void insertFirstJurnalis(ListJurnalis &J, adrJurnalis p);
void insertLastJurnalis(ListJurnalis &J, adrJurnalis p);
void insertAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis p);
void deleteFirstJurnalis(ListJurnalis &J, adrJurnalis &p);
void deleteLastJurnalis(ListJurnalis &J, adrJurnalis &p);
void deleteAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis &p);
adrJurnalis findJurnalis(ListJurnalis J, string idJurnalis);
void showAllJurnalis(ListJurnalis Lj);

#endif //JURNALIS_H_INCLUDED

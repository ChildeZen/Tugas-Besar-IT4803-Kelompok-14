#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "jurnalis.h"
#include "berita.h"

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    adrJurnalis jurnalis; 
    adrBerita berita; 
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

#endif
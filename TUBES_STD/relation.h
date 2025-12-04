#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "jurnalis.h"
#include "berita.h"

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    adrBerita berita;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

#endif // RELATION_H_INCLUDED

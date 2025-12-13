#include "Jurnalis.h"
#include <iostream>

void createList(ListRelasi &L){
    L.first = nullptr;
}

adrRelasi alokasi(adrBerita C){
    adrRelasi p = new elmRelasi;
    p->info = C;
    p->next = nullptr;
    return p;
}

void dealokasi(adrRelasi &P){}

adrRelasi findElm(ListRelasi L, adrBerita C){
    adrRelasi P = L.first;
    while (P != nullptr){
        if(P->info == C){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void printInfo(ListRelasi L){

}

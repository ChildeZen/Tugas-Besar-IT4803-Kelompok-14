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

void insertFirst(ListRelasi &L, adrRelasi P){
    P->next = L.first;
    L.first = P;
}

void insertLast(ListRelasi &L, adrRelasi P){

}
void insertAfter(adrRelasi Prec, adrRelasi P){}
void deleteFirst(ListRelasi &L, adrRelasi &P){}
void deleteLast(ListRelasi &L, adrRelasi &P){}
void deleteAfter(ListRelasi Prec, adrRelasi &P){}



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

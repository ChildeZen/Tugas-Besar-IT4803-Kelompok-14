#include "Jurnalis.h"

void createJurnalis (Jurnalis J){
    J.firts = NULL;
}

adrJurnalis allocateJurnalis(infotypeJurnalis x){
    adrJurnalis P = new elmJurnalis;

    P -> info.nama = x.nama;
    P -> info.idJurnalis = x.idJurnalis;
    P -> info.usia = x.usia;
    P -> info.status = x.status;
    P ->next = NULL;
    P -> prev = NULL;
    
    return P;
}

void insertFirstJurnalis(ListJurnalis &J, adrJurnalis p){
    p -> next = J.firts;
    J.first -> prev = p;
    J.first = p;
}

void insertLastJurnalis(ListJurnalis &J, adrJurnalis p) {
    p -> prev = J.last;
    J.last -> next = p;
    J.last = p;
}

void deleteAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis &p) {
    if (J.firts = NULL){
        cout << "list kosong";
    }else if (J.first == J.last){
        p = L.first;
        L.first = NULL;
        L.last = NULL;
    }else  {
        prec -> next = p;
        prec -> nex = p -> next;
        p -> prev = NULL;
        p -> next = NULL;
    }
}

adrJurnalis findJurnalis(ListJurnalis J, string idJurnalis) {
    adrJurnalis x;

    x = J.first;
    while (x != NULL){
        if (x -> info.idJurnalis = idJurnalis){
            return x;
        }else if (x -> info.nama = nama){
            return x;
        }else if (x -> info.bidang = bidang){
            return x;
        }else if (x -> info.status = status){
            return x;
        }
        x = x -> next;
    }
    return NULL;
}



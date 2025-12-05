#include "Jurnalis.h"

void insertAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis p){
    if (J.first == nullptr && J.last == nullptr) {
        insertFirstJurnalis(J, p);
    } else if (prec->next == nullptr) {
        insertLastJurnalis(J, p);
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next = p;
        p->next->prev = prev;
    }
}

void deleteFirstJurnalis(ListJurnalis &J, adrJurnalis &p){
    if (J.first == nullptr && J.last == nullptr) {
        p = nullptr;
        cout << "List kosong";
    } else if(J.first == J.last){
        p = J.first;
        J.first = nullptr;
        J.last = nullptr;
    } else {
        p = J.first;
        J.first = p->next;
        p->next = nullptr;
        J.first->prev = nullptr;
    }
}

void deleteLastJurnalis(ListJurnalis &J, adrJurnalis &p) {
    if (J.first == nullptr && J.last == nullptr) {
        p = nullptr;
    } else if (J.first == J.last) {
        p = J.first;
        J.first = nullptr;
        J.last = nullptr;
    } else {
        p = J.first;
        J.first = p->next;
        p->next = nullptr;
        J.first->prev == nullptr;

    }
}


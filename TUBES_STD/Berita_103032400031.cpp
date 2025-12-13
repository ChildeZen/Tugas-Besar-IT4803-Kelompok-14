#include "Berita.h"
#include <iostream>

void insertafterBerita (ListBerita &B, adrBerita prec, adrBerita &b){
    if (B.first == nullptr){
        insertFirstBerita(B, b);
    }else {
        b -> next = prec -> next;
        prec -> next = b;
    }
}

void deleteAfterBerita(ListBerita &B, adrBerita prec, adrBerita b){
    if (B.first == nullptr){
        cout << "list sudah kosong";
    }else if (B.first->next->next == nullptr) {
        b = prec->next;
        prec->next = nullptr;
    } else {
        b = prec->next;
        prec->next = b->next;
        b->next = nullptr;
        }
}

void deleteLastBerita(ListBerita &B, adrBerita &b){
    adrBerita q;

    if(B.first == nullptr){
        b = nullptr;
    } else if (B.first->next == nullptr) {
        b = B.first;
        B.first = nullptr;
    } else {
        q = B.first;
        while(q->next->next != nullptr) {
            q = q->next;
        }
        b = q->next;
        q->next = nullptr;
    }

}


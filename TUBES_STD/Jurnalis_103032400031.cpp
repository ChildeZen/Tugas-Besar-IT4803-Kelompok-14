#include "Jurnalis.h"

void createListJurnalis(ListJurnalis &J) {
    J.first = nullptr;
    J.last = nullptr;
}

adrJurnalis allocateJurnalis(infotypeJurnalis x) {
    adrJurnalis P = new elmJurnalis;
    P->info.nama = x.nama;
    P->info.idJurnalis = x.idJurnalis;
    P->info.status = x.status;
    P->next = nullptr;
    P->prev = nullptr;

    return P;
}

void insertFirstJurnalis(ListJurnalis &J, adrJurnalis p) {
    if (J.first == nullptr) {
        J.first = p;
        J.last = p;
    } else {
        p->next = J.first;
        J.first->prev = p;
        J.first = p;
    }
}

void insertLastJurnalis(ListJurnalis &J, adrJurnalis p) {
    if (J.first == nullptr) {
        J.first = p;
        J.last = p;
    } else {
        p->prev = J.last;
        J.last->next = p;
        J.last = p;
    }
}

void deleteAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis &p) {
    if (J.first == nullptr ) {
        cout << "List kosong" << endl;
    } else if (J.last == J.first) {
        p = J.first;
        J.first = nullptr;
        J.last = nullptr;
    } else {
        p = prec->next;
        prec->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = prec;
        } else {
            J.last = prec;
        }
        p->prev = nullptr;
        p->next = nullptr;
    }
}

adrJurnalis findJurnalisByid(ListJurnalis J, string idJurnalis) {
    adrJurnalis x = J.first;
    while (x != nullptr) {
        if (x->info.idJurnalis == idJurnalis) {
            return x;
        }
        x = x->next;
    }
    return nullptr;
}

adrJurnalis findJurnalisByName(ListJurnalis J, string name) {
    adrJurnalis x = J.first;
    while (x != nullptr) {
        if (x->info.nama == name) {
            return x;
        }
        x = x->next;
    }
    return nullptr;
}

adrJurnalis findJurnalisByStatus(ListJurnalis J, string status) {
    adrJurnalis x = J.first;
    while (x != nullptr) {
        if (x->info.status == status) {
            return x;
        }
        x = x->next;
    }
    return nullptr;
}

void showAllJurnalis(ListJurnalis J) {
    adrJurnalis p = J.first;
    if (J.first == nullptr) {
        cout << "List Jurnalis Kosong!" << endl;
        return;
    }

    cout << "\n========== DAFTAR JURNALIS ==========" << endl;
    cout << "-------------------------------------" << endl;

    int nomor = 1;
    while (p != nullptr) {
        cout << "Jurnalis ke-" << nomor << endl;
        cout << "ID Jurnalis : " << p->info.idJurnalis << endl;
        cout << "Nama        : " << p->info.nama << endl;
        cout << "Status      : " << p->info.status << endl;
        cout << "-------------------------------------" << endl;

        p = p->next;
        nomor++;
    }
}

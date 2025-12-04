#include "Jurnalis.h"

void createJurnalis(ListJurnalis &J) {
    J.first = NULL;
    J.last = NULL;
}

adrJurnalis allocateJurnalis(infotypeJurnalis x) {
    adrJurnalis P = new elmJurnalis;
    P->info.nama = x.nama;
    P->info.idJurnalis = x.idJurnalis;
    P->info.bidang = x.bidang;
    P->info.status = x.status;
    P->next = NULL;
    P->prev = NULL;

    return P;
}

void insertFirstJurnalis(ListJurnalis &J, adrJurnalis p) {
    if (J.first == NULL) {
        J.first = p;
        J.last = p;
    } else {
        p->next = J.first;
        J.first->prev = p;
        J.first = p;
    }
}

void insertLastJurnalis(ListJurnalis &J, adrJurnalis p) {
    if (J.first == NULL) {
        J.first = p;
        J.last = p;
    } else {
        p->prev = J.last;
        J.last->next = p;
        J.last = p;
    }
}

void deleteAfterJurnalis(ListJurnalis &J, adrJurnalis prec, adrJurnalis &p) {
    if (J.first == NULL) {
        cout << "List kosong" << endl;
    } else if (prec == NULL || prec->next == NULL) {
        cout << "Tidak ada elemen setelah prec" << endl;
    } else {
        p = prec->next;
        prec->next = p->next;
        if (p->next != NULL) {
            p->next->prev = prec;
        } else {
            J.last = prec;
        }
        p->prev = NULL;
        p->next = NULL;
    }
}

adrJurnalis findJurnalisByid(ListJurnalis J, int idJurnalis) {
    adrJurnalis x = J.first;
    while (x != NULL) {
        if (x->info.idJurnalis == idJurnalis) {
            return x;
        }
        x = x->next;
    }
    return NULL;
}

adrJurnalis findJurnalisByName(ListJurnalis J, string name) {
    adrJurnalis x = J.first;
    while (x != NULL) {
        if (x->info.nama == name) {
            return x;
        }
        x = x->next;
    }
    return NULL;
}

adrJurnalis findJurnalisByBidang(ListJurnalis J, string bidang) {
    adrJurnalis x = J.first;
    while (x != NULL) {
        if (x->info.bidang == bidang) {
            return x;
        }
        x = x->next;
    }
    return NULL;
}

adrJurnalis findJurnalisByStatus(ListJurnalis J, string status) {
    adrJurnalis x = J.first;
    while (x != NULL) {
        if (x->info.status == status) {
            return x;
        }
        x = x->next;
    }
    return NULL;
}

void showAllJurnalis(ListJurnalis J) {
    adrJurnalis p = J.first;
    if (J.first == NULL) {
        cout << "List Jurnalis Kosong!" << endl;
        return;
    }

    cout << "\n========== DAFTAR JURNALIS ==========" << endl;
    cout << "-------------------------------------" << endl;

    int nomor = 1;
    while (p != NULL) {
        cout << "Jurnalis ke-" << nomor << endl;
        cout << "ID Jurnalis : " << p->info.idJurnalis << endl;
        cout << "Nama        : " << p->info.nama << endl;
        cout << "Bidang      : " << p->info.bidang << endl;
        cout << "Status      : " << p->info.status << endl;
        cout << "-------------------------------------" << endl;

        p = p->next;
        nomor++;
    }
}

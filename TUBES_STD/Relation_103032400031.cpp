void insertFirst(ListRelasi &L, adrRelasi P){
    P->next = L.first;
    L.first = P;
}

void insertLast(ListRelasi &L, adrRelasi P){
    adrRelasi q;
    if (L.first == nullptr){
        L.first = P;
    } else {
        q = L.first;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = P;
    }
}

void insertAfter(ListRelasi &L, adrRelasi Prec, adrRelasi P){
    if (Prec != nullptr){
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(ListRelasi &L, adrRelasi &P){
    if (L.first == nullptr){
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLast(ListRelasi &L, adrRelasi &P){
    adrRelasi q;
    if (L.first == nullptr){
        P = nullptr;
    } else if (L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
        P->next = nullptr;
    } else {
        q = L.first;
        while (q->next->next != nullptr){
            q = q->next;
        }
        P = q->next;
        q->next = nullptr;
        P->next = nullptr;
    }
}

void deleteAfter(ListRelasi Prec, adrRelasi &P){
    if (Prec != nullptr && Prec->next != nullptr){
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void showJurnalisWithBerita_103032400031(ListJurnalis J){
    adrRelasi r;
    adrJurnalis p = J.first;

    while (p != nullptr){
        cout << "Jurnalis: " << p->info.nama << endl;

        r = p->Berita.first;

        if (r == nullptr){
            cout << "  (tidak memiliki berita)" << endl;
        } else {
            while (r != nullptr){
                cout << "  Judul Berita: "
                     << r->info->info.judul << endl;
                r = r->next;
            }
        }

        cout << endl;
        p = p->next;
    }
}


void showJurnalisByJudulBerita(ListJurnalis J, ListBerita B, string judul){
    adrBerita target = findBerita(B, judul);
    if (target == nullptr){
        cout << "Berita tidak ditemukan" << endl;
        return;
    }
    showJurnalisByBerita(J, target);
}


void showJurnalisByBerita(ListJurnalis J, adrBerita target){
    adrJurnalis p = J.first;
    bool found = false;

    while (p != nullptr){
        adrRelasi r = p->Berita.first;
        while (r != nullptr){
            if (r->info == target){
                cout << "Jurnalis:" << endl;
                cout << "ID     : " << p->info.idJurnalis << endl;
                cout << "Nama   : " << p->info.nama << endl;
                cout << "Bidang : " << p->info.bidang << endl;
                found = true;
                break;
            }
            r = r->next;
        }
        p = p->next;
    }

    if (!found){
        cout << "Tidak ada jurnalis yang berelasi dengan berita ini." << endl;
    }
}


int countJurnalisByBerita(ListJurnalis J, adrBerita target){
    int count = 0;
    adrJurnalis p = J.first;

    while (p != nullptr){
        adrRelasi r = p->Berita.first;
        while (r != nullptr){
            if (r->info == target){
                count++;
                break;
            }
            r = r->next;
        }
        p = p->next;
    }
    return count;
}


void editRelasiBerita(adrJurnalis p, adrBerita lama, adrBerita baru){
    adrRelasi r = p->Berita.first;
    while (r != nullptr){
        if (r->info == lama){
            r->info = baru;
            cout << "Relasi berhasil diperbarui." << endl;
            return;
        }
        r = r->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
}


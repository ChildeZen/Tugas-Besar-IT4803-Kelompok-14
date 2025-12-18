#include "Jurnalis.h"
#include "Berita.h"
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

adrRelasi findElmRelasi(adrJurnalis J, adrBerita B){
    adrRelasi R =  J->Berita.first;

    while (R != nullptr){
        if(R->info == B){
            return R;
        }
        R = R->next;
    }
    return nullptr;
}

void dealokasi(adrRelasi &R){
    delete R;
    R = nullptr;
}


//sudah//
void connectJurnalisBerita(ListJurnalis &J, ListBerita B, string namaJurnalis, string judulBerita) {
    adrJurnalis P = findJurnalisByName(J, namaJurnalis);
    adrBerita Q = findBerita(B, judulBerita);

    if (P != nullptr && Q != nullptr) {
        if (findElmRelasi(P, Q) == nullptr) {
            adrRelasi R = alokasi(Q);
            insertLast(P->Berita, R);
            cout << "Berhasil menghubungkan!" << endl;
        } else {
            cout << "Relasi sudah ada!" << endl;
        }
    } else {
        cout << "Jurnalis atau Berita tidak ditemukan." << endl;
    }
}

//sudah//
//Show data child dari parent tertentu//
void showBeritaByJurnalis(ListJurnalis J, string namaJurnalis){
    adrJurnalis P = findJurnalisByName(J, namaJurnalis);
    if(P == nullptr){
        cout << "Jurnalis dengan nama " << namaJurnalis << "tidak ditemukan " << endl;
    } else {
        cout << "Daftar Berita Oleh " << P->info.nama << ":" << endl;
        adrRelasi R;
        R = P->Berita.first;

        if(R == nullptr) {
            cout << "Belum ada berita yang ditulis";
        } else {
            int i = 1;
            while (R != nullptr){
                cout << i << ". " << R->info->info.judulBerita << " (" << R->info->info.tanggal << ") " << endl;
                R = R->next;
                i++;
            }
        }
    }

}


//sudah//
//Show data child beserta data parent yang masing-masing child miliki//
void printAllBeritaWithJurnalis(ListBerita LB, ListJurnalis LJ){
   adrBerita B = LB.first;

   int i = 1;
   cout << "\n=== DAFTAR BERITA BERSETA JURNALISNYA ===" << endl;
   while(B != nullptr){
        cout << i << ". Judul   :" << B->info.judulBerita << endl;
        cout << "   Tema    :" << B->info.temaBerita << endl;
        cout << "   Tanggal :" << B->info.tanggal << endl;
        cout << "   Penulis :" ;
        adrJurnalis P = LJ.first;
        bool adaPenulis = false;

        while(P!=nullptr) {
            adrRelasi R = findElmRelasi(P, B );
            if (R!= nullptr){
                cout << P->info.nama << ", ";
                adaPenulis = true;
            }
            P = P->next;
        }
        if(!adaPenulis){
        cout << "Tanpa Penulis (ANANONIM)";
        }
        cout << endl << endl;
        B = B->next;
        i++;
   }
   cout << "\n=========================================" << endl;
}

//sudah//
//Count relation dari setiap element parent//
void countRelasiJurnalis(ListJurnalis J){
    adrJurnalis P = J.first;
    cout << "\n=== JUMLAH BERITA PER JURNALIS ===" << endl;
    while (P != nullptr) {
        int count = 0;
        adrRelasi R = P->Berita.first;
        while (R != nullptr) {
            count++;
            R = R->next;
        }
        cout << "Jurnalis: " << P->info.nama << endl;
        cout << "Jumlah Berita: " << count << endl;
        P = P->next;
        cout << endl;
    }
}
//sudah//
//count berita tanpa relasi dengan jurnalis//
int countBeritaTanpaJurnalis(ListBerita B, ListJurnalis J){
    int count = 0;
    adrBerita adrB = B.first;

    while (adrB != nullptr) {
        bool punyaPenulis = false;
        adrJurnalis adrJ = J.first;
        while (adrJ != nullptr && !punyaPenulis) {
            if (findElmRelasi(adrJ, adrB) != nullptr) {
                punyaPenulis = true;
            }

            adrJ = adrJ->next;
        }

        if (!punyaPenulis) {
            count++;
        }
        adrB = adrB->next;
    }
    return count;
}

void disconnectJurnalisBerita(ListJurnalis &J, ListBerita B, string namaJurnalis, string judulBerita){
    adrJurnalis P = findJurnalisByName(J, namaJurnalis);
    adrBerita targetBerita = findBerita(B, judulBerita);

    if (P == nullptr) {
        cout << "Jurnalis tidak ditemukan!" << endl;
    } else if (targetBerita == nullptr){
        cout << "Berita tidak ditemukan!" << endl;
    } else {
        adrRelasi R = findElmRelasi(P, targetBerita);
        if (R == nullptr) {
        cout << "Jurnalis " << namaJurnalis << " tidak menulis berita tersebut." << endl;

        } else {
            if (P->Berita.first == R) {
                deleteFirst(P->Berita, R);
            } else {
                adrRelasi Prec = P->Berita.first;
                while (Prec->next != R) {
                    Prec = Prec->next;
                }
                deleteAfter(Prec, R);
            }
            dealokasi(R);
            cout << "Relasi berhasil dihapus." << endl;
        }
    }
}


//sudah//
void deleteBeritaRelasi(ListBerita &B, ListJurnalis &J, string judul) {

    adrBerita target = findBerita(B, judul);

    if (target != nullptr) {
        adrJurnalis P = J.first;
        while (P != nullptr) {
            disconnectJurnalisBerita(J, B, P->info.nama, judul);
            P = P->next;
        }

        adrBerita hapus;
        if (B.first == target) {
            deleteFirstBerita(B, hapus);
        } else if (target->next == nullptr) {
            deleteLastBerita(B, hapus);
        } else {

            adrBerita prec = B.first;
            while (prec->next != target) {
                prec = prec->next;
            }
            deleteAfterBerita(B, prec, hapus);
        }


        delete hapus;
        cout << "Berita berhasil dihapus." << endl;

    } else {
        cout << "Berita tidak ditemukan." << endl;
    }
}

//belum
void deleteJurnalisLengkap(ListJurnalis &J, string nama) {

    adrJurnalis P = findJurnalisByName(J, nama);

    if (P != nullptr) {
        adrRelasi R = P->Berita.first;
        while (R != nullptr) {
            adrRelasi hapus = R;
            R = R->next;
            delete hapus;
        }
        P->Berita.first = nullptr;
        adrJurnalis hapusJ;
        if (J.first == P) {
            deleteFirstJurnalis(J, hapusJ);
        } else if (P == J.last) {
            deleteLastJurnalis(J, hapusJ);
        } else {
            adrJurnalis prec = P->prev;
            deleteAfterJurnalis(J, prec, hapusJ);
        }

        delete hapusJ;
        cout << "Jurnalis " << nama << " dan semua relasinya berhasil dihapus." << endl;

    } else {
        cout << "Jurnalis tidak ditemukan." << endl;
    }
}


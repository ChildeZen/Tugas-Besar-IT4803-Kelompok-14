#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>
#include <string>

using namespace std;

// Prototype
void menuParent(ListJurnalis &LJ, ListBerita &LB);
void menuChild(ListBerita &LB);
void menuRelation(ListJurnalis &LJ, ListBerita &LB);

void menuAdmin(ListJurnalis &LJ, ListBerita &LB) {
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ MENU ADMIN ============" << endl;
        cout << "|| 1. Kelola Jurnalis (Parent)    ||" << endl;
        cout << "|| 2. Kelola Berita (Child)       ||" << endl;
        cout << "|| 3. Kelola Relasi               ||" << endl;
        cout << "|| 0. Keluar                      ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi: ";
        if (!(cin >> option)) break;

        switch (option) {
            case 1:
                menuParent(LJ, LB);
                break;
            case 2:
                menuChild(LB);
                break;
            case 3:
                menuRelation(LJ, LB);
                break;
        }
    }
}

void menuParent(ListJurnalis &LJ, ListBerita &LB) {
    int option = -99;
    infotypeJurnalis J;
    adrJurnalis P, prec;
    string cariID, cariNama, judulBerita, id;
    int x;

    while (option != 0) {
        system("cls");
        cout << "========== MENU JURNALIS ==========" << endl;
        cout << "|| 1. Insert First               ||" << endl;
        cout << "|| 2. Insert Last                ||" << endl;
        cout << "|| 3. Insert After               ||" << endl;
        cout << "|| 4. Delete First               ||" << endl;
        cout << "|| 5. Delete Last                ||" << endl;
        cout << "|| 6. Delete After               ||" << endl;
        cout << "|| 7. Cari Jurnalis              ||" << endl;
        cout << "|| 8. Show All Jurnalis          ||" << endl;
        cout << "|| 0. Kembali                    ||" << endl;
        cout << "===================================" << endl;
        cout << "Pilih opsi: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "=== INSERT FIRST JURNALIS ===" << endl;
                cout << "ID Jurnalis : "; cin >> J.idJurnalis;
                cout << "Nama        : "; cin >>  J.nama;
                cout << "Status      : "; cin >> J.status;


                if (findJurnalisByName(LJ, J.nama) != NULL) {
                    cout << "Nama sudah ada!" << endl;
                } else {
                    P = allocateJurnalis(J);
                    insertFirstJurnalis(LJ, P);
                    cout << "Jurnalis berhasil ditambahkan!" << endl;

                    cout << "\nHubungkan Jurnalis ini ke Berita yang sudah ada?" << endl;
                    cout << "1. Ya\n2. Tidak\nPilih: ";
                    cin >> x;
                    if (x == 1) {
                        cout << "Masukkan Judul Berita yang dituju: ";
                        cin >>  judulBerita;
                        connectJurnalisBerita(LJ, LB, J.nama, judulBerita);
                    }
                }
                system("pause");
                break;
            case 2:
                cout << "=== INSERT LAST JURNALIS ===" << endl;
                cout << "ID Jurnalis : "; cin >> J.idJurnalis;
                cout << "Nama        : "; cin >>  J.nama;
                cout << "Status      : "; cin >> J.status;

                if (findJurnalisByName(LJ, J.nama) != NULL) {
                    cout << "Nama sudah ada!" << endl;
                } else {
                    P = allocateJurnalis(J);
                    insertLastJurnalis(LJ, P);
                    cout << "Jurnalis berhasil ditambahkan!" << endl;
                    cout << "\nHubungkan Jurnalis ini ke Berita yang sudah ada?" << endl;
                    cout << "1. Ya\n2. Tidak\nPilih: ";
                    cin >> x;
                    if (x == 1) {
                        cout << "Masukkan Judul Berita yang dituju: ";
                        cin >> judulBerita;
                        connectJurnalisBerita(LJ, LB, J.nama, judulBerita);
                    }
                }
                system("pause");
                break;

            case 3:
                cout << "=== INSERT AFTER JURNALIS ===" << endl;
                cout << "Masukkan Nama Jurnalis sebelumnya (Prec): ";
                cin >> cariNama;
                prec = findJurnalisByName(LJ, cariNama);

                if (prec == NULL) {
                    cout << "Jurnalis referensi tidak ditemukan!" << endl;
                } else {
                    cout << "ID Jurnalis : "; cin >> J.idJurnalis;
                    cout << "Nama        : "; cin >>  J.nama;
                    cout << "Status      : "; cin >> J.status;

                    P = allocateJurnalis(J);
                    insertAfterJurnalis(LJ, prec, P);
                    cout << "Jurnalis berhasil ditambahkan!" << endl;

                    cout << "\nHubungkan Jurnalis ini ke Berita yang sudah ada?" << endl;
                    cout << "1. Ya\n2. Tidak\nPilih: ";
                    cin >> x;
                    if (x == 1) {
                        cout << "Masukkan Judul Berita yang dituju: ";
                        cin >> judulBerita;
                        connectJurnalisBerita(LJ, LB, J.nama, judulBerita);
                    }
                }
                system("pause");
                break;

            case 4:
                deleteFirstJurnalis(LJ, P);
                if (P) cout << "Jurnalis " << P->info.nama << " dihapus." << endl;
                else cout << "List Kosong" << endl;
                system("pause");
                break;

            case 5:
                deleteLastJurnalis(LJ, P);
                if (P) cout << "Jurnalis " << P->info.nama << " dihapus." << endl;
                else cout << "List Kosong" << endl;
                system("pause");
                break;

            case 6:
                cout << "Hapus setelah Jurnalis nama apa? ";
                cin >> cariNama;
                prec = findJurnalisByName(LJ, cariNama);
                if (prec) {
                    deleteAfterJurnalis(LJ, prec, P);
                    if (P) cout << "Jurnalis " << P->info.nama << " dihapus." << endl;
                } else cout << "Jurnalis tidak ditemukan." << endl;
                system("pause");
                break;

            case 7:
                int subOption;
                system("cls");
                cout << "====== CARI JURNALIS ======\n";
                cout << "1. Berdasarkan ID\n";
                cout << "2. Berdasarkan Nama\n";
                cout << "3. Berdasarkan Status\n";
                cout << "Choose search criteria: ";
                cin >> subOption;

                P = nullptr;
                if (subOption == 1) {
                    cout << "Cari ID: "; cin >> id;
                    P = findJurnalisByid(LJ, id);
                } else if (subOption == 2) {
                    string nama;
                    cout << "Cari Nama: "; cin >> nama;
                    P = findJurnalisByName(LJ, nama);
                } else if (subOption == 3) {
                    string status;
                    cout << "Cari Status: "; cin >> status;
                    P = findJurnalisByStatus(LJ, status);
                }

                if (P != nullptr) {
                    cout << "\n--- Data Ditemukan ---\n";
                    cout << "ID     : " << P->info.idJurnalis << endl;
                    cout << "Nama   : " << P->info.nama << endl;
                    cout << "Status : " << P->info.status << endl;
                } else {
                    cout << "\nData Jurnalis tidak ditemukan.\n";
                }
                system("pause");
                break;

            case 8:
                showAllJurnalis(LJ);
                system("pause");
                break;
        }
    }
}

void menuChild(ListBerita &LB) {
    int option = -99;
    infotypeBerita B;
    adrBerita P, prec;
    string cariJudul;

    while (option != 0) {
        system("cls");
        cout << "=========== MENU BERITA ============" << endl;
        cout << "|| 1. Insert First                ||" << endl;
        cout << "|| 2. Insert Last                 ||" << endl;
        cout << "|| 3. Insert After                ||" << endl;
        cout << "|| 4. Delete First                ||" << endl;
        cout << "|| 5. Delete Last                 ||" << endl;
        cout << "|| 6. Delete After                ||" << endl;
        cout << "|| 7. Find Berita                 ||" << endl;
        cout << "|| 8. Show All Berita             ||" << endl;
        cout << "|| 0. Kembali                     ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Judul  : "; cin >> B.judulBerita;
                cout << "Tema   : "; cin >>  B.temaBerita;
                cout << "Tanggal: "; cin >> B.tanggal;
                P = allocateBerita(B);
                insertFirstBerita(LB, P);
                cout << "Berita ditambahkan." << endl;
                system("pause");
                break;
            case 2:
                cout << "Judul  : "; cin >>  B.judulBerita;
                cout << "Tema   : "; cin >> B.temaBerita;
                cout << "Tanggal: "; cin >> B.tanggal;
                P = allocateBerita(B);
                insertLastBerita(LB, P);
                cout << "Berita ditambahkan." << endl;
                system("pause");
                break;
            case 3 :
                cout << "Masukkan JUDUL BERITA sebelumnya: ";
                cin >> cariJudul;

                prec = findBerita(LB, cariJudul);
                if (prec != nullptr) {
                    cout << "Judul Baru : "; cin >> B.judulBerita;
                    cout << "Tema       : "; cin >> B.temaBerita;
                    cout << "Tanggal    : "; cin >> B.tanggal;

                    P = allocateBerita(B);
                    insertAfterBerita(LB, prec, P);
                    cout << "Berita berhasil ditambahkan." << endl;
                } else {
                    cout << "Berita referensi tidak ditemukan\n";
                }
                system("pause");
                break;
            case 4:
                deleteFirstBerita(LB, P);
                if(P) cout << "Berita dihapus." << endl;
                else cout << "List Kosong." << endl;
                system("pause");
                break;
            case 5:
                deleteLastBerita(LB, P);
                if (P) cout << "Berita dihapus." << endl;
                else cout << "List kosong." << endl;
                system("pause");
                break;
            case 6:
                cout << "Hapus setelah Judul apa? ";
                cin >>  cariJudul;
                prec = findBerita(LB, cariJudul);
                if (prec != nullptr) {
                    deleteAfterBerita(LB, prec, P);
                    if (P != nullptr) {
                        cout << "Berita " << P->info.judulBerita << " dihapus.\n";
                        delete P;
                    }
                } else {
                    cout << "Berita tidak ditemukan." << endl;
                }
                system("pause");
                break;
            case 7 :
                cout << "Cari Judul Berita: ";
                cin >> cariJudul;
                P = findBerita(LB, cariJudul);
                if (P != nullptr) cout << "Berita ditemukan: " << P->info.judulBerita << " | " << P->info.temaBerita << endl;
                else cout << "Berita tidak ditemukan\n";
                system("pause");
                break;
            case 8 :
                showAllBerita(LB);
                system("pause");
                break;
        }
    }
}

void menuRelation(ListJurnalis &LJ, ListBerita &LB) {
    int option = -99;
    string namaJurnalis, judulBerita;

    while (option != 0) {
        system("cls");
        cout << "=========== MENU RELASI ============" << endl;
        cout << "|| 1. Hubungkan (Connect)         ||" << endl;
        cout << "|| 2. Putuskan (Disconnect)       ||" << endl;
        cout << "|| 3. Show All Parents + Child    ||" << endl;
        cout << "|| 0. Kembali                     ||" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "=== CONNECT ===" << endl;
                showAllJurnalis(LJ);
                cout << "\nNama Jurnalis: "; cin >> namaJurnalis;

                showAllBerita(LB);
                cout << "Judul Berita : "; cin >> judulBerita;

                connectJurnalisBerita(LJ, LB, namaJurnalis, judulBerita);
                system("pause");
                break;

            case 2:
                cout << "=== DISCONNECT ===" << endl;
                cout << "Nama Jurnalis: "; cin >> namaJurnalis;
                cout << "Judul Berita : "; cin >> judulBerita;

                disconnectJurnalisBerita(LJ, LB, namaJurnalis, judulBerita);
                system("pause");
                break;

            case 3:
                cout << "=== SHOW ALL PARENTS & CHILDREN ===" << endl;
                printAllBeritaWithJurnalis(LB, LJ);
                system("pause");
                break;
        }
    }
}

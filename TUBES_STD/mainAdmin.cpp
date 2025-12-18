#include "main.h"
#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>
#include <string> // Tambahin ini buat keamanan string

using namespace std;

void menuParent(ListJurnalis &LJ);
void menuChild(ListBerita &LB);

void menuAdmin(ListJurnalis &LJ, ListBerita &LB) {
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ MENU ADMIN ============\n";
        cout << "|| 1. Kelola Jurnalis (Parent)    ||\n";
        cout << "|| 2. Kelola Berita (Child)       ||\n";
        cout << "|| 0. Kembali                     ||\n";
        cout << "====================================\n";
        cout << "Choose your option: ";
        if (!(cin >> option)) break; // Cek input valid

        switch (option) {
            case 1: menuParent(LJ); break;
            case 2: menuChild(LB); break;
        }
    }
}

void menuParent(ListJurnalis &LJ) {
    int option = -99;
    infotypeJurnalis J;
    adrJurnalis P, prec;
    string id;

    while (option != 0) {
        system("cls");
        cout << "========== MENU JURNALIS ==========\n";
        cout << "|| 1. Insert First               ||\n";
        cout << "|| 2. Insert Last                ||\n";
        cout << "|| 3. Insert After               ||\n";
        cout << "|| 4. Delete First               ||\n";
        cout << "|| 5. Delete Last                ||\n";
        cout << "|| 6. Delete After               ||\n";
        cout << "|| 7. Find Jurnalis              ||\n";
        cout << "|| 8. Show All Jurnalis          ||\n";
        cout << "|| 0. Back                       ||\n";
        cout << "===================================\n";
        cout << "Choose your option: ";
        cin >> option;

        switch (option) {
        case 1: { // Tambahkan kurung kurawal untuk scope variabel
            cout << "ID      : "; cin >> J.idJurnalis;
            cout << "Nama    : "; cin >> ws; getline(cin, J.nama);
            cout << "Status  : "; cin >> J.status;

            bool namaDipakai = false;
            adrJurnalis Q = LJ.first;
            while (Q != nullptr){
                if (Q->info.nama == J.nama){
                    namaDipakai = true;
                    break;
                }
                Q = Q->next;
            }

            if (namaDipakai){
                cout << "Nama sudah digunakan!" << endl;
            } else {
                P = allocateJurnalis(J);
                insertFirstJurnalis(LJ, P);
                cout << "Jurnalis berhasil ditambahkan (First)." << endl;
            }
            system("pause");
            break;
        }
        case 2:
            cout << "ID      : "; cin >> J.idJurnalis;
            cout << "Nama    : "; cin >> ws; getline(cin, J.nama);
            cout << "Status  : "; cin >> J.status;

            P = allocateJurnalis(J);
            insertLastJurnalis(LJ, P);
            cout << "Jurnalis berhasil ditambahkan (Last)." << endl;
            system("pause");
            break;

        case 3:
            cout << "Masukkan ID Jurnalis sebelumnya: "; cin >> id;
            prec = findJurnalisByid(LJ, id);
            if (prec != nullptr) {
                cout << "ID      : "; cin >> J.idJurnalis;
                cout << "Nama    : "; cin >> ws; getline(cin, J.nama);
                cout << "Status  : "; cin >> J.status;

                P = allocateJurnalis(J);
                insertAfterJurnalis(LJ, prec, P);
                cout << "Jurnalis berhasil ditambahkan." << endl;
            } else {
                cout << "Jurnalis pencari tidak ditemukan\n";
            }
            system("pause");
            break;

        case 4:
            deleteFirstJurnalis(LJ, P);
            if (P != nullptr) {
                cout << "Jurnalis " << P->info.nama << " berhasil dihapus." << endl;
                delete P;
            }
            system("pause");
            break;

        case 5:
            deleteLastJurnalis(LJ, P);
            if (P != nullptr) {
                cout << "Jurnalis " << P->info.nama << " berhasil dihapus." << endl;
                delete P;
            }
            system("pause");
            break;

        case 6:
            cout << "Masukkan ID Jurnalis sebelumnya: "; cin >> id;
            prec = findJurnalisByid(LJ, id);
            if (prec != nullptr) {
                deleteAfterJurnalis(LJ, prec, P);
                if (P != nullptr) {
                    cout << "Jurnalis " << P->info.nama << " berhasil dihapus." << endl;
                    delete P;
                }
            } else {
                cout << "ID tidak ditemukan." << endl;
            }
            system("pause");
            break;

        case 7:
            int subOption;
            system("cls");
            cout << "====== CARI JURNALIS ======\n";
            cout << "1. Berdasarkan ID\n";
            cout << "2. Berdasarkan Nama\n";
            cout << "4. Berdasarkan Status\n";
            cout << "Choose search criteria: ";
            cin >> subOption;

            if (subOption == 1) {
                cout << "Cari ID: "; cin >> id;
                P = findJurnalisByid(LJ, id);
            } else if (subOption == 2) {
                string nama;
                cout << "Cari Nama: "; cin >> ws; getline(cin, nama);
                P = findJurnalisByName(LJ, nama); // Pastikan fungsi ini ada
            }else if (subOption == 3) {
                string status;
                cout << "Cari Status: "; cin >> status;
                P = findJurnalisByStatus(LJ, status);
            }

            // Tampilkan hasil
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

// Lakukan hal yang sama untuk menuChild (tambahkan scope { } dan system pause)
void menuChild(ListBerita &LB) {
    int option = -99;
    infotypeBerita B;
    adrBerita P, prec;
    string judul;

    while (option != 0) {
        system("cls");
        cout << "=========== MENU BERITA ===========\n";
        cout << "|| 1. Insert First               ||\n";
        cout << "|| 2. Insert Last                ||\n";
        cout << "|| 3. Insert After               ||\n";
        cout << "|| 4. Delete First               ||\n";
        cout << "|| 5. Delete Last                ||\n";
        cout << "|| 6. Delete After               ||\n";
        cout << "|| 7. Find Berita                ||\n";
        cout << "|| 8. Show All Berita            ||\n";
        cout << "|| 0. Back                       ||\n";
        cout << "===================================\n";
        cout << "Choose your option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Judul   : ";
            cin >> B.judulBerita;
            cout << "Tema    : "; getline(cin, B.temaBerita);
            cout << "Tanggal : "; cin >> B.tanggal;
            P = allocateBerita(B);
            insertFirstBerita(LB, P);
            cout << "Berita ditambahkan.\n";
            system("pause");
            break;

        case 2:
            cout << "Judul   : "; cin >> ws; getline(cin, B.judulBerita);
            cout << "Tema    : "; getline(cin, B.temaBerita);
            cout << "Tanggal : "; cin >> B.tanggal;
            P = allocateBerita(B);
            insertLastBerita(LB, P);
            cout << "Berita ditambahkan.\n";
            system("pause");
            break;

        case 3: {
            cout << "Judul sebelumnya: "; cin >> ws; getline(cin, judul);
            prec = findBerita(LB, judul);
            if (prec != nullptr) {
                cout << "Judul Baru: "; getline(cin, B.judulBerita);
                cout << "Tema      : "; getline(cin, B.temaBerita);
                cout << "Tanggal   : "; cin >> B.tanggal;
                P = allocateBerita(B);
                insertAfterBerita(LB, prec, P);
            } else {
                cout << "Judul referensi tidak ditemukan.\n";
            }
            system("pause");
            break;
        }
        case 4:
            deleteFirstBerita(LB, P);
            if (P != nullptr) { cout << "Berita dihapus.\n"; delete P; }
            system("pause");
            break;

        case 5:
            deleteLastBerita(LB, P);
            if (P != nullptr) { cout << "Berita dihapus.\n"; delete P; }
            system("pause");
            break;

        case 6: {
            cout << "Judul sebelumnya: "; cin >> ws; getline(cin, judul);
            prec = findBerita(LB, judul);
            if (prec != nullptr) {
                deleteAfterBerita(LB, prec, P);
                if (P != nullptr) delete P;
                cout << "Berita berhasil dihapus.\n";
            }
            system("pause");
            break;
        }
        case 7:
            cout << "Judul Berita: "; cin >> ws; getline(cin, judul);
            P = findBerita(LB, judul);
            if (P != nullptr) cout << "Berita ditemukan: " << P->info.judulBerita << endl;
            else cout << "Berita tidak ditemukan\n";
            system("pause");
            break;

        case 8:
            showAllBerita(LB);
            system("pause");
            break;
        }
    }
}

#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>
using namespace std;

void menuUser(ListJurnalis &LJ, ListBerita &LB) {
    int option = -99;
    string namaJurnalis, judulBerita;
    adrJurnalis PJ;
    adrBerita PB;
    int hasil;

    while (option != 0) {
        system("cls");
        cout << "============= MENU USER =============\n";
        cout << "||  1. Lihat berita dari jurnalis    ||\n";
        cout << "||  2. Lihat semua jurnalis + berita ||\n";
        cout << "||  3. Lihat semua berita + jurnalis ||\n";
        cout << "||  4. Lihat jurnalis dari berita    ||\n";
        cout << "||  5. Hitung berita tiap jurnalis   ||\n";
        cout << "||  6. Hitung jurnalis dari berita   ||\n";
        cout << "||  7. Hitung berita tanpa jurnalis  ||\n";
        cout << "||  8. Edit relasi berita            ||\n";
        cout << "||  9. Delete Berita dan Relasinya   ||\n";
        cout << "|| 10. Delete Jurnalis dan Relasinya ||\n";
        cout << "||  0. Keluar                        ||\n";
        cout << "=====================================\n";
        cout << "Choose your option: ";
        cin >> option;
        system("pause");

        switch (option) {

        // 1. Lihat berita dari jurnalis tertentu
        case 1:
            cout << "Nama Jurnalis: ";
            cin >> namaJurnalis;

            PJ = findJurnalisByName(LJ, namaJurnalis);
            if (PJ != nullptr) {
                showBeritaByJurnalis(LJ, namaJurnalis);
            } else {
                cout << "Jurnalis tidak ditemukan\n";
            }
            system("pause");
            break;

        // 2. Semua jurnalis + beritanya
        case 2:
            showJurnalisWithBerita(LJ);
            system("pause");
            break;

        // 3. Semua berita + jurnalisnya
        case 3:
            printAllBeritaWithJurnalis(LB, LJ);
            system("pause");
            break;

        // 4. Jurnalis dari berita tertentu
        case 4:
            cout << "Judul Berita: ";
            cin >> judulBerita;

            PB = findBerita(LB, judulBerita);
            if (PB != nullptr) {
                showJurnalisByBerita(LJ, PB);
            } else {
                cout << "Berita tidak ditemukan\n";
            }
            system("pause");
            break;

        // 5. Hitung berita tiap jurnalis
        case 5:
            countRelasiJurnalis(LJ);
            system("pause");
            break;

        // 6. Hitung jurnalis dari berita tertentu
        case 6:
            cout << "Judul Berita: ";
            cin >> judulBerita;

            PB = findBerita(LB, judulBerita);
            if (PB != nullptr) {
                hasil = countJurnalisByBerita(LJ, PB);
                cout << "Jumlah jurnalis: " << hasil << endl;
            } else {
                cout << "Berita tidak ditemukan\n";
            }
            system("pause");
            break;

        // 7. Hitung berita tanpa jurnalis
        case 7:
            hasil = countBeritaTanpaJurnalis(LB, LJ);
            cout << "Jumlah berita tanpa jurnalis: " << hasil << endl;
            system("pause");
            break;

        // 8. Edit relasi berita
       case 8: {
           string namaJurnalis, judulLamaStr, judulBaruStr;
           adrJurnalis pJ;
           adrBerita pLama;
           adrBerita pBaru;
           cout << "--- Edit Relasi Berita ---" << endl;
           cout << "Masukan nama Jurnalis: ";
           cin >> namaJurnalis;
            pJ = findJurnalisByName(LJ, namaJurnalis);
            if (pJ == nullptr) {
                cout << "Error: Jurnalis tidak ditemukan!" << endl;
            }

            cout << "Masukan Judul Berita LAMA (yang mau diganti): ";
            cin >> judulLamaStr;
            pLama = findBerita(LB, judulLamaStr);
            if (pLama == nullptr) {
                cout << "Error: Berita lama tidak ditemukan!" << endl;
            }

            cout << "Masukan Judul Berita BARU: ";
            cin >> judulBaruStr;
            pBaru = findBerita(LB, judulBaruStr);

            if (pBaru != nullptr) {
                cout << "Info: Berita dengan judul tersebut sudah ada." << endl;
                cout << "Menghubungkan ke berita yang sudah ada..." << endl;
            } else {
                cout << "Judul Berita belum ada di List" << endl;
            }
            if (pJ != nullptr && pLama != nullptr && pBaru != nullptr) {
                editRelasiBerita(pJ, pLama, pBaru);
            } else {
                cout << "Terjadi kesalahan data." << endl;
            }
            system("pause");
            break;
        }

        case 9 : {
            string cariJudul;

            cout << "Masukkan Judul Berita yang akan dihapus: ";
            cin >> cariJudul;

            deleteBeritaRelasi(LB, LJ, cariJudul);
            system("pause");
            break;

        }
        case 10: {
            string namaHapus;

            cout << "Menghapus Jurnalis akan menghapus relasinya juga!!!" << endl;
            cout << "Masukkan nama jurnalis yang akan dihapus: ";
            cin >> namaHapus;

            deleteJurnalisLengkap(LJ, namaHapus);

            system("pause");
            break;

        }
    }
}
}


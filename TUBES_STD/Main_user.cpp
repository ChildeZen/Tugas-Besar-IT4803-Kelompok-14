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
        cout << "|| 1. Lihat berita dari jurnalis    ||\n";
        cout << "|| 2. Lihat semua jurnalis + berita ||\n";
        cout << "|| 3. Lihat semua berita + jurnalis ||\n";
        cout << "|| 4. Lihat jurnalis dari berita    ||\n";
        cout << "|| 5. Hitung berita tiap jurnalis   ||\n";
        cout << "|| 6. Hitung jurnalis dari berita   ||\n";
        cout << "|| 7. Hitung berita tanpa jurnalis  ||\n";
        cout << "|| 8. Edit relasi berita            ||\n";
        cout << "|| 9. Connect                       ||\n";
        cout << "|| 0. Keluar                        ||\n";
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
            string judulLama, judulBaru;

            cout << "Nama Jurnalis: ";
            cin >> namaJurnalis;
            cout << "Judul Berita Lama: ";
            cin >> judulLama;
            cout << "Judul Berita Baru: ";
            cin >> judulBaru;

            PJ = findJurnalisByName(LJ, namaJurnalis);
            adrBerita lama = findBerita(LB, judulLama);
            adrBerita baru = findBerita(LB, judulBaru);

            if (PJ != nullptr && lama != nullptr && baru != nullptr) {
                editRelasiBerita(PJ, lama, baru);
            } else {
                cout << "Data tidak valid\n";
            }

            system("pause");
            break;
        }
        case 9 :{
            cout << "masukan nama jurnalis";
            cin >> namaJurnalis;
            cout << "masukan judul berita";
            cin >> judulBerita;
            connectJurnalisBerita(LJ, LB, namaJurnalis, judulBerita);
        }

        }
    }
}

#include <iostream>
#include "main.h"
#include "Jurnalis.h"
#include "Berita.h"

using namespace std;


int main()
{
    ListJurnalis LJ;
    ListBerita LB;

    createListJurnalis(LJ);
    createListBerita(LB);

    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1. Test Case             ||" << endl;
        cout << "|| 2. Study Case            ||" << endl;
        cout << "|| 0. Exit                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1:
              cout << "you choose option 1" << endl;
              menuAdmin(LJ, LB);
              break;

           case 2:
              cout << "you choose option 2" << endl;
              menuUser(LJ, LB);
              break;

           case 0:
              cout << "Program selesai." << endl;
              break;

           default:
              cout << "Pilihan tidak valid!" << endl;
              system("pause");
        }
    }

    return 0;
}

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include "Jurnalis.h"
#include "Berita.h"

using namespace std;

void menuAdmin(ListJurnalis &LJ, ListBerita &LB);
void menuUser(ListJurnalis &LJ, ListBerita &LB);
void menuParent();
void menuChild();




#endif // MAIN_H_INCLUDED

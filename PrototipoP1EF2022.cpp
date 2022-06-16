#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include<conio.h>
#include<math.h>

using namespace std;

class cinema{
public:
    void menuGeneral();
    void menuPeliculas();
    void menuSalas();
    void menuAsientos();
    void menuCines();
    void menuClientes();

private:
    string desicion;
};

void cinema::menuGeneral(){
    system ("cls");
    int menu;
    cout << "\n\t\t\tBienvenido al PrototipoP1EF2022 de *William Ottoniel Mayen Vasquez 9959-21-1581*";
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Peliculas\n" << "\t\t[2] Salas\n" << "\t\t[3] Asientos\n" << "\t\t[4] Cines\n" << "\t\t[5] Clientes\n" << "\t\t[6] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuPeliculas();
        break;
    case 2:
        menuSalas();
        break;
    case 3:
        menuAsientos();
        break;
    case 4:
        menuCines();
        break;
    case 5:
        menuClientes();
        break;
    case 6:
        cout << "\n\t\t�Quiere salir del PrototipoP1EF2022? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            cout<<"\n\n\t\tGRACIAS POR USAR EL *PrototipoP1EF2022* :)";
            cout<<"\n\n\t\t";system("pause");
            return exit (1);
        }
        else {
            return menuGeneral();
        break;
        }
    }
}


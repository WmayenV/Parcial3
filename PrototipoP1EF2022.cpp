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


using namespace std;

class cinema{
public:
    void menuGeneral();
    void menuPeliculas();
    void registrarPeliculas();
    void modificarPeliculas();
    void eliminarPeliculas();
    void mostrarPeliculas();
    void menuSalas();
    void menuAsientos();
    void menuCines();
    void menuClientes();

private:
    string desicion, numSerie, nombre, clasif, duracion, baseDatos, busquedaDatos, modBaseDatos, mostrarDatosPeliculas;
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
void cinema::menuPeliculas(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU PELICULAS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar pelicula\n" << "\t\t[2] Modificar pelicula\n" <<  "\t\t[3] Eliminar pelicula\n" << "\t\t[4] Mostrar peliculas\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarPeliculas();
        break;
    case 2:
        modificarPeliculas();
        break;
    case 3:
        eliminarPeliculas();
        break;
    case 4:
        mostrarPeliculas();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PELICUALAS--" << endl;
        cout<<"\t";system ("pause");
        return menuPeliculas();
        break;
    }
}

void cinema::registrarPeliculas(){
    system("cls");
    cout << "\n\t\t\tEntrando al menu --REGISTRAR PELICULAS--\n" << endl;
    cout << "\n\t�Quires salir al --MENU PELICULAS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPeliculas();
    }
    else {
        cout << "\n\t\tIngrese el numero de serie de la pelicula: "; cin >> numSerie;
        cout << "\t\tIngrese el nombre de la pelicula a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la clasificacion de la pelicula a registrar: "; cin >> clasif;
        cout << "\t\tIngrese la duracion de la pelicula a registrar: "; cin >> duracion;
        cout << "\n\t--Registro de pelicula completado--\n" << endl;
        //baseDatos.open("peliculas.dat",ios::app | ios::out | ios::binary);
       // baseDatos<<std::left<<std::setw(15)<< numSerie <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasif <<std::left<<std::setw(15)<< duracion <<"\n";
        //baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU Peliculas--";
    cout<<"\n\t";system("pause");
    return menuPeliculas();
}

void cinema::modificarPeliculas(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR Pelicula--" << endl;
    baseDatos.open("peliculas.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU Peliculas--";
        cout<<"\n\t";system("pause");
        return menuPeliculas();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de serie de la pelicula que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalPeliculas.dat",ios::out|ios::binary);
        baseDatos>>numSerie>>nombre>>clasif>>duracion;
        while (!baseDatos.eof()){
            if (busquedaDatos!=numSerie){
                modBaseDatos <<std::left<<std::setw(15)<< numSerie <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasif <<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de serie de la pelicula: "; cin >> numSerie;
                cout << "\t\tIngrese el nombre de la pelicula a registrar: "; cin >> nombre;
                cout << "\t\tIngrese la clasificacion de la pelicula a registrar: "; cin >> clasif;
                cout << "\t\tIngrese la duracion de la pelicula a registrar: "; cin >> duracion;
                modBaseDatos <<std::left<<std::setw(15)<< numSerie <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasif <<std::left<<std::setw(15)<< duracion <<"\n";
            }
            baseDatos>>numSerie>>nombre>>clasif>>duracion;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "peliculas.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalPeliculas.dat","peliculas.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU PELICULAS--";
    cout<<"\n\t";system("pause");
    return menuPeliculas();
}

void cinema::eliminarPeliculas(){
    system("cls");
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR PELICULA--" << endl;
//	baseDatos.open("peliculas.dat",ios::in|ios::binary);
//    if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
//		baseDatos.close();
	}
	//else
	{
		cout << "\n\t\tIngrese el numero de serie de la pelicula que busca: "; cin >> busquedaDatos;
		//modBaseDatos.open("temporalPeliculas.dat", ios::app | ios::out | ios::binary);
		//baseDatos>>numSerie>>nombre>>clasif>>duracion;
		//while(!baseDatos.eof())
		{
			if(busquedaDatos!=numSerie)
			{
				//modBaseDatos <<std::left<<std::setw(15)<< numSerie <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasif <<std::left<<std::setw(15)<< duracion <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			//baseDatos>>numSerie>>nombre>>clasif>>duracion>>;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Pelicula no encontrada...\a";
		}
//		baseDatos.close();
//		modBaseDatos.close();
//    if (baseDatos.is_open())
//        baseDatos.close();
 //   if (modBaseDatos.is_open())
 //       modBaseDatos.close();

    if( remove( "peliculas.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalPeliculas.dat","peliculas.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU PELICULAS--";
    cout<<"\n\t";system("pause");
    return menuPeliculas();
}

void cinema::mostrarPeliculas(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR PELICULAS--";
    cout << "\n\n\t\t�Quiere buscar una pelicula en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("peliculas.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR PELICULA--"<<endl;
            cout << "\n\t\tIngrese el numero de serie de la pelicula a buscar: "; cin >> numSerie;
            baseDatos>>numSerie>>nombre>>clasif>>duracion;
            while(!baseDatos.eof()){
                if(busquedaDatos==numSerie){
                    cout<<"\n\t\tDocumento de serie: "<< numSerie;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tClasificacion: "<< clasif;
                    cout<<"\n\t\tDuracion: "<< duracion;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU PELICULAS--";
                    cout<<"\n\t";system("pause");
                    return menuPeliculas();
                }
                baseDatos>>numSerie>>nombre>>clasif>>duracion;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR PELICULAS--";
                cout<<"\n\t";system("pause");
//                return mostrarDatosPeliculas();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR PEliculas"<<endl;
        baseDatos.open("peliculas.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU PWELICUlas--";
            cout<<"\n\t";system("pause");
            return menuPeliculas();
        }
        else
        {
            baseDatos>>numSerie>>nombre>>clasif>>duracion;
            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\n\t\tNUmero de serie: "<< numSerie;
                cout<<"\n\t\tNombre: " << nombre;
                cout<<"\n\t\tClasif: "<< clasif;
                cout<<"\n\t\tDuracion: "<< duracion;
                baseDatos>>numSerie>>nombre>>clasif>>duracion;
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU PELICULAS--";
            cout<<"\n\t";system("pause");
            return menuPeliculas();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}


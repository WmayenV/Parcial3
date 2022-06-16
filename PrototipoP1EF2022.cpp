#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
//#include <windows.h>//
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
    void registrarSalas();
    void modificarSalas();
    void eliminarSalas();
    void mostrarSalas();
    void menuAsientos();
    void registrarAsientos();
    void modificarAsientos();
    void eliminarAsientos();
    void mostrarAsientos();
    void menuCines();
    void registrarCines();
    void modificarCines();
    void eliminarCines();
    void mostrarCines();
    void menuClientes();
    void registrarClientes();
    void modificarClientes();
    void eliminarClientes();
    void mostrarClientes();

private:
    string desicion, numSerie, nombre, clasif, duracion, baseDatos, busquedaDatos, modBaseDatos, numSal, nivel, numAsientos, numeroAs, estado, idCines, direccion, estadoCines, idClientes, nomClientes, nomPelis ;
};

// inicio Menu General //

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
//fin menu General //

//inicio menu pelicualas//
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
        cout << "\n\tSaliendo al --MENU General--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
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
                return mostrarPeliculas();
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
//fin menu peliculas //

//inicio menu salas
void cinema::menuSalas(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU SALAS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar sala\n" << "\t\t[2] Modificar sala\n" <<  "\t\t[3] Eliminar sala\n" << "\t\t[4] Mostrar sala\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarSalas();
        break;
    case 2:
        modificarSalas();
        break;
    case 3:
        eliminarSalas();
        break;
    case 4:
        mostrarSalas();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU General--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void cinema::registrarSalas(){
    system("cls");
    cout << "\n\t\t\tEntrando al menu --REGISTRAR Salaw--\n" << endl;
    cout << "\n\t�Quires salir al --MENU Salas--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuSalas();
    }
    else {
        cout << "\n\t\tIngrese el numero de sala: "; cin >> numSal;
        cout << "\t\tIngrese el nivel de la sala a registrar: "; cin >> nivel;
        cout << "\t\tIngrese cantidad de asietos habiles de la sala: "; cin >> numAsientos;
        cout << "\n\t--Registro de pelicula completado--\n" << endl;
        //baseDatos.open("salas.dat",ios::app | ios::out | ios::binary);
       // baseDatos<<std::left<<std::setw(15)<< numSal <<std::left<<std::setw(15)<< nivel <<std::left<<std::setw(15)<< numAsientos <<"\n";
        //baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU Salas--";
    cout<<"\n\t";system("pause");
    return menuSalas();
}

void cinema::modificarSalas(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR Salas-" << endl;
    baseDatos.open("salas.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU Salas--";
        cout<<"\n\t";system("pause");
        return menuSalas();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de la sala que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalSalas.dat",ios::out|ios::binary);
        baseDatos>>numSal>>nivel>>numAsientos;
        while (!baseDatos.eof()){
            if (busquedaDatos!=numSal){
                modBaseDatos <<std::left<<std::setw(15)<< numSal <<std::left<<std::setw(15)<< nivel <<std::left<<std::setw(15)<< numAsientos <<"\n";
            }
            else {
                 cout << "\n\t\tIngrese el numero de sala: "; cin >> numSal;
                cout << "\t\tIngrese el nivel de la sala a registrar: "; cin >> nivel;
                cout << "\t\tIngrese cantidad de asietos habiles de la sala: "; cin >> numAsientos;
                modBaseDatos <<std::left<<std::setw(15)<< numSal <<std::left<<std::setw(15)<< nivel <<std::left<<std::setw(15)<< numAsientos<<"\n";
            }
            baseDatos>>numSal>>nivel>>numAsientos;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "salas.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalSalas.dat","salas.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU Salas--";
    cout<<"\n\t";system("pause");
    return menuSalas();
}

void cinema::eliminarSalas(){
    system("cls");
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR Salaws-" << endl;
//	baseDatos.open("salas.dat",ios::in|ios::binary);
//    if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
//		baseDatos.close();
	}
	//else
	{
		cout << "\n\t\tIngrese el numero de sala que busca: "; cin >> busquedaDatos;
		//modBaseDatos.open("temporalPeliculas.dat", ios::app | ios::out | ios::binary);
		//baseDatos>>numSerie>>nombre>>clasif>>duracion;
		//while(!baseDatos.eof())
		{
			if(busquedaDatos!=numSal)
			{
				//modBaseDatos <<std::left<<std::setw(15)<< numSal <<std::left<<std::setw(15)<< nivel <<std::left<<std::setw(15)<< numAsientos <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			//baseDatos>>numSal>>nivel>>numAsientos>>;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Sala no encontrada...\a";
		}
//		baseDatos.close();
//		modBaseDatos.close();
//    if (baseDatos.is_open())
//        baseDatos.close();
 //   if (modBaseDatos.is_open())
 //       modBaseDatos.close();

    if( remove( "salas.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalSalas.dat","salas.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU SALA--";
    cout<<"\n\t";system("pause");
    return menuSalas();
}

void cinema::mostrarSalas(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR Salas--";
    cout << "\n\n\t\t�Quiere buscar una Sala en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("salas.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR Salas--"<<endl;
            cout << "\n\t\tIngrese el numero de la  sala a buscar: "; cin >> numSal;
            baseDatos>>numSal>>nivel>>numAsientos;
            while(!baseDatos.eof()){
                if(busquedaDatos==numSal){
                    cout<<"\n\t\tnumero de sala: "<< numSal;
                    cout<<"\n\t\tNivel: " << nivel;
                    cout<<"\n\t\tAsientos habiles: "<< numAsientos;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU Salas--";
                    cout<<"\n\t";system("pause");
                    return menuSalas();
                }
                baseDatos>>numSal>>nivel>>numAsientos;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR Salas--";
                cout<<"\n\t";system("pause");
                return mostrarSalas();
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
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR Salas"<<endl;
        baseDatos.open("salas.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU Salas--";
            cout<<"\n\t";system("pause");
            return menuSalas();
        }
        else
        {
            baseDatos>>numSal>>nivel>>numAsientos;
            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\n\t\tNUmero de sala: "<< numSal;
                cout<<"\n\t\tNivel: " << nivel;
                cout<<"\n\t\Asientos habiles: "<< numAsientos;
                baseDatos>>numSal>>nivel>>numAsientos>>duracion;
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
            cout <<"\n\n\t\tRegresando al --MENU Salas--";
            cout<<"\n\t";system("pause");
            return menuSalas();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}
//fin menu salas //

// inicio menu asientos//
void cinema::menuAsientos(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU Asientos--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar asiento\n" << "\t\t[2] Modificar asiento\n" <<  "\t\t[3] Eliminar asientos\n" << "\t\t[4] Mostrar asientos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarAsientos();
        break;
    case 2:
        modificarAsientos();
        break;
    case 3:
        eliminarAsientos();
        break;
    case 4:
        mostrarAsientos();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU General--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void cinema::registrarAsientos(){
    system("cls");
    cout << "\n\t\t\tEntrando al menu --REGISTRAR ASiento--\n" << endl;
    cout << "\n\t�Quires salir al --MENU asientos--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuAsientos();
    }
    else {
        cout << "\n\t\tIngrese el numero de asiento: "; cin >> numeroAs;
        cout << "\t\tIngrese el estado del asiento a registrar: "; cin >> estado;
        cout << "\n\t--Registro de pelicula completado--\n" << endl;
        //baseDatos.open("asientos.dat",ios::app | ios::out | ios::binary);
       // baseDatos<<std::left<<std::setw(15)<< numeroAs <<std::left<<std::setw(15)<< estado<<"\n";
        //baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU Asientos--";
    cout<<"\n\t";system("pause");
    return menuAsientos();
}

void cinema::modificarAsientos(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR Asientos-" << endl;
    baseDatos.open("asientos.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU Asienots--";
        cout<<"\n\t";system("pause");
        return menuAsientos();
    }
    else {
        cout << "\n\t\t\tIngrese el numero del asiento que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalAsientos.dat",ios::out|ios::binary);
        baseDatos>>numeroAs>>estado;
        while (!baseDatos.eof()){
            if (busquedaDatos!=numeroAs){
                modBaseDatos <<std::left<<std::setw(15)<< numeroAs <<std::left<<std::setw(15)<< estado <<"\n";
            }
            else {
                 cout << "\n\t\tIngrese el numero de asiento: "; cin >> numeroAs;
                cout << "\t\tIngrese el estado del asiento a registrar: "; cin >> estado;
                modBaseDatos <<std::left<<std::setw(15)<< numeroAs <<std::left<<std::setw(15)<< estado <<"\n";
            }
            baseDatos>>numeroAs>>estado;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "asientos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalAsientos.dat","asientos.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU Asientos--";
    cout<<"\n\t";system("pause");
    return menuAsientos();
}

void cinema::eliminarAsientos(){
    system("cls");
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR Asientos-" << endl;
//	baseDatos.open("asientos.dat",ios::in|ios::binary);
//    if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
//		baseDatos.close();
	}
	//else
	{
		cout << "\n\t\tIngrese el numero asiento que busca: "; cin >> busquedaDatos;
		//modBaseDatos.open("temporalAsientos.dat", ios::app | ios::out | ios::binary);
		//baseDatos>>numeroAs>>estado>>;
		//while(!baseDatos.eof())
		{
			if(busquedaDatos!=numeroAs)
			{
				//modBaseDatos <<std::left<<std::setw(15)<< numeroAs <<std::left<<std::setw(15)<< estado<<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			//baseDatos>>numeroAs>>estado>>;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t asiento no encontrado...\a";
		}
//		baseDatos.close();
//		modBaseDatos.close();
//    if (baseDatos.is_open())
//        baseDatos.close();
 //   if (modBaseDatos.is_open())
 //       modBaseDatos.close();

    if( remove( "asientos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalAsientos.dat","asientos.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU Asientos--";
    cout<<"\n\t";system("pause");
    return menuAsientos();
}

void cinema::mostrarAsientos(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR Asientos--";
    cout << "\n\n\t\t�Quiere buscar un asiento en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("asientos.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR asiento--"<<endl;
            cout << "\n\t\tIngrese el numero del asiento a buscar: "; cin >> numeroAs;
            baseDatos>>numeroAs>>estado;
            while(!baseDatos.eof()){
                if(busquedaDatos==numeroAs){
                    cout<<"\n\t\tnumero de asiento: "<< numeroAs;
                    cout<<"\n\t\tEstado: " << estado;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU Asientos--";
                    cout<<"\n\t";system("pause");
                    return menuAsientos();
                }
                baseDatos>>numeroAs>>estado;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR Asientos--";
                cout<<"\n\t";system("pause");
                return mostrarAsientos();
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
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR Asientos"<<endl;
        baseDatos.open("asientos.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU Asientos--";
            cout<<"\n\t";system("pause");
            return menuAsientos();
        }
        else
        {
            baseDatos>>numeroAs>>estado;
            while(!baseDatos.eof())
            {
                total++;
                    cout<<"\n\t\tnumero de asiento: "<< numeroAs;
                    cout<<"\n\t\tEstado: " << estado;
                baseDatos>>numeroAs>>estado;
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
            cout <<"\n\n\t\tRegresando al --MENU Salas--";
            cout<<"\n\t";system("pause");
            return menuSalas();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}
void cinema::menuCines(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU CINES--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar cine\n" << "\t\t[2] Modificar cine\n" <<  "\t\t[3] Eliminar cine\n" << "\t\t[4] Mostrar cines\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarCines();
        break;
    case 2:
        modificarCines();
        break;
    case 3:
        eliminarCines();
        break;
    case 4:
        mostrarCines();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU General--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}
// fin menu asientos//

//inicio menu cines//
void cinema::registrarCines(){
    system("cls");
    cout << "\n\t\t\tEntrando al menu --REGISTRAR Cines--\n" << endl;
    cout << "\n\t�Quires salir al --MENU Cines--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuCines();
    }
    else {
        cout << "\n\t\tIngrese el numero de identificacion del cine: "; cin >> idCines;
        cout << "\n\t\tIngrese la direccion del cine: "; cin >> direccion;
        cout << "\t\tIngrese el estado del cine a registrar: "; cin >> estadoCines;
        cout << "\n\t--Registro de pelicula completado--\n" << endl;
        //baseDatos.open("cines.dat",ios::app | ios::out | ios::binary);
       // baseDatos<<std::left<<std::setw(15)<< idCines <<std::left<<std::setw(15)<< direccion<<<<std::left<<std::setw(15)<< estadoCines"\n";
        //baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU Cines--";
    cout<<"\n\t";system("pause");
    return menuCines();
}

void cinema::modificarCines(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR Cines-" << endl;
    baseDatos.open("cines.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU Cines--";
        cout<<"\n\t";system("pause");
        return menuCines();
    }
    else {
        cout << "\n\t\t\tIngrese el numero del cine que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalCines.dat",ios::out|ios::binary);
        baseDatos>>numeroAs>>estado;
        while (!baseDatos.eof()){
            if (busquedaDatos!=idCines){
                modBaseDatos <<std::left<<std::setw(15)<< idCines <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<<estadoCines<<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de identificacion del cine: "; cin >> idCines;
                cout << "\n\t\tIngrese la direccion del cine: "; cin >> direccion;
                cout << "\t\tIngrese el estado del cine a registrar: "; cin >> estadoCines;
                modBaseDatos <<std::left<<std::setw(15)<< idCines <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<<estadoCines<<"\n";
            }
            baseDatos>>idCines>>direccion>>estadoCines;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "cines.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalCines.dat","cines.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU Cines--";
    cout<<"\n\t";system("pause");
    return menuCines();
}

void cinema::eliminarCines(){
    system("cls");
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR Cines-" << endl;
//	baseDatos.open("cines.dat",ios::in|ios::binary);
//    if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
//		baseDatos.close();
	}
	//else
	{
		cout << "\n\t\tIngrese el numero del cine que busca: "; cin >> busquedaDatos;
		//modBaseDatos.open("temporalCines.dat", ios::app | ios::out | ios::binary);
		//baseDatos>>idCines>>direccion>>estadoCines>>;
		//while(!baseDatos.eof())
		{
			if(busquedaDatos!=numeroAs)
			{
				//modBaseDatos <<std::left<<std::setw(15)<< idCines <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<<estadoCines<<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			//baseDatos>>idCines>>direccion>>estadoCines>>;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Cince no encontrado...\a";
		}
//		baseDatos.close();
//		modBaseDatos.close();
//    if (baseDatos.is_open())
//        baseDatos.close();
 //   if (modBaseDatos.is_open())
 //       modBaseDatos.close();

    if( remove( "cines.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalCines.dat","cines.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU Cines--";
    cout<<"\n\t";system("pause");
    return menuCines();
}

void cinema::mostrarCines(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR Cines--";
    cout << "\n\n\t\t�Quiere buscar un Cine en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("cine.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR cine--"<<endl;
            cout << "\n\t\tIngrese el numero del cine a buscar: "; cin >> idCines;
            baseDatos>>idCines>>direccion>>estadoCines;
            while(!baseDatos.eof()){
                if(busquedaDatos==idCines){
                    cout<<"\n\t\tnumero de Cine: "<< idCines;
                    cout<<"\n\t\tDireccion: " << direccion;
                    cout<<"\n\t\testado: " << estadoCines;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU cines--";
                    cout<<"\n\t";system("pause");
                    return menuCines();
                }
                baseDatos>>idCines>>direccion>>estadoCines;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR Cines--";
                cout<<"\n\t";system("pause");
                return mostrarCines();
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
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR Cines"<<endl;
        baseDatos.open("cines.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU Cines--";
            cout<<"\n\t";system("pause");
            return menuCines();
        }
        else
        {
            baseDatos>>idCines>>direccion>>estadoCines;
            while(!baseDatos.eof())
            {
                total++;
                    cout<<"\n\t\tnumero de cine: "<< idCines;
                    cout<<"\n\t\tDireccion: " << direccion;
                    cout<<"\n\t\tEstado: " << estadoCines;
                baseDatos>>idCines>>direccion>>estadoCines;
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
            cout <<"\n\n\t\tRegresando al --MENU Cines--";
            cout<<"\n\t";system("pause");
            return menuCines();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}
//fin menu cines//
void cinema::menuClientes(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU Clietnes--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar clientes\n" << "\t\t[2] Modificar clientes\n" <<  "\t\t[3] Eliminar clientes\n" << "\t\t[4] Mostrar clientes\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarClientes();
        break;
    case 2:
        modificarClientes();
        break;
    case 3:
        eliminarClientes();
        break;
    case 4:
        mostrarClientes();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU General--" << endl;
        cout<<"\t";system ("pause");
        return menuGeneral();
        break;
    }
}

void cinema::registrarClientes(){
    system("cls");
    cout << "\n\t\t\tEntrando al menu --REGISTRAR Clientes--\n" << endl;
    cout << "\n\t�Quires salir al --MENU Clientes--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuClientes();
    }
    else {
        cout << "\n\t\tIngrese el numero de identificacion del cliente: "; cin >> idClientes;
        cout << "\n\t\tIngrese nombre del cliente: "; cin >> nomClientes;
        cout << "\t\tIngrese el nombre de la pelicula que vera: "; cin >> nomPelis;
        cout << "\n\t--Registro de pelicula completado--\n" << endl;
        //baseDatos.open("cines.dat",ios::app | ios::out | ios::binary);
       // baseDatos<<std::left<<std::setw(15)<< idClientes <<std::left<<std::setw(15)<< nomClientes<<<<std::left<<std::setw(15)<< nomPelis"\n";
        //baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU Clientes--";
    cout<<"\n\t";system("pause");
    return menuClientes();
}

void cinema::modificarClientes(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR Clientes-" << endl;
    baseDatos.open("clientes.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU clientes--";
        cout<<"\n\t";system("pause");
        return menuClientes();
    }
    else {
        cout << "\n\t\t\tIngrese el numero del cliente que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalClientes.dat",ios::out|ios::binary);
        baseDatos>>idClientes>>nomClientes>>nomPelis;
        while (!baseDatos.eof()){
            if (busquedaDatos!=idCines){
                modBaseDatos <<std::left<<std::setw(15)<< idClientes <<std::left<<std::setw(15)<< nomClientes <<std::left<<std::setw(15)<<nomPelis<<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de identificacion del cliente: "; cin >> idClientes;
                cout << "\n\t\tIngrese nombre del cliente: "; cin >> nomClientes;
                cout << "\t\tIngrese el nombre de la pelicula que vera: "; cin >> nomPelis;
                modBaseDatos <<std::left<<std::setw(15)<< idClientes <<std::left<<std::setw(15)<< nomClientes <<std::left<<std::setw(15)<<nomPelis<<"\n";
            }
            baseDatos>>idClientes>>nomClientes>>nomPelis;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "clientes.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalClientes.dat","clientes.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU Clientes--";
    cout<<"\n\t";system("pause");
    return menuClientes();
}

void cinema::eliminarClientes(){
    system("cls");
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR Clientes-" << endl;
//	baseDatos.open("clientes.dat",ios::in|ios::binary);
//    if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
//		baseDatos.close();
	}
	//else
	{
		cout << "\n\t\tIngrese el numero del cliente que busca: "; cin >> busquedaDatos;
		//modBaseDatos.open("temporalClientes.dat", ios::app | ios::out | ios::binary);
		//baseDatos>>idClientes>>nomClientes>>nomPelis;
		//while(!baseDatos.eof())
		{
			if(busquedaDatos!=numeroAs)
			{
				//modBaseDatos <<std::left<<std::setw(15)<< idClientes <<std::left<<std::setw(15)<< nomClientes <<std::left<<std::setw(15)<<nomPelis<<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			//baseDatos>>idClientes>>nomClientes>>nomPelis;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Cince no encontrado...\a";
		}
//		baseDatos.close();
//		modBaseDatos.close();
//    if (baseDatos.is_open())
//        baseDatos.close();
 //   if (modBaseDatos.is_open())
 //       modBaseDatos.close();

    if( remove( "clientes.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalClientes.dat","clientes.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU clientes--";
    cout<<"\n\t";system("pause");
    return menuClientes();
}

void cinema::mostrarClientes(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR Clientes--";
    cout << "\n\n\t\t�Quiere buscar un cliente en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("cliente.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR cliente--"<<endl;
            cout << "\n\t\tIngrese el numero del cin a buscar: "; cin >> idCines;
            baseDatos>>idClientes>>nomClientes>>nomPelis;
            while(!baseDatos.eof()){
                if(busquedaDatos==idCines){
                    cout<<"\n\t\tnumero del cliente: "<< idClientes;
                    cout<<"\n\t\tNombre del cliente: " << nomClientes;
                    cout<<"\n\t\tNombre de la pelicula: " << nomPelis;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU clientes--";
                    cout<<"\n\t";system("pause");
                    return menuClientes();
                }
                baseDatos>>idClientes>>nomClientes>>nomPelis;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR Clienes--";
                cout<<"\n\t";system("pause");
                return mostrarCines();
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
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR Clientes"<<endl;
        baseDatos.open("clientes.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU Clientes--";
            cout<<"\n\t";system("pause");
            return menuClientes();
        }
        else
        {
            baseDatos>>idClientes>>nomClientes>>nomPelis;
            while(!baseDatos.eof())
            {
                total++;
                    cout<<"\n\t\tnumero del cliente: "<< idClientes;
                    cout<<"\n\t\tNombre del cliente: " << nomClientes;
                    cout<<"\n\t\tNombre de la pelicula: " << nomPelis;
                baseDatos>>idClientes>>nomClientes>>nomPelis;
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
            cout <<"\n\n\t\tRegresando al --MENU Clientes--";
            cout<<"\n\t";system("pause");
            return menuCines();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
};
//seguridad//
/*int main(){
    system ("cls");
    string usuario, contrasena, config1, config2;
    fstream usuariosContrasenas;
    usuariosContrasenas.open("seguridad.dat",ios::app|ios::in|ios::binary);
    if(!usuariosContrasenas){
        cout<<"\n\t\tError\a";
        cout<<"\n\t\tNo se encontro el archivo\a";
    }
    else{
        cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
        cout << "\n\t\tIngrese su contrasena: "; cin >> contrasena;
        usuariosContrasenas>>config1>>config2;
            if (usuario=="William" && contrasena =="101"){
                fstream bienvenida;
                string line, desicion;
                bienvenida.open("welcome.txt");
                if(bienvenida.is_open()){
                    cout << "\n";
                    while( getline(bienvenida, line)){
                        cout << "\t\t"<<line << endl;
                    }
                    bienvenida.close();
                    }
                cout << "\n\t\tPresione e para ingresar al --PROGRAMA-- : ";cin>>desicion;
                if (desicion=="e"){
                cinema peliculas;
               peliculas.menuGeneral();
            }
            else{
                cout << "\n\t\t\tPermiso denegado\a";
                exit(0);
            }
        }
    }
}*/


#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <cstring>


using namespace std;
const char *nombe_archivo = "archivo.dat";


typedef struct {
	char palabra[30];
	char traduccion[30];
	char definicion[300];
	int borrar=0;
	
	
}Palabra;

void ingresar();
void leer();
void actualizar();
void eliminar();
void leerlista();
void codigo();

main (){
	int opcion;
	do{
		system("cls");
	cout<<"PROYECTO TRADUCTOR C++"<<endl;
	cout<<"----------------------"<<endl;
	cout<<"QUE DESEA HACER: "<<endl<<endl;
	cout<<"1 INGRESAR DATOS\n2 LEER DATO\n3 ACTUALIZAR DATOS\n4 ELIMINAR DATOS\n5 LEER LISTA DE DATOS COMPLETA\n6(pendiente) TRADUCIR CODIGO\n7 SALIR\n";
	cin>>opcion;
	switch (opcion){
	case 1:
		ingresar();
		break;
	case 2:
		leer();
		break;
	case 3:
		actualizar();
		break;
	case 4:
		eliminar();
		break;
	case 5:
		leerlista();
		break;
	case 6:
		codigo();
		break;
	case 7:
	    return 0;
	    break;
		}
}while(opcion>7);
return 0;
}


void ingresar(){
		system("cls");
	FILE* archivo = fopen(nombe_archivo, "ab");
	if(archivo==NULL) {		
		archivo = fopen(nombe_archivo, "w+b");
	}
	Palabra palabra;
	string pal,trad,def;
	char otra;
	do{
	cout<<"INGRESE LA INFORMACION QUE SE LE SOLICITA: "<<endl<<endl;
		fflush(stdin);
	cout<<"PALABRA: ";
	getline(cin,pal);
	strcpy(palabra.palabra,pal.c_str());
	
	cout<<"TRADUCCION: ";
	getline(cin,trad);
	strcpy(palabra.traduccion,trad.c_str());
	
	cout<<"DEFINICION: ";
	getline(cin,def);
	strcpy(palabra.definicion,def.c_str());
	palabra.borrar==0;
	
	fwrite(&palabra,sizeof(Palabra),1,archivo);
	
	cout<<"DESEA AGREGAR OTRA PALABRA RESERVADA [S/N] ";
	cin>>otra;
	
	} while((otra=='s') || (otra=='S') );
	
	fclose(archivo);
	main();
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	int pos=0,indice=0;
	bool existe=false;
	string pal;
	char p[30];
	cout<<"INGRESE PALABRA RESERVADA"<<endl;
	fflush(stdin);
	getline(cin,pal);
	strcpy(p,pal.c_str());
	
	Palabra palabra;
	fread(&palabra,sizeof(Palabra),1,archivo);	
	do{
    	int x=strcmp(p,palabra.palabra);	
		if(x==0){
			pos=indice;
			existe=true;
		}
	fread(&palabra,sizeof(Palabra),1,archivo);	
	indice++;
	}while (feof( archivo ) == 0);
	
	if(existe==true){
	fseek ( archivo,pos * sizeof(Palabra), SEEK_SET );

    fread ( &palabra, sizeof(Palabra), 1, archivo );
    cout<<"PALABRA:   \t"<<palabra.palabra<<endl;
    cout<<"TRADUCCION:\t"<<palabra.traduccion<<endl;
    cout<<"DEFINICION:\t"<<palabra.definicion<<endl;
    cout<<"---------------------------------------\n";
}
else{
	cout<<"NO SE ENCONTRO LA PALABRA, PORFAVOR INGRESAR PALABRA RESPETANDO MAYUSCULAS, MINUSCULAS Y ESPACIOS"<<endl;
}
	fclose(archivo);
	system("PAUSE");
	main();
	
}
void actualizar(){
FILE* archivo = fopen(nombe_archivo, "r+b");
    Palabra palabra;
    int pos=0,indice=0;
	bool existe=false;
	string pal,trad,def;
	char p[30];
	
	cout<<"INGRESE PALABRA RESERVADA"<<endl;
	fflush(stdin);
	getline(cin,pal);
	strcpy(p,pal.c_str());
	
	fread(&palabra,sizeof(Palabra),1,archivo);	
	do{
    	int x=strcmp(p,palabra.palabra);	
		if(x==0){
			pos=indice;
			existe=true;
		}
	fread(&palabra,sizeof(Palabra),1,archivo);	
	indice++;
	}while (feof( archivo ) == 0);
	
	if(existe==true){
	fseek ( archivo,pos * sizeof(Palabra), SEEK_SET );

    fread ( &palabra, sizeof(Palabra), 1, archivo );
    cout<<"PALABRA:   \t"<<palabra.palabra<<endl;
    cout<<"TRADUCCION:\t"<<palabra.traduccion<<endl;
    cout<<"DEFINICION:\t"<<palabra.definicion<<endl;
    cout<<"---------------------------------------\n";
    fseek ( archivo,pos * sizeof(Palabra), SEEK_SET );
    cout<<"INGRESE LA INFORMACION QUE SE LE SOLICITA: "<<endl<<endl;
		fflush(stdin);
	cout<<"PALABRA: ";
	getline(cin,pal);
	strcpy(palabra.palabra,pal.c_str());
	
	cout<<"TRADUCCION: ";
	getline(cin,trad);
	strcpy(palabra.traduccion,trad.c_str());
	
	cout<<"DEFINICION: ";
	getline(cin,def);
	strcpy(palabra.definicion,def.c_str());
	palabra.borrar==0;
	
	fwrite(&palabra,sizeof(Palabra),1,archivo);
	cout<<"REGISTRO MODIFICADO"<<endl;
    
}
else{
	cout<<"NO SE ENCONTRO LA PALABRA, PORFAVOR INGRESAR PALABRA RESPETANDO MAYUSCULAS, MINUSCULAS Y ESPACIOS"<<endl;
}
	fclose(archivo);
	system("PAUSE");
	main();
	
	
}
void eliminar(){
}
void leerlista(){
}
void codigo(){
}


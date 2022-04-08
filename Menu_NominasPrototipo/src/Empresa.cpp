#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include "Empresa.h"
using namespace std;

//Metodos de clase Empresa (menu Empresa)
Empresa::insertE()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Informacion Empresa ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Nombre de la Empresa         : ";
	cin>>nameE;
	cout<<"\t\t\tIngresa Actividad Economica    : ";
	cin>>ecoActivity;
	cout<<"\t\t\tIngresa Correo Electronico  : ";
	cin>>mail;
	cout<<"\t\t\tIngresa Nombre del Gerente o Representante legal: ";
	cin>>nameR;
	cout<<"\t\t\tIngresa No.de nit  : ";
	cin>>nit;
	cout<<"\t\t\tIngresa Direccion de la Empresa  : ";
	cin>>address;
	cout<<"\t\t\tIngresa No.de Telefono  : ";
	cin>>phone;
	cout<<"\t\t\tIngresa No.de trabajadores  : ";
	cin>>staffNumber;
	cout<<"\t\t\tIngresa No.de Empresa  : ";
	cin>>companyNumber;
	file.open("datosEmpresa.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< nameE <<std::left<<std::setw(15)<< ecoActivity <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< nameR <<std::left<<std::setw(15)<< nit <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< phone << std::left<<std::setw(15)<< staffNumber <<std::left<<std::setw(15)<< companyNumber <<"\n";
	file.close();
}


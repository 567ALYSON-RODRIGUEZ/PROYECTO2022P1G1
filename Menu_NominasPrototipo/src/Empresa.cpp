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

Empresa::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Informacion de Empresa -------------------------"<<endl;
	file.open("datosEmpresa.txt",ios::in| ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre Empresa: "<<nameE<<endl;
			cout<<"\t\t\t Actividad Economica: "<<ecoActivity<<endl;
			cout<<"\t\t\t Correo Empresa: "<<mail<<endl;
			cout<<"\t\t\t Gerente/Representante legal: "<<nameR<<endl;
			cout<<"\t\t\t Direccion: "<<address<<endl;
			cout<<"\t\t\t No.telefono: "<<phone<<endl;
			cout<<"\t\t\t No.de empleados: "<<staffNumber<<endl;
			cout<<"\t\t\t No.de Empresa "<<companyNumber<<endl;
			file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	}
}

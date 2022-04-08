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

Empresa::menu()
{
    Empresa mostrarE;
    Empresa modificarE;
    Empresa buscarE;
    Empresa borrarE;
    int choice2;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION EMPRESA |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Empresa"<<endl;
	cout<<"\t\t\t 2. Despliegue Empresa"<<endl;
	cout<<"\t\t\t 3. Modifica Empresa"<<endl;
	cout<<"\t\t\t 4. Busca Empresa"<<endl;
	cout<<"\t\t\t 5. Borra Empresa"<<endl;
	cout<<"\t\t\t 6. Volver al menu superior"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice2;

    switch(choice2)
    {
	case 1:
		mostrarE.display();
		getch();
		break;
	case 2:
		modificarE.modify();
		getch();
		break;
	case 3:
		buscarE.searchE();
		getch();
		break;
	case 4:
		borrarE.deletE();
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
	//getch();
    }while(choice2!= 5);
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

Empresa::modify()
{
	system("cls");
	fstream file,file1;
	int numero_Empresa;
	int found=0;
	cout<<"\n-------------------------Modificacion Datos de Empresa-------------------------"<<endl;
	file.open("datosEmpresa.txt",ios::in| ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el numero de empresa que desea modificar: ";
		cin>>numero_Empresa;
		file1.open("RegistroDatosEmpresa.txt",ios::app | ios::out| ios::binary);
		file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		while(!file.eof())
		{
			if(numero_Empresa!=companyNumber)
			{
            file1<<std::left<<std::setw(15)<< nameE <<std::left<<std::setw(15)<< ecoActivity <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< nameR <<std::left<<std::setw(15)<< nit <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< phone << std::left<<std::setw(15)<< staffNumber <<std::left<<std::setw(15)<< companyNumber <<"\n";
			}
			else
			{
			    cout<<"\t\t\tIngresa Nombre de la Empresa: ";
                cin>>nameE;
                cout<<"\t\t\tIngresa Actividad Economica: ";
                cin>>ecoActivity;
                cout<<"\t\t\tIngresa Correo Electronico: ";
                cin>>mail;
                cout<<"\t\t\tIngresa Nombre del Gerente o Representante legal: ";
                cin>>nameR;
                cout<<"\t\t\tIngresa No.de nit: ";
                cin>>nit;
                cout<<"\t\t\tIngresa Direccion de la Empresa: ";
                cin>>address;
                cout<<"\t\t\tIngresa No.de Telefono: ";
                cin>>phone;
                cout<<"\t\t\tIngresa No.de trabajadores: ";
                cin>>staffNumber;
	            cout<<"\t\t\tIngresa No.de Empresa: ";
                cin>>companyNumber;
				file1<<std::left<<std::setw(15)<< nameE <<std::left<<std::setw(15)<< ecoActivity <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< nameR <<std::left<<std::setw(15)<< nit <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< phone << std::left<<std::setw(15)<< staffNumber <<std::left<<std::setw(15)<< companyNumber <<"\n";
				found++;
			}
			file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;

		}
		file1.close();
		file.close();
		remove("datosEmpresa.txt");
		rename("RegistroDatosEmpresa.txt","datosEmpresa.txt");
	}
}

Empresa::searchE()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("datosEmpresa.txt",ios::in| ios::binary);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Empresa buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		int numero_EmpresaN;
		cout<<"\n-------------------------Datos de la Empresa buscada------------------------"<<endl;
		cout<<"\nIngrese el numero de empresa que desea modificar: ";
		cin>>numero_EmpresaN;
		file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		while(!file.eof())
		{
			if(numero_EmpresaN==companyNumber)
			{
				cout<<"\n\n\t\t\t Nombre Empresa: "<<nameE<<endl;
                cout<<"\t\t\t Actividad Economica: "<<ecoActivity<<endl;
                cout<<"\t\t\t Correo Empresa: "<<mail<<endl;
                cout<<"\t\t\t Gerente/Representante legal: "<<nameR<<endl;
                cout<<"\t\t\t Direccion: "<<address<<endl;
                cout<<"\t\t\t No.telefono: "<<phone<<endl;
                cout<<"\t\t\t No.de empleados: "<<staffNumber<<endl;
                cout<<"\t\t\t No.de Empresa "<<companyNumber<<endl;
				found++;
			}
			file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empresa no encontrada...";
		}
		file.close();
	}
}

Empresa::deletE()
{
	system("cls");
	fstream file,file1;
	int numero_EmpresaN;
	int found=0;
	cout<<"\n-------------------------Detalles Empresa a Borrar-------------------------"<<endl;
	file.open("datosEmpresa.txt",ios::in| ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el DPI del Empleado que quiere borrar: ";
		cin>>numero_EmpresaN;
		file1.open("RegistroDatosEmpresa.txt",ios::app | ios::out | ios::binary);
		file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		while(!file.eof())
		{
			if(numero_EmpresaN!= companyNumber)
			{
				file1<<std::left<<std::setw(15)<< nameE <<std::left<<std::setw(15)<< ecoActivity <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< nameR <<std::left<<std::setw(15)<< nit <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< phone << std::left<<std::setw(15)<< staffNumber <<std::left<<std::setw(15)<< companyNumber <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> nameE >> ecoActivity >> mail >> nameR >> nit >> address >> phone >> staffNumber >> companyNumber ;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t DPI Empresa no encontrada...";
			getch();
		}
		file1.close();
		file.close();
		remove("datosEmpresa.txt");
		rename("RegistroDatosEmpresa.txt","datosEmpresa.txt");
	}
}




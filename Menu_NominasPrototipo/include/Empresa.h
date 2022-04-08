#include<cstring>
#ifndef EMPRESA_H
#define EMPRESA_H
using namespace std;


class Empresa
{
public:
    display();
    insertE();
    ingresarE();
    menu();
    modify();
    searchE();
    deletE();

    private:
        string nameE,mail,nameR,ecoActivity;
        long int nit,address,phone;
        int staffNumber, companyNumber;
};


#endif // EMPRESA_H

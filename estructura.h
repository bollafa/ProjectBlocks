#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

    # define MAXCLIENTES 100
    # define MAXDNI 10
    # define MAXNUMCUENTA 11
    # define MAXNOMBRE 50
    # define MAXDOMICILIO 50
    # define MAXTIPOCUENTA 10
    # define MAXMES 11
    struct data {
        unsigned int dia;
        unsigned int mes;
        unsigned int anho;
    };

    struct Cliente {
        char nombre [ MAXNOMBRE ];
        char DNI [ MAXDNI ];
        char domicilio [ MAXDOMICILIO ];
        char numCuenta [ MAXNUMCUENTA ];
        char tipoCuenta [ MAXTIPOCUENTA ];
        data fecha;
    };

    struct setClientes {
        Cliente Clientes[ MAXCLIENTES ];  // Array donde almacenamos todos los clientes
        int numClientes;  // Número total de clientes existentes en el vector clientes
    };


struct cuenta{
char tipoCuenta[MAXTIPOCUENTA];
int id ;
};

#endif // ESTRUCTURA_H_INCLUDED

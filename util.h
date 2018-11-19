#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

/*
        Lee cadenas y números por teclado
*/

    # include <iostream>
    # include <cstdlib>

    # define MAXCAD 200 //Dimension maxima de las cadenas de caracteres

    using namespace std;
vg
    void leerCadena(char mensaje[ ], char cad []);
    int leerEntero(char mensaje []);

#endif // UTIL_H_INCLUDED

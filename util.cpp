/*
	Lee cadenas y números por teclado
*/

# include <iostream>
# include <cstdlib>

# include "util.h"

void leerCadena(char mensaje[ ], char cad []) {

	cout << mensaje;
	cin.getline(cad, MAXCAD-1);
}

int leerEntero(char mensaje []) {

	char cad [MAXCAD];

	leerCadena( mensaje, cad );
	return atoi( cad );
}

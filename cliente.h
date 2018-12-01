#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

# include "estructura.h"

    // Declaraciones de las funciones necesarias específicas para gestionar paciemtes
    // Los prototipos proporcionados pueden ser modificados en sus argumentos y en el tipo de dato devuelto

void listarClientes ( setClientes& variosClientes );
void addCliente(setClientes varios);

void mostrarCliente ( Cliente elCliente );
void removeClient(setClientes& clientes, int id);
void ListarDNIErroneos(const setClientes& clientes);
void BuscarPorDNI3(const setClientes& clientes, const char DNI[MAXDNI]);
void BuscarPorNCuenta(const setClientes& clientes, const char numCuenta[MAXDNI]);
void BuscarPorDNI(const setClientes& clientes,unsigned int &id);
void menuDeModificacion(unsigned int &modificacion);
void selectorDeModificacion(setClientes &variosClientes, unsigned int &modificacion, unsigned int id);
bool verificadorDNI (setClientes variosClientes, char DNI[]);
bool verificadorvalidezNumCuenta (char numCuenta[]);
bool verificadorExistenciaNumCuenta (setClientes variosClientes, char numCuenta[]);
bool verificadorMes(char mes[], unsigned int &mesNum);
bool verificadorDia(unsigned int dia, unsigned int mesNum,unsigned int anho);
bool verificadorAnho(unsigned int anho);

#endif // UTIL_H_INCLUDED

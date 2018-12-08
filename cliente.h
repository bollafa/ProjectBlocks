#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

# include "estructura.h"

    // Declaraciones de las funciones necesarias específicas para gestionar paciemtes
    // Los prototipos proporcionados pueden ser modificados en sus argumentos y en el tipo de dato devuelto

//Funcionalidad 1
void listarClientes ( setClientes& variosClientes );
void mostrarCliente ( Cliente elCliente );

//Funcionalidad 2
void addCliente(setClientes varios);

//Funcionalidad 3
void eliminarCliente(setClientes& clientes, int id);

//void BuscarPorDNI3(const setClientes& clientes, const char DNI[MAXDNI]);

//Funciones para buscar clientes (Funcionalidad 4 y 5)
void BuscarPorNCuenta(const setClientes& clientes, const char numCuenta[MAXDNI]);
void BuscarPorDNI(const setClientes& clientes,unsigned int &id);

//Funciones principales para modificar datos (Funcionalidad 6)
void menuDeModificacion(unsigned int &modificacion);
void selectorDeModificacion(setClientes &variosClientes, unsigned int &modificacion, unsigned int id);

//Funcionalidad 7
void visualizadorTipoCuenta(setClientes &variosClientes);
void visualizadorTipoCuentaAlternativo(setClientes clientes);
//Funcionalidad 8
void ListarDNIErroneos(const setClientes& clientes);

//Funciones de verificacion de datos
bool verificadorDNI (setClientes variosClientes, char DNI[]);
bool verificadorvalidezNumCuenta (char numCuenta[]);
bool verificadorExistenciaNumCuenta (setClientes variosClientes, char numCuenta[]);
bool verificadorMes(char mes[], unsigned int &mesNum);
bool verificadorDia(unsigned int dia, unsigned int mesNum,unsigned int anho);
bool verificadorAnho(unsigned int anho);

#endif // UTIL_H_INCLUDED

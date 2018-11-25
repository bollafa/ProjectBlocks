﻿#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

# include "estructura.h"

    // Declaraciones de las funciones necesarias específicas para gestionar paciemtes
    // Los prototipos proporcionados pueden ser modificados en sus argumentos y en el tipo de dato devuelto

void listarClientes ( setClientes& variosClientes );
void addCliente(setClientes varios);

void removeClient(setClientes& clientes, int id);
void ListarDNIErroneos(const setClientes& clientes);

#endif // UTIL_H_INCLUDED

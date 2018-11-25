# include <iostream>
# include <cstdlib>

# include "string.h"

# include "cliente.h"
# include "util.h"

using namespace std;

// Definiciones de las funciones necesarias específicas para gestionar clientes

void mostrarCliente ( Cliente elCliente );


void mostrarCliente( Cliente elCliente )
{
    char meses [ ][ 12 ] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};      // Para visualizar los meses
    cout << "\n\tNombre: " << elCliente.nombre;
    cout << "\n\tDNI: " << elCliente.DNI;
    cout << "\n\tdomicilio: " << elCliente.domicilio;
    cout << "\n\tNumCuenta: " << elCliente.numCuenta;
    cout << "\n\ttipoCuenta: " << elCliente.tipoCuenta;
    cout << "\n\tFecha: " << elCliente.fecha.dia << " de " << meses [ elCliente.fecha.mes -1 ] << " de " << elCliente.fecha.anho << endl;
    cout << "\n------------------------------------------------------\n";
}

void listarClientes( setClientes& variosClientes )  //Listar todas los Clientes
{
    int i;
    if ( variosClientes.numClientes == 0 )
        cout << "\nNo existen clientes que listar.\n";
    else {
        cout << "\nListando clientes...\n";
        for (i = 0; i < variosClientes.numClientes; i++ ) {
            cout << "\nCliente : " << i;
            mostrarCliente( variosClientes.Clientes[ i ] );
        }
    }
}
void swap(Cliente& lhs, Cliente& rhs)
{
  Cliente backup = lhs;
  lhs = rhs;
  rhs = backup;
}
void removeClient( setClientes& clientes, int id)
{
  if( !(id < clientes.numClientes) )
    {
      cout << "Por favor inserte una ID valida!\n";
      return;
    }
    for(int i = clientes.numClientes - 2; i >= id; i--)
    {
      cout << "i: " << i << '\n';
      cout << clientes.Clientes[clientes.numClientes - 1].nombre << " << " << clientes.Clientes[i].nombre << '\n';
      swap(clientes.Clientes[clientes.numClientes - 1],clientes.Clientes[i]);
      cout << clientes.Clientes[clientes.numClientes - 1].nombre << " << " << clientes.Clientes[i].nombre << '\n';
    }

    clientes.numClientes--;

}

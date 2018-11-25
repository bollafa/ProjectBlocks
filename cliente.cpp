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
bool isDigit(const char& c)
{
  return (c >= '0') && (c <= '9');
}
bool isDNICorrect(const char DNI[MAXDNI])
{
  static const unsigned char LetterLookUp[23] = { 'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X',
                                                  'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K',
                                                  'E'};
  if(strlen(DNI) != 9)
    return false;

  // hay que comprobar que todos los caracters del dni menos el ultimo sean digitos, pues dnis como '00000000T'
  // son válidos y dnis como '0   0  0T' deberian ser invalidos pero atoi(DNI) daria el mismo resultado := 0.
  for(unsigned int i = 0; i < MAXDNI-2; i++)
    if(!isDigit(DNI[i]))
      return false;

  int iDNI = atoi(DNI);

  return LetterLookUp[iDNI % 23] == DNI[MAXDNI-2];
}
void ListarDNIErroneos(const setClientes& clientes)
{
  cout << " Usuarios con DNI's erroneos: \n";
  if(clientes.numClientes == 0)
    cout << "No existen clientes que comprobar!\n";
  for(unsigned int i = 0; i < clientes.numClientes; i++)
    {
      if(!isDNICorrect(clientes.Clientes[i].DNI))
        {
          mostrarCliente(clientes.Clientes[i]);
        }
    }
}

void BuscarPorDNI(const setClientes& clientes, const char DNI[MAXDNI])
{
  for(unsigned int i = 0; i < clientes.numClientes; i++)
    {
      if(strcmp(clientes.Clientes[i].DNI,DNI) == 0)
        mostrarCliente(clientes.Clientes[i]);
    }

}

void BuscarPorNCuenta(const setClientes& clientes, const char numCuenta[MAXNUMCUENTA])
{
  for(unsigned int i = 0; i < clientes.numClientes; i++)
    {
      if(strcmp(clientes.Clientes[i].numCuenta,numCuenta))
         mostrarCliente(clientes.Clientes[i]);

    }
}
     

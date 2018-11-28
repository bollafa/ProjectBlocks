# include <iostream>
# include <cstdlib>

# include "string.h"

# include "cliente.h"
# include "util.h"

using namespace std;

// Definiciones de las funciones necesarias específicas para gestionar clientes




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
  // se define como const porque no va a cambiar la tabla y como static para que no se vuelva a redefinir cada vez que se llame a la funciones
  // la letra del dni esta definido por una tabla y como N % 23 pertenece a [0,22] sabemos que siempre va a dar dentro de la array.
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

  // el dni seria correcto si la letra dada coincide con la del algoritmo.
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

void BuscarPorDNI3(const setClientes& clientes, const char DNI[MAXDNI])
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

void BuscarPorDNI(const setClientes& variosClientes, unsigned int &id)
{
    char DNI[MAXDNI];
    leerCadena("Inserte DNI: ", DNI);
    for(unsigned int i = 0; i < variosClientes.numClientes; i++)
            if(strcmp(variosClientes.Clientes[i].DNI,DNI) == 0)
                id=i;

}
void menuDeModificacion(unsigned int &modificacion)
{
do {
    cout << "\n1. Nombre";
    cout << "\n2. DNI";
    cout << "\n3. Domiciio";
    cout << "\n4. Numero de cuenta";
    cout << "\n5. Tipo de cuenta";
    cout << "\n6. Fecha de creacion de la cuenta";

    modificacion= leerEntero("\nQue dato desea modificar?\n");

    if (modificacion<1 || modificacion>6)
        cout << "Elige una opcion valida";

}while (modificacion<1 || modificacion>6);



}

void selectorDeModificacion(setClientes &variosClientes, unsigned int &modificacion, unsigned int id){
switch (modificacion) {
    int seguir;

    case 1:

        leerCadena("\nIntroduzca el nuevo nombre: ",variosClientes.Clientes[id].nombre);

        break;
    case 2:
        do{
            leerCadena("\nIntroduzca el nuevo DNI: ",variosClientes.Clientes[id].DNI);
            //if (verificadorDNI)
               //)) cout << "DNI ya existente";
               // cout << verificadorDNI;

        } while (0);
        break;
    case 3:

        leerCadena("\nIntroduzca el nuevo domicilio: ",variosClientes.Clientes[id].domicilio);
        break;
    case 4:

        leerCadena("\nIntroduzca el nuevo numero de cuenta: ",variosClientes.Clientes[id].numCuenta);
        break;
    case 5:

        leerCadena("\nIntroduzca el nuevo tipo de cuenta: ",variosClientes.Clientes[id].tipoCuenta);
        break;
    case 6:
        //cout << "introduzca la nueva fecha ";
    default:
        cout << "Error en la operacion ";

}
}
//bool verificadorDNI (){
    //for(unsigned int i = 0; i < variosClientes.numClientes; i++){
      //      if(strcmp(variosClientes.Clientes[i].DNI,DNI) == 0)
               // return false;
   // }
//}


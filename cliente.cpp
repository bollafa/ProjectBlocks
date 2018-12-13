# include <iostream>
# include <cstdlib>

# include "string.h"

# include "cliente.h"
# include "util.h"

using namespace std;

// Definiciones de las funciones necesarias específicas para gestionar clientes

/*
  PD: Algunas funciones como esDigito y  DNICorrecto o mesCadenaANumero que solo estan definidas y declaradas en
  cliente.cpp porque no hace falta que se utilicen en main.cpp o en otro archivo, ademas se busca
  que solo se puedan utilizar en cliente.cpp al ser funciones que dan utilidades específicas. Así no se
  poluciona el espacio de nombres global y un usuario ajeno a la libreria que requiera añadir alguna funcionalidad
  desde las ya dadas no necesita preocuparse de su existencia.
  Las funciones estan ordenadas segun la funcionalidad principal para las que se usa
*/

//Funcionalidad 1
void mostrarCliente( Cliente elCliente ){
    char meses [ ][ 12 ] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};      // Para visualizar los meses
    cout << "\n\tNombre: " << elCliente.nombre;
    cout << "\n\tDNI: " << elCliente.DNI;
    cout << "\n\tdomicilio: " << elCliente.domicilio;
    cout << "\n\tNumCuenta: " << elCliente.numCuenta;
    cout << "\n\ttipoCuenta: " << elCliente.tipoCuenta;
    cout << "\n\tFecha: " << elCliente.fecha.dia << " de " << meses [ elCliente.fecha.mes -1 ] << " de " << elCliente.fecha.anho << endl;
    cout << "\n------------------------------------------------------\n";
}
void listarClientes( setClientes& variosClientes ){
//Listar todos los Clientes

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

//Funcionalidad 2
void anadirCliente(setClientes& clientes){
  Cliente cNuevoCliente; //Creamos un nuevo dato de tipo cliente donde guardar los nuevos datos mientras estos aun no se verificaron
  char mes[MAXMES];
  char continuar[2];

  if(clientes.numClientes+1 > MAXCLIENTES) //Comprobamos que no se haya llegado al limite de clientes
    {
      cout << "¡Hay demasiados clientes!\n";
      return;
    }

  cout << "\n---- CREACION DE NUEVO CLIENTE ----\n";
  leerCadena("\nInserte el nombre del cliente o pulse '*' salir: ",cNuevoCliente.nombre);
  if (cNuevoCliente.nombre[0]=='*'){
    cout << "Operacion cancelada...\n";
    return;
  }


  leerCadena("Inserte DNI o pulse * para salir: ", cNuevoCliente.DNI);
  while(verificadorDNI(clientes, cNuevoCliente.DNI)&& cNuevoCliente.DNI[0]!='*' )
    {
      leerCadena("DNI ya esta registrado, por favor inserte de nuevo el DNI o pulse '*' para salir: ", cNuevoCliente.DNI);
    }
  if (cNuevoCliente.DNI[0]=='*'){
    cout << "Operacion cancelada...\n";
    return;
  }

  leerCadena("Inserte domicilio o pulse '*' para salir: ", cNuevoCliente.domicilio);
  if (cNuevoCliente.domicilio[0]=='*'){
    cout << "Operacion cancelada...\n";
    return;
  }

  leerCadena("Inserte numero de cuenta o pulse '*' para salir: ", cNuevoCliente.numCuenta );
  while(( !verificadorvalidezNumCuenta(cNuevoCliente.numCuenta) ||
         verificadorExistenciaNumCuenta(clientes, cNuevoCliente.numCuenta)) && cNuevoCliente.numCuenta[0]!='*' )
    {
      leerCadena("Numero de cuenta erroneo o ya esta registrado, por favor inserte de nuevo el numero de cuenta o pulse '*' para salir: ",
                 cNuevoCliente.numCuenta);
    }
  if (cNuevoCliente.numCuenta[0]=='*'){
    cout << "Operacion cancelada...\n";
    return;
  }

  leerCadena("Inserte el tipo de cuenta ahorro/corriente o pulse '*' para salir: ", cNuevoCliente.tipoCuenta);

  while( !verificadorTipoCuenta(cNuevoCliente.tipoCuenta) && cNuevoCliente.tipoCuenta[0]!='*' )
    {
      leerCadena("Tipo de cuenta erroneo, por favor inserte de nuevo el tipo de cuenta o pulse '*' para salir: ", cNuevoCliente.tipoCuenta);
    }
  if (cNuevoCliente.tipoCuenta[0]=='*'){
    cout << "Operacion cancelada...\n";
    return;
  }

  cout << "Inserte fecha de apertura de la cuenta: \n";
  cNuevoCliente.fecha.dia = leerEntero("Dia: ");
  leerCadena("Mes: ", mes);
  cNuevoCliente.fecha.anho = leerEntero("Anho: ");
  verificadorMes(mes,cNuevoCliente.fecha.mes);
  /*
    Si el dato mes es correcto (tanto en numero como el letra), lo guarda en numero en el apartado
    correcpondiente de cNuevoClienteesto. Esto es necesario hacerlo antes del while porque
    el orden de los operandos del operador || no se garantiza ni en C ni en C++
  */
  while(!verificadorMes(mes, cNuevoCliente.fecha.mes) ||
        !verificadorDia(cNuevoCliente.fecha.dia,cNuevoCliente.fecha.mes, cNuevoCliente.fecha.anho) ||
        !verificadorAnho(cNuevoCliente.fecha.anho))
    {

      leerCadena("Fecha erronea, pulse '*' para salir o otra tecla para introducir una fecha valida \n",continuar);
      if (continuar[0]!='*'){
        cNuevoCliente.fecha.dia = leerEntero("Dia: ");
        leerCadena("Mes: ", mes);
        cNuevoCliente.fecha.anho = leerEntero("Anho: ");
        verificadorMes(mes,cNuevoCliente.fecha.mes);
      }
      else{
        cout << "Operacion cancelada...\n";
        return;
      }
    }
  //Si la operacion no se cancela y todos los datos introducidos son validos los datos nuevos se guardan en el array de clientes
  clientes.Clientes[clientes.numClientes] = cNuevoCliente;
  cout << "\nNuevo cliente creado:\n";
  mostrarCliente(cNuevoCliente);
  clientes.numClientes++;
}

//Funcionalidad 3
void intercambiar(Cliente& lhs, Cliente& rhs){

// Para intercambiar dos elementos, es decir, dados a y b:  a:= c y b := d, que se intercambien sus valores
// a := d y b:= c, es necesario crear una copia por la cual copia := c, a:= b, b := copia.

  Cliente backup = lhs;
  lhs = rhs;
  rhs = backup;
}
void eliminarCliente( setClientes& clientes, int id){

/*
  Eliminar un cliente del medio es lo mismo que ponerlo al final y luego eliminarlo.
   Por tanto, se van intercambiando las posiciones del cliente penúltimo con el último asi consiguiendo
   ir cambiando todos los clientes hasta que quedan todos en su orden original menos el que se quiera eliminar que
   se encuentra al final, posteriormente se elimina sin necesidad de cambiar nada mas.
*/

    for(int i = clientes.numClientes - 2; i >= id; i--)
    {
      //cout << "i: " << i << '\n';
      //cout << clientes.Clientes[clientes.numClientes - 1].nombre << " << " << clientes.Clientes[i].nombre << '\n';
      intercambiar(clientes.Clientes[clientes.numClientes - 1],clientes.Clientes[i]);
      //cout << clientes.Clientes[clientes.numClientes - 1].nombre << " << " << clientes.Clientes[i].nombre << '\n';
    }

    clientes.numClientes--;
}

//Funcionalidad 4
void BuscarPorNCuenta(const setClientes& clientes, const char numCuenta[MAXNUMCUENTA]){
    bool bExisteCliente=false;

  for(unsigned int i = 0; i < clientes.numClientes; i++)
    if(!strcmp(clientes.Clientes[i].numCuenta,numCuenta)){
        mostrarCliente(clientes.Clientes[i]);
        bExisteCliente=true;
    }
    if(!bExisteCliente)
        cout << "No existe ningun cliente con ese numero de cuenta";
}

//Funcionalidad 5
void BuscarPorDNI(const setClientes& variosClientes, unsigned int &id){
    char DNI[MAXDNI];

    id=MAXCLIENTES+1;
    if(variosClientes.numClientes==0){
        cout << "\nOperacion denegada. No hay ningun cliente guardado en la base de datos\n";
        return;
    }
    do {
        leerCadena("\nInserte DNI o pulse '*' para cancelar\n", DNI); //Se pide el DNI
        if(DNI[0] == '*'){
            cout << "Operacion cancelada...\n";
            return; //Si se pulsa '*' se termina la ejecucion de la funcion
        }
        //Se compara con los DNI existentes y se guarda la posicion en el array del cliente con el que coincida
        for(unsigned int i = 0; i < variosClientes.numClientes; i++)
            if(!strcmp(variosClientes.Clientes[i].DNI,DNI))
                id=i;
        if (id==MAXCLIENTES+1)
                cout << "El DNI no se encuentra en la base de datos\n\n";

    } while (id==MAXCLIENTES+1); // Si no se pulsa '*' se pide un DNI hasta que este coincida con el de algun cliente
}

//Funcionalidad 6
void menuDeModificacion(unsigned int &modificacion){
//Menu con los datos que se pueden modificar

do {
    cout << "\n1. Nombre";
    cout << "\n2. DNI";
    cout << "\n3. Domicilio";
    cout << "\n4. Numero de cuenta";
    cout << "\n5. Tipo de cuenta";
    cout << "\n6. Fecha de creacion de la cuenta";
    cout << "\n7. Salir\n";

    modificacion= leerEntero("\nQue dato desea modificar?\n"); //Introducimos la variable que nos permitira realizar los cambios

    if (modificacion<1 || modificacion>7)
        cout << "\nElige una opcion valida\n";

}while (modificacion<1 || modificacion>7); //Se repite hasta que se introduzca un valor correcto



}
void selectorDeModificacion(setClientes &variosClientes, unsigned int &modificacion, unsigned int id){

//Para realizar los cambios en los datos creamos un switch con el que se llevaran a cab los cambios en funcion de la opcion elegida por el usuario

    switch (modificacion) {


        case 1:     //Introducimos un nuevo valor para el array de nombre

            leerCadena("\nIntroduzca el nuevo nombre: ",variosClientes.Clientes[id].nombre);

            break;

        case 2:        //Modificamos el valor del DNI siempre que este no este ya almacenado o si se eligela opcion de cancelar.
        {              //Se repite la operacion hasta que sea correcto o se cancele
            char DNI[MAXDNI];
            do{
                leerCadena("\nIntroduzca el nuevo DNI o pulse '*' para cancelar: ",DNI);
                if (verificadorDNI(variosClientes,DNI))
                    cout << "DNI ya existente";
            } while (verificadorDNI(variosClientes,DNI));
            if (DNI[0]!='*')
                strcpy(variosClientes.Clientes[id].DNI, DNI);

        }
            break;

        case 3:     //Introducimos un nuevo valor para el array de domicilio

            leerCadena("\nIntroduzca el nuevo domicilio: ",variosClientes.Clientes[id].domicilio);
            break;

        case 4:     //Pedimos un nuevo numero de cuenta y si este es correcto se modifica. Se repite la operacion hasta que sea correcto o se cancele
            char numCuenta[11];
            do{
            leerCadena("\nIntroduzca el nuevo numero de cuenta o pulse '*' para cancelar: ",numCuenta);
            if (!verificadorvalidezNumCuenta (numCuenta) && numCuenta[0]!='*')
                cout << "Numero de cuenta incorrecto";
            if (verificadorExistenciaNumCuenta (variosClientes,numCuenta) && numCuenta[0]!='*')
                cout << "Numero de cuenta ya existente";
            }while((!verificadorvalidezNumCuenta (numCuenta)||verificadorExistenciaNumCuenta (variosClientes,numCuenta))&& (numCuenta[0]!='*'));
            if (numCuenta[0]!='*')
                strcpy(variosClientes.Clientes[id].numCuenta, numCuenta);
            break;

        case 5:     //Introducimos un nuevo valor para el tipo de cuenta y si es correcto lo modificamos
            char tipoCuenta[MAXTIPOCUENTA];

            do {
                leerCadena("\nIntroduzca el nuevo tipo de cuenta (ahorro/corriente) o pulse '*' para cancelar\n",tipoCuenta);
                verificadorTipoCuenta(tipoCuenta);
                if(!verificadorTipoCuenta(tipoCuenta)&& tipoCuenta[0]!='*')
                    cout << "Tipo de cuenta incorrecto";
            }while(!verificadorTipoCuenta(tipoCuenta)&& tipoCuenta[0]!='*');
            if (tipoCuenta[0]!='*')
                strcpy(variosClientes.Clientes[id].tipoCuenta, tipoCuenta);
            break;

        case 6:{        //Pedimos un nuevo numero de cuenta y si este es correcto se modifica. Se repite la operacion hasta que sea correcto o se cancele
            unsigned int dia;
            unsigned int anho;
            char mes [11];
            unsigned int mesNum;
            char continuar[2];

            cout << "\nIntroduzca la nueva fecha\n";
            do {
                dia= leerEntero("Dia: ");
                leerCadena("Mes: ", mes);
                anho= leerEntero("Anho: ");


                if (!verificadorMes(mes, mesNum))
                    cout << "Mes introducido no valido\n";
                if (!verificadorDia(dia,mesNum, anho))
                    cout << "El dia y el mes no se corresponden\n";
                if (!verificadorAnho(anho))
                    cout << "El anho de creacion de la cuenta tiene que ser un numero y no puede ser superior al anho actual\n";

                if (!verificadorMes(mes, mesNum)|| !verificadorDia(dia,mesNum, anho) || !verificadorAnho(anho)){
                    leerCadena("Pulse '*' para salir o otra tecla para introducir una fecha valida\n",continuar);
                    if (continuar[0]=='*')
                        break;

                    }
            }while(!verificadorMes(mes, mesNum)|| !verificadorDia(dia,mesNum, anho) || !verificadorAnho(anho));

                if(continuar[0]!='*'){ // Si se cumplen las condiciones y no se pulsa '*' se modifican los datos del cliente
                    variosClientes.Clientes[id].fecha.mes=mesNum;
                    variosClientes.Clientes[id].fecha.dia=dia;
                    variosClientes.Clientes[id].fecha.anho=anho;
                }
        }
            break;

        case 7:  return;

        default:
            cout << "Error en la operacion ";

}
    cout << "\nOperacion realizada con exito...\n";
}

//Funcionalidad 7
void visualizadorTipoCuenta(setClientes clientes){

/*
 Se elige un tipo de cuenta inicial y se imprimen por pantalla aquellos usuarios que tengan el mismo
 se borran los usuarios que se imprimen para no tener que volver a iterar por ellos después. Cuando se llega al final
 y ya no quedan mas usuarios con el primer tipo, se cambia al segundo y se repite el proceso así sucesivamente hasta
 que ya no queda ningun usuario
*/

  char tipoCuenta[MAXTIPOCUENTA];

  if(clientes.numClientes <= 0)

    cout<< "\nNo hay clientes que visualizar\n";

  while(clientes.numClientes > 0)
    {
      strcpy(tipoCuenta,clientes.Clientes[0].tipoCuenta);
      cout << "\nTipo de cuenta: " << tipoCuenta << "\n";
      for(unsigned int i = 0; i < clientes.numClientes ; i++)
          if(!strcmp(tipoCuenta,clientes.Clientes[i].tipoCuenta))
            {
              mostrarCliente(clientes.Clientes[i]);
              eliminarCliente(clientes,i);
              // al borrar en la array hay que restarle al indice para ajustarse
              // al nuevo tamaño.
              i--;
            }

    }
}

//Funcionalidad 8
bool esDigito(const char& c){
  return (c >= '0') && (c <= '9');
}
bool DNICorrecto(const char DNI[MAXDNI]){
  // se define como const porque no va a cambiar la tabla y como static para que no se vuelva a redefinir cada vez que se llame a la funcion
  // la letra del dni esta definido por una tabla y como N % 23 pertenece a [0,22] sabemos que siempre va a dar dentro de la array.
  // Se podria haber definido como global pero para no polucionar el espacio de nombres global y como su uso
  // es específico para esta funcion, se declara aquí.
  static const unsigned char LetraLookUpTable[23] = { 'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X',
                                                  'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K',
                                                  'E'};
  if(strlen(DNI) != MAXDNI-1)
    return false;

  // hay que comprobar que todos los caracteres del dni menos el ultimo sean digitos, pues dnis como '00000000T'
  // son válidos y dnis como '0   0  0T' deberian ser invalidos pero atoi(DNI) daria el mismo resultado := 0.
  for(unsigned int i = 0; i < MAXDNI-2; i++)
    if(!esDigito(DNI[i]))
      return false;

  int iDNI = atoi(DNI);

  // el DNI seria correcto si la letra dada coincide con la del algoritmo.
  return LetraLookUpTable[iDNI % 23] == DNI[MAXDNI-2];
}
void ListarDNIErroneos(const setClientes& clientes){
  bool DNIErroneos=false;
  if(clientes.numClientes == 0){
    cout << "\nNo existen clientes que comprobar!\n";
    return;
  }
  for(unsigned int i = 0; i < clientes.numClientes; i++)
    {
      if(!DNICorrecto(clientes.Clientes[i].DNI))
        {
          if (!DNIErroneos)
            cout << "\nUsuarios con DNI erroneos: \n";
          mostrarCliente(clientes.Clientes[i]);
          DNIErroneos=true;
        }
    }
  if (!DNIErroneos)
    cout << "\nTodos los DNI son correctos\n";
}

//Funciones de verificacion de datos
bool verificadorDNI (const setClientes& variosClientes, char DNI[]){
  //Comparamos el DNI introducido con los ya existentes para descartar que ya este almacenado
    for(unsigned int i = 0; i < variosClientes.numClientes; i++)
        if(!strcmp(variosClientes.Clientes[i].DNI,DNI))
            return true;
    return false;
}
bool verificadorvalidezNumCuenta (char numCuenta[]){


  //Comprobamos que el numero de cuenta introducido sea valido ( tenga 6 letras y despues 4 numeros)
  for (int i=0;i<6;i++)
    if (!((numCuenta[i]>='A')&& (numCuenta[i] <= 'Z')))
      return false;

  for (int i=6; i<MAXNUMCUENTA-1;i++)
    if (!((numCuenta[i] >= '0') && (numCuenta[i] <= '9')))
      return false;

    return true;
}
bool verificadorExistenciaNumCuenta (setClientes variosClientes, char numCuenta[]){
  //Comparamos el numero de cuenta introducido con los existentes para descartar que ya este almacenado
    for(unsigned int i = 0; i < variosClientes.numClientes; i++)
        if(strcmp(variosClientes.Clientes[i].numCuenta,numCuenta) == 0)
            return true;
    return false;
}
bool verificadorTipoCuenta(char tipoCuenta[]){
if (!strcmp(tipoCuenta,"ahorro")|| !strcmp(tipoCuenta,"corriente"))
    return true;
return false;
}
unsigned int mesCadenaANumero(char mes[]){
  char meses [ ][ 12 ] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre",
                          "octubre", "noviembre", "diciembre"};
  //Comparamos el mes introducido con los de la matriz meses, si coinciden devolvemos el valor + 1
  for(unsigned int i = 0; i < 12; i++)
    if(!strcmp(meses[i],mes))
      return i + 1; // para que este en rango [1,12]

  return -1; // numero magico que indica que ha habido un error, -1 como unsigned int causa overflow y se
  // convierte en el maximo numero representable por un unsigned int, normalmente si int de 32 bits := 2^32-1
}
bool verificadorMes(char mes[], unsigned int &mesNum){

//Se permiten dos formas de introducir el mes, mediante un numero de 1 al 12 o en letra

    //Devolvemos el valor true si el caracter introducido es un numero entre el 1 y el 12
    if (atoi (mes)>0 && atoi (mes)<13){
      // hay que comprobar que el mes no sea: 1junio o abril12 por ejemplo,
      for(int i = 0; i < strlen(mes); i++)
        if(!esDigito(mes[i]))
          return false;
        mesNum = atoi (mes);
        return true;
    }
    else if( (mesNum = mesCadenaANumero(mes) ) != -1 )
      {
        return true;
      }
    return false;
}
bool verificadorDia(unsigned int dia, unsigned int mesNum, unsigned int anho){
//Restringimos los valores de la variable dia en funcion de mes

    if (mesNum==1|| mesNum==3|| mesNum==5|| mesNum==7|| mesNum==8|| mesNum==10|| mesNum==12)
        if (dia<32 && dia > 0)
            return true;
        else return false;

    if (mesNum==4|| mesNum==6|| mesNum==9|| mesNum==11)
        if (dia<31 && dia > 0)
            return true;
        else return false;

//Comprobamo si el año es bisiesto (se puede dividir por 4) y en funcion del resultado limitamos los dias de febrero

    if (mesNum==2)
        if (anho%4==0)
            if (dia < 30 && dia>0)
                return true;
            else
                return false;
        else
            if (dia <29 && dia >0)
                return true;
            else
                return false;

}
bool verificadorAnho(unsigned int anho){
//Comprobamos que el año no sea superior a 2018
    if (anho<2019 && anho>0 )
        return true;
    return false;


}

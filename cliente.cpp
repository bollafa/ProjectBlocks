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

*/


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
void addCliente(setClientes varios)
{
    int id;
    char ahorro, corriente;
    char DNI[MAXDNI];
    char nombre [ MAXNOMBRE ];
    char domicilio [ MAXDOMICILIO ];
    char numCuenta [ MAXNUMCUENTA ];
    char tipoCuenta [ MAXTIPOCUENTA ];
    unsigned int numClientes;

    id=varios.numClientes+1;

    char meses [ ][ 12 ] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    cout<< "Para crear la cuenta correctamente, tendrá que cubrir los siguientes campos:" << endl;

    if ( varios.numClientes==100)
        cout<< "La base de datos está llena"; //Si hay 100, que es lo máximo, no deja crear nueva cuenta

    else
    {
        for (int i=0; i<50;i++){

    do{
        leerCadena("\nNombre:",varios.Clientes[id].nombre); //Pido el nombre, y compruebo que si no tiene alguna letra, no es válido.

        if(!((nombre[i]>'A')&& (nombre[i] < 'Z')))
            cout<<"Nombre no valido";

    }while(((nombre[i]>'A')&& (nombre[i] < 'Z')));
        }

    do{
        leerCadena("\nDNI:",varios.Clientes[id].DNI); //Pido el DNI, comprobando si está ya registrado o es correcto.

                    if ((verificadorDNI(varios,DNI))&&(isDNICorrect(vario,DNI)))
                         cout<<"DNI ya registrado";

    } while ((verificadorDNI(varios,DNI))&&(isDNICorrect(vario,DNI)));

    for (int i=0; i<50;i++){

    do{
        leerCadena("\nDomicilio:",varios.Clientes[id].domicilio); //Pido el domicilio y al igual que el nombre compruebo que no tenga numeros para que sea correcto

        if(!((domicilio[i]>'A')&& (domicilio[i] < 'Z')))
            cout<<"Domicilio no valido";

    }while(((domicilio[i]>'A')&& (domicilio[i] < 'Z')));
        }

    do{

    leerCadena("\nNumero de cuenta:",varios.Clientes[id].numCuenta); //Pido la cuenta y veo que no esté ya o que sea errónea

                if ((verificadorExistenciaNumCuenta(varios,numCuenta)) (verificadorvalidezNumCuenta(varios,numCuenta)))
                     cout<<"Numero de cuenta ya existente o no valido";

    } while ((verificadorExistenciaNumCuenta(varios,numCuenta)) (verificadorvalidezNumCuenta(varios,numCuenta)));

     do{

        leerCadena("\nTipo de Cuenta: ",varios.Clientes[id].tipoCuenta ); //Pido el tipo de cuenta, q si no es de tipo ahorro o corriente, no es válida.

        if((tipoCuenta!=ahorro)||(tipoCuenta!=corriente))
            cout<<"Tipo de cuenta no valida";

    }while((tipoCuenta=='ahorro')||(tipoCuenta=='corriente'));


        cout<<"Fecha:";

    do{

        leerCadena("\nDia: ",varios.Clientes[id].fecha.dia ); //Pido día, mes y anho y compruebo q sean válidos.

        if(!verificadorDia)
            cout<<"Dia no valido";

   } while(verificadorDia);

    do{

        leerCadena("\nMes: ",varios.Clientes[id].fecha.mes );

        if(!verificadorMes(varios,numCuenta))
            cout<<"Tipo de cuenta no valida";

    }while(verificadorMes(varios,numCuenta));


    do{

        leerCadena("\nAnho: ",varios.Clientes[id].fecha.anho );

        if(!verificadorAnho(varios,numCuenta))
            cout<<"anho no valido";

    }while(verificadorAnho(varios,numCuenta));

    }
}
// Para intercambiar dos elementos, es decir, dados a y b:  a:= c y b := d, que se intercambien sus valores
// a := d y b:= c, es necesario crear una copia por la cual copia := c, a:= b, b := copia.
void intercambiar(Cliente& lhs, Cliente& rhs)
{
  Cliente backup = lhs;
  lhs = rhs;
  rhs = backup;
}

/*
  Eliminar un cliente del medio es lo mismo que ponerlo al final y luego eliminarlo.
   Por tanto, se van intercambiando las posiciones del cliente penúltimo con el último asi consiguiendo
   ir cambiando todos los clientes hasta que quedan todos en su orden original menos el que se quiera eliminar que
   se encuentra al final, posteriormente se elimina sin necesidad de cambiar nada mas.
*/

void eliminarCliente( setClientes& clientes, int id)
{

    for(int i = clientes.numClientes - 2; i >= id; i--)
    {
      //cout << "i: " << i << '\n';
      //cout << clientes.Clientes[clientes.numClientes - 1].nombre << " << " << clientes.Clientes[i].nombre << '\n';
      intercambiar(clientes.Clientes[clientes.numClientes - 1],clientes.Clientes[i]);
      //cout << clientes.Clientes[clientes.numClientes - 1].nombre << " << " << clientes.Clientes[i].nombre << '\n';
    }

    clientes.numClientes--;
}
bool esDigito(const char& c)
{
  return (c >= '0') && (c <= '9');
}
bool DNICorrecto(const char DNI[MAXDNI])
{
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
void ListarDNIErroneos(const setClientes& clientes)
{
  cout << " Usuarios con DNI's erroneos: \n";
  if(clientes.numClientes == 0)
    cout << "No existen clientes que comprobar!\n";
  for(unsigned int i = 0; i < clientes.numClientes; i++)
    {
      if(!DNICorrecto(clientes.Clientes[i].DNI))
        {
          mostrarCliente(clientes.Clientes[i]);
        }
    }
}

void BuscarPorNCuenta(const setClientes& clientes, const char numCuenta[MAXNUMCUENTA])
{
    bool bExisteCliente=false;

  for(unsigned int i = 0; i < clientes.numClientes; i++)
    if(!strcmp(clientes.Clientes[i].numCuenta,numCuenta)){
        mostrarCliente(clientes.Clientes[i]);
        bExisteCliente=true;
    }
    if(!bExisteCliente)
        cout << "No existe ningun cliente con ese numero de cuenta";
}

void BuscarPorDNI(const setClientes& variosClientes, unsigned int &id)
{
    char DNI[MAXDNI];

    id=MAXCLIENTES+1;
    do {
        leerCadena("Inserte DNI o pulsa '*' para cancelar\n", DNI); //Se pide el DNI
        if(DNI[0] == '*')
          return;
        for(unsigned int i = 0; i < variosClientes.numClientes; i++) //Se compara con los DNI existentes y le asocia
            if(!strcmp(variosClientes.Clientes[i].DNI,DNI))
                id=i;
        if (id==MAXCLIENTES+1)
                cout << "El DNI no se encuentra en la base de datos\n\n";

    } while (id==MAXCLIENTES+1);
}
void menuDeModificacion(unsigned int &modificacion) //Menu con los datos que se pueden modificar
{
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
                leerCadena("\nIntroduzca el nuevo DNI o pulsa '*' para cancelar: ",DNI);
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
            leerCadena("\nIntroduzca el nuevo numero de cuenta o pulsa '*' para cancelar: ",numCuenta);
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
                leerCadena("\nIntroduzca el nuevo tipo de cuenta (ahorro/corriente) o pulsa '*' para cancelar\n",tipoCuenta);
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
                    leerCadena("Pulsa '*' para salir o otra tecla para introducir una fecha valida\n",continuar);
                    if (continuar[0]=='*')
                        break;

                    }
            }while(!verificadorMes(mes, mesNum)|| !verificadorDia(dia,mesNum, anho) || !verificadorAnho(anho));

                if(continuar[0]!='*'){
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
    if ( !( (numCuenta[i]>='A')&& (numCuenta[i] <= 'Z') ) )
      return false;

  for (int i=6; i<MAXNUMCUENTA-1;i++)
    if (!esDigito(numCuenta[i]))
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
unsigned int mesCadenaANumero(char mes[])
{
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

bool verificadorAnho(unsigned int anho){  //Comprobamos que el año no sea superior a 2018
    if (anho<2019 && anho>0 )
        return true;
    return false;


}


void anadirCliente(setClientes& clientes)
{
  Cliente cNuevoCliente;
  char mes[MAXMES];
  unsigned int iNumeroMes;
  if(clientes.numClientes+1 > MAXCLIENTES)
    {
      cout << "¡Hay demasiados clientes!\n";
      return;
    }

  cout << "---- CREACIÓN DE NUEVO CLIENTE ----\n";
  leerCadena("Inserte el nombre del cliente: ",cNuevoCliente.nombre);

  leerCadena("Inserte DNI: ", cNuevoCliente.DNI);

  while( !DNICorrecto(cNuevoCliente.DNI) || verificadorDNI(clientes, cNuevoCliente.DNI) )
    {
      leerCadena("DNI Erroneo o ya esta registrado, por favor inserte de nuevo el DNI: ", cNuevoCliente.DNI);
    }

  leerCadena("Inserte domicilio: ", cNuevoCliente.domicilio);

  leerCadena("Inserte número de cuenta: ", cNuevoCliente.numCuenta );

  while( !verificadorvalidezNumCuenta(cNuevoCliente.numCuenta) ||
         verificadorExistenciaNumCuenta(clientes, cNuevoCliente.numCuenta) )
    {
      leerCadena("Numero de cuenta erroneo o ya esta registrado, por favor inserte de nuevo el numero de cuenta: ",
                 cNuevoCliente.numCuenta);
    }
         
  leerCadena("Inserte el tipo de cuenta ahorro/corriente: ", cNuevoCliente.tipoCuenta);

  while( !verificadorTipoCuenta(cNuevoCliente.tipoCuenta) )
    {
      leerCadena("Tipo de cuenta erróneo, por favor inserte de nuevo el tipo de cuenta: ", cNuevoCliente.tipoCuenta);
    }

  cout << "Inserte fecha de apertura de la cuenta: \n";
  cNuevoCliente.fecha.dia = leerEntero("Dia: ");
  leerCadena("Mes: ", mes);
  cNuevoCliente.fecha.anho = leerEntero("Anho: ");

  
  verificadorMes(mes,cNuevoCliente.fecha.mes);
  
  // NOTA: el orden de los operandos del operador || no se garantiza ni en C ni en C++
  while(!verificadorMes(mes, cNuevoCliente.fecha.mes) ||
        !verificadorDia(cNuevoCliente.fecha.dia,cNuevoCliente.fecha.mes, cNuevoCliente.fecha.anho) ||
        !verificadorAnho(cNuevoCliente.fecha.anho))
    {
      cout << "Fecha errónea, por favor inserte fecha de apertura de la cuenta: \n";
      cNuevoCliente.fecha.dia = leerEntero("Dia: ");
      leerCadena("Mes: ", mes);
      cNuevoCliente.fecha.anho = leerEntero("Anho: ");
      verificadorMes(mes,cNuevoCliente.fecha.mes);
    }
  clientes.Clientes[clientes.numClientes] = cNuevoCliente;
  clientes.numClientes++;
}
  



/*
 Se elige un tipo de cuenta inicial y se imprimen por pantalla aquellos usuarios que tengan el mismo
 se borran los usuarios que se imprimen para no tener que volver a iterar por ellos después. Cuando se llega al final
 y ya no quedan mas usuarios con el primer tipo, se cambia al segundo y se repite el proceso así sucesivamente hasta
 que ya no queda ningun usuario
*/
void visualizadorTipoCuenta(setClientes clientes)
{
  char tipoCuenta[MAXTIPOCUENTA];

  if(clientes.numClientes <= 0)

    cout<< "No hay clientes que visualizar";

  while(clientes.numClientes > 0)
    {
      strcpy(tipoCuenta,clientes.Clientes[0].tipoCuenta);
      cout << "Tipo de cuenta: " << tipoCuenta << "\n";
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

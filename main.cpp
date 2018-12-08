//Programa main para gestion de Clientes de un centro sanitario

# include <iostream>
# include <cstdlib>

# include "string.h"

# include "estructura.h"
# include "cliente.h"
# include "util.h"

using namespace std;

int menu();

int main() {
    int opcion;
    setClientes variosClientes;

    variosClientes.numClientes = 0; // Inicializamos el numero de clientes

    // Valores iniciales de prueba

    strcpy(variosClientes.Clientes[0].nombre, "Mercedes Lorenzo");
    strcpy(variosClientes.Clientes[0].DNI, "41235674C");
    strcpy(variosClientes.Clientes[0].domicilio, "Delicias, 25");
    strcpy(variosClientes.Clientes[0].numCuenta, "BBVAES0508");
    strcpy(variosClientes.Clientes[0].tipoCuenta, "ahorro");
    variosClientes.Clientes[0].fecha.dia = 15;
    variosClientes.Clientes[0].fecha.mes = 4;
    variosClientes.Clientes[0].fecha.anho = 2013;


    strcpy(variosClientes.Clientes[1].nombre, "Cosme Pazos");
    //variosClientes.Clientes[1].nombre = "Cosme Pazos00000000000000000000000000000000000000";
    strcpy(variosClientes.Clientes[1].DNI, "33271682C");
    strcpy(variosClientes.Clientes[1].domicilio, "Retiro,34");
    strcpy(variosClientes.Clientes[1].numCuenta, "BSCHES1234");
    strcpy(variosClientes.Clientes[1].tipoCuenta, "corriente");
    variosClientes.Clientes[1].fecha.dia = 30;
    variosClientes.Clientes[1].fecha.mes = 9;
    variosClientes.Clientes[1].fecha.anho = 2014;

    strcpy(variosClientes.Clientes[2].nombre, "Enrique Bueno");
    strcpy(variosClientes.Clientes[2].DNI, "98765432Z");
    strcpy(variosClientes.Clientes[2].domicilio, "Plaza del Comendador");
    strcpy(variosClientes.Clientes[2].numCuenta, "BKBKES4978");
    strcpy(variosClientes.Clientes[2].tipoCuenta, "ahorro");
    variosClientes.Clientes[2].fecha.dia = 29;
    variosClientes.Clientes[2].fecha.mes = 6;
    variosClientes.Clientes[2].fecha.anho = 2012;

    strcpy(variosClientes.Clientes[3].nombre, "Bernardo Requejo");
    strcpy(variosClientes.Clientes[3].DNI, "45986104J");
    strcpy(variosClientes.Clientes[3].domicilio, "Diagonal, 345");
    strcpy(variosClientes.Clientes[3].numCuenta, "PBNKDF3234");
    strcpy(variosClientes.Clientes[3].tipoCuenta, "ahorro");
    variosClientes.Clientes[3].fecha.dia = 1;
    variosClientes.Clientes[3].fecha.mes = 1;
    variosClientes.Clientes[3].fecha.anho = 2008;

    strcpy(variosClientes.Clientes[4].nombre, "Luisa Legazpi");
    strcpy(variosClientes.Clientes[4].DNI, "87253640K");
    strcpy(variosClientes.Clientes[4].domicilio, "Callejuela del Parque, 46");
    strcpy(variosClientes.Clientes[4].numCuenta, "ABNAAU2436");
    strcpy(variosClientes.Clientes[4].tipoCuenta, "corriente");
    variosClientes.Clientes[4].fecha.dia = 18;
    variosClientes.Clientes[4].fecha.mes = 3;
    variosClientes.Clientes[4].fecha.anho = 2015;

    variosClientes.numClientes = 5;

    cout << "\nBienvenido a GesBANCO--Sistema gestor de entidades bancarias.\n";
    do {

        opcion = menu();

        switch ( opcion ) {
            case 1: listarClientes ( variosClientes );
                    break;
            case 2: cout << "\nSe debe implementar la funcionalidad";
                    break;
            case 3:
            {
                unsigned int id;

                BuscarPorDNI (variosClientes, id);
                if(id!=101){
                    eliminarCliente(variosClientes, id);
                    cout << "Cliente eliminado con exito\n";
                }
            }
                break;
            case 4:
            {
                char NCuenta[MAXNUMCUENTA];
                leerCadena("Inserte numero de cuenta: ", NCuenta);
                BuscarPorNCuenta( variosClientes, NCuenta);
            }
                break;
            case 5:
            {
                unsigned int id;

                BuscarPorDNI (variosClientes, id);
                if(id!=101)
                    mostrarCliente(variosClientes.Clientes[id]);
            }
                break;
            case 6:
            {
                unsigned int modificacion;
                unsigned int id;
                char seguir[3];

                BuscarPorDNI( variosClientes,id); //Pedimos un DNI con el que obtenemos la id del cliente con ese DNI
                if(id!=101){    //Salvo que no se introduzca el DNI se ejecuta el siguiente codigo
                    mostrarCliente(variosClientes.Clientes[id]); //Mostramos los datos del cliente con la id obtenida
                    do{
                        menuDeModificacion(modificacion); //Mostramos un menu con los posibles cambios
                        selectorDeModificacion(variosClientes,modificacion,id); //Se efectuan los cambios en funcion delo seleccionado anteriormente
                        mostrarCliente(variosClientes.Clientes[id]); //Volvemos a mostrar el cliente con los datos modificados
                        leerCadena("Quieres hacer mas cambios? ",seguir); //Preguntamos si quiere hacer mas cambios, de lo contrario se vuleve al menu principal

                    }while (!strcmp(seguir,"si")|| !strcmp(seguir,"Si")|| !strcmp(seguir,"s")|| !strcmp(seguir,"S"));
                }
            }
                break;
            case 7: visualizadorTipoCuenta(variosClientes);
                    break;
            case 8: ListarDNIErroneos(variosClientes);
                    break;
            case 9: cout << "\nGracias por utilizar los servicios de GesBANCO.\n";
                    break;
            default:cout << "Opcion no valida\n" << endl;
        }
    } while ( opcion != 9 );
    return 0;
}

int menu()
{
    int opcion;
    cout << "\n######################################################\n";
    cout << "\nQue operacion desea realizar?";
    do {
        cout << "\n1. Listar clientes";
        cout << "\n2. Insertar cliente";
        cout << "\n3. Eliminar cliente";
        cout << "\n4. Buscar cliente por NumCuenta";
        cout << "\n5. Buscar cliente por DNI";
        cout << "\n6. Modificar datos de un cliente";
        cout << "\n7. Visualizar clientes por cada tipo de cuenta";
        cout << "\n8. Buscar DNIs invalidos";
        cout << "\n9. Salir\n";
        cout << "\n######################################################\n";
        opcion = leerEntero ( "Opcion: ");

    } while ( opcion < 0 || opcion > 10 );

    return opcion;
}

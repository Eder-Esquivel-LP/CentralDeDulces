#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#define Productos 15
#define Informacion 5

//COLORES DE TEXTO
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

void Altas_Inventario(int fCED[Productos][Informacion]);
void Bajas_Inventario(int fCED[Productos][Informacion]);
void Cambios(int fCED[Productos][Informacion]);
void ReportesArchivos(int fCED[Productos][Informacion]);
void imprimirlinea();
void Recorrer(int a[Productos][Informacion]);
void ImprimirProductos(int fCED[Productos][Informacion]);


int cant_p = 0;
char c;

main()
{
  int opcion;
  int resp,i;
  int CED[Productos][Informacion]={NULL};

  do
  {
   system("cls");
    printf("%68s", "Central de dulces \n\n ");
    printf("%79s", "****************** MENU PRINCIPAL ****************\n");
    printf("%80s", "* 1. Altas a inventario                          *\n");
    printf("%80s", "* 2. Bajas a inventario                          *\n");
    printf("%80s", "* 3. Cambios                                     *\n");
    printf("%80s", "* 4. Reportes                                    *\n");
    printf("%80s", "* 5. Salir                                       *\n");
    printf("%80s", "**************************************************\n");
    printf("Ingrese la opcion que desea ejecutar: ");
    fflush(stdin);
    scanf("%d", &resp);

     switch(resp)
    {
      case 1:

        Altas_Inventario(CED);
        break;

      case 2:
        Bajas_Inventario(CED);
        break;

      case 3:
        Cambios(CED);
        break;

      case 4:

        do
        {

            system("cls");
            printf("%80s", "****************** MENU DE REPORTES ****************\n");
            printf("%80s", "* 1. Reportes por Pantalla                         *\n");
            printf("%80s", "* 2. Reportes por archivos                         *\n");
            printf("%80s", "* 3. Regresar al menu principal                    *\n");
            printf("\nIngrese la opcion que desea ejecutar: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    ImprimirProductos(CED);
                    system("pause");
                    break;

                case 2:

                    ReportesArchivos(CED);
                    break;

                case 3:
                    break;
                default:

                    printf("\n\t\t\t\t\tERROR!!!\n\t\t\t\tOPCION INGRESADA NO VALIDA");

                    getch();
                    break;

                }

            }while(opcion !=3);
        break;

      case 5:

          	printf(GREEN " \n\nUsted ha salido del programa exitosamente...." RESET);

          	system("pause>nul");
        break;


        default:

            printf(RED "\n\t\t\t\t\tERROR!!!\n\t\t\t\tOPCION INGRESADA NO VALIDA" RESET);

            getch();

    }


  }while (resp !=5);
}




int contador=0;
void Altas_Inventario(int fCED[Productos][Informacion]) //Funcion de las Altas a inventario (case 1)
{
    char resp = 's',c;
    int clave;
    bool clave_valida=false, clave_existe=false;
    int i, j, k=0;
    char lleno = 'f';

    while (resp =='s' && contador!=Productos)
    {
        system("cls");
        printf("\t\t\t ALTA INVENTARIO\n\n");
        do {
        do {
            printf("\nIngrese la clave del producto: ");
            if (scanf("%d%c", &clave, &c) != 2 || c != '\n') {
                printf(RED "ERROR: Debe ingresar solo numeros enteros!\n" RESET);
                while (getchar() != '\n');
            } else if (clave < 1000 || clave > 9999) {
                printf(RED "ERROR: Solo se admiten claves de 4 numeros!\n" RESET);
            } else {
                clave_valida = true;
            }
        } while (!clave_valida);

        clave_existe = false;
        for (i = 0; i < Productos; i++) {
            if (fCED[i][0] == clave) {
                clave_existe = true;
                printf(RED "ERROR: La clave ingresada, ya existe utilice otra!\n\n" RESET);
                break;
            }
        }

        if (!clave_existe) {
            for (i = 0; i < Productos; i++) {
                if (fCED[i][0] == 0) {
                    fCED[i][0] = clave;
                    break;
                }
            }
        }
    } while (!clave_valida || clave_existe );



        do
        {
            do
            {
                printf("\nIngresa la cantidad de productos en existencia:  ");
                if (scanf("%d%c", & fCED[i][1], &c) != 2 || c != '\n')
                {

		            printf(RED "ERROR: Debe ingresar solo numeros enteros!\n" RESET);

                    while (getchar() != '\n');
                }

                 if(fCED[i][1]<=0)
                {

                    printf(RED "ERROR: La cantidad de existencia no puede ser 0 o inferior!\n" RESET);

                }

                else
                {
                    break;
                }
                } while (1);
        }
        while (fCED[i][1] <= 0);

       do
        {
            do
            {
                printf("\nIngresa la cantidad de stock:  ");
                if (scanf("%d%c", & fCED[i][2], &c) != 2 || c != '\n')
                {
		            printf(RED "ERROR: Debe ingresar solo numeros enteros!\n" RESET);
                    while (getchar() != '\n');
                }

                if(fCED[i][2] < fCED[i][1])
                {
		            printf(RED "ERROR: La cantidad de stock no puede ser inferior a la de existencia!\n" RESET);
                }

                if(fCED[i][2] == fCED[i][1])
                {
		            printf(RED "ERROR: La cantidad de stock no puede ser igual a la de existencia!\n" RESET);
                }

                if(fCED[i][2] == 0)
                {
		            printf(RED "ERROR: La cantidad de stock no puede ser igual a 0!\n" RESET);
                }

                else
                {
                    break;
                }
                } while (1);
        }
        while (fCED[i][2] <= 0 || (fCED[i][2] < fCED[i][1]) ||fCED[i][2] == fCED[i][1]);


        do
        {
            do
            {
                printf("\nIngresa el precio de compra: $");
                if (scanf("%d%c", & fCED[i][3], &c) != 2 || c != '\n')
                {

		            printf(RED "ERROR: Debe ingresar solo numeros enteros!\n" RESET);

                    while (getchar() != '\n');
                }
                if(fCED[i][3] <= 0)
                {

		            printf(RED "ERROR: El precio de compra no puede ser igual o inferior a 0!\n" RESET);

                }
                else
                {
                    break;
                }
                } while (1);
        }while(fCED[i][3] < 0);

        do
        {
            do
            {
                printf("\nIngresa el precio de venta: $");
                if (scanf("%d%c", & fCED[i][4], &c) != 2 || c != '\n')
                {
		            printf(RED "ERROR: Debe ingresar solo numeros enteros!\n" RESET);
                    while (getchar() != '\n');
                }

                if(fCED[i][4] < fCED[i][3])
                {
		            printf(RED "ERROR: El precio de venta no puede ser inferio al precio de compra!\n" RESET);
                }

                if(fCED[i][4] == fCED[i][3])
                {
		            printf(RED "ERROR: El precio de venta no puede ser igual al precio de compra!\n" RESET);
                }

                if(fCED[i][4] == 0)
                {
		            printf(RED "ERROR: EL precio de compra no puede ser igual o 0!\n" RESET);
                }

                else
                {
                    break;
                }
                } while (1);
        }
        while(fCED[i][4] == 0 || (fCED[i][4] < fCED[i][3])|| fCED[i][4] == fCED[i][3]);


        printf(GREEN "\n\n\t\t*El producto ha sido agregada correctamente.*\n" RESET);


        contador=contador+1;

        do
        {
            printf("\n\t\t\tDesea ingresar otro producto?: s/n: ");
            fflush(stdin);
            scanf("%c", &resp);
        }
        while(resp != 's' && resp != 'n');
    }

    if(resp!='n')
    {

    if(contador==Productos)
    {
        printf(RED"\nSolo hay limite de %d productos para registrar\n" RESET ,Productos) ;
        system("pause");
    }
    }
}




void Bajas_Inventario(int fCED[Productos][Informacion])
{
    int i;
    char Resp;
    int Prod;
    int claveprod;
    int encontrado = 0; // bandera que indica si se encontró el producto
    system("cls");
    printf("\t\t\t\t\t BAJA INVENTARIO\n\n");

    ImprimirProductos(fCED);

    printf("\n\nIngrese la clave del producto:");
    scanf("%d",&claveprod);

    for(int j = 0; j<Productos; j++ )
    {

        if (claveprod == fCED [j] [0])

        {
        	// Se encontró el producto
            encontrado = 1;
            printf("\n\n");
            imprimirlinea(),
            printf("\n\t|%20s | %20s |%18s |%20s |%19s |","Clave","Existencia","stock","Compra","Venta");
            imprimirlinea(),
            printf("\n\t|%20d |%18d    |%18d |%20d |%20d|",fCED[j][0],fCED[j][1],fCED[j][2],fCED[j][3],fCED[j][4]);
            imprimirlinea(),
            printf("\n\nEsta seguro de dar de baja el producto: SI/NO ");
            fflush(stdin);
            scanf("%c",&Resp);


            if(Resp=='S'||Resp=='s')
            {
            	 // Dar de baja el producto
                fCED[j][0] = NULL; // Marcar el código como inválido
                fCED[j][1] = NULL; // Marcar el código como inválido
                fCED[j][2] = NULL; // Marcar el código como inválido
                fCED[j][3] = NULL; // Marcar el código como inválido
                fCED[j][4] = NULL; // Marcar el código como inválido

                printf(GREEN "El producto ha sido dado de baja.\n" RESET);getch();
                contador=contador-1;
                Recorrer(fCED);

			}
			else
            {
				 printf(YELLOW "El producto no ha sido dado de baja.\n" RESET);getch();

				 return;
			}
			break;
        }

        if (encontrado) {
            break;
        }

    }
// Si no se encontró el producto, mostrar un mensaje
    if (!encontrado)
        {

            printf(RED"\n\n\t\t\t\t\tPRODUCTO INEXISTENTE"RESET);
            system("pause>nul");

            getch();
            return;
        }

}

void imprimirlinea()
{
    printf("\n\t+---------------------+----------------------+-------------------+---------------------+--------------------+");
}

void Recorrer(int a[Productos][Informacion])
{
    int i;

    for(i=0;i<Productos;i++)
    {
        if(a[i][0]==0)
        {
            if(a[i+1][0]!=0)
            {
                a[i][0]=a[i+1][0];
                a[i][1]=a[i+1][1];
                a[i][2]=a[i+1][2];
                a[i][3]=a[i+1][3];
                a[i][4]=a[i+1][4];

                a[i+1][0]=0;
                a[i+1][1]=0;
                a[i+1][2]=0;
                a[i+1][3]=0;
                a[i+1][4]=0;

                Recorrer(a);
            }

        }

    }

}

void ReportesArchivos(int fCED[Productos][Informacion])
{
    system("cls");
    int i;
    FILE*reporte;
    if((reporte=fopen("Central de Dulces.txt","w"))==NULL)
    {
        puts(RED "No puede abrirse el archivo.\n"RESET);
    }
    else
    {
        fprintf(reporte,"\n\t+---------------------+----------------------+-------------------+---------------------+--------------------+");
        fprintf(reporte,"\n\t|%20s | %20s |%18s |%20s |%19s |","Clave","Existencia","stock","Compra","Venta");
        fprintf(reporte,"\n\t+---------------------+----------------------+-------------------+---------------------+--------------------+");
        for(i=0;i<Productos;i++)
        {

            if(fCED[i][0]!=0)
            {
            fprintf(reporte,"\n\t|%20d |%18d    |%18d |%20d |%20d|",fCED[i][0],fCED[i][1],fCED[i][2],fCED[i][3],fCED[i][4]);
            fprintf(reporte,"\n\t+---------------------+----------------------+-------------------+---------------------+--------------------+");
            }
        }

        fclose(reporte);

        printf(GREEN"Reporte generado\n\n"RESET);

        system("pause");
    }



}

void ImprimirProductos(int fCED[Productos][Informacion])
{
    int i;
    imprimirlinea();
    printf("\n\t|%20s | %20s |%18s |%20s |%19s |","Clave","Existencia","stock","Compra","Venta");
    imprimirlinea();
    for(i=0;i<Productos;i++)
        {
            if(fCED[i][0]!=0)
            {
                printf("\n\t|%20d |%18d    |%18d |%20d |%20d|",fCED[i][0],fCED[i][1],fCED[i][2],fCED[i][3],fCED[i][4]);
                imprimirlinea();
            }
         }
    printf("\n\n");

}

void Cambios(int fCED[Productos][Informacion])
{
    int i = 0;
	int opcion = 0;
	int Producto = 0;
	int DA = 0;
	int encontrado=0;
	bool clave_valida ,clave_existe;
    system("cls");
	printf("\t\t\t\t\t CAMBIOS INVENTARIO\n\n");
	ImprimirProductos(fCED);

	printf("\n Ingrese el codigo del producto: ");
	scanf("%d", &Producto);

    for(i=0;i<Productos;i++)
    {
        if(Producto==fCED[i][0])
        {
            encontrado=1;
            int fila_actualizada = i;
            do{
                printf("\n Campos a modificar: "
                            "\n 1.-Clave del producto"
                            "\n 2.-Existencia"
                            "\n 3.-Stock"
                            "\n 4.-Precio de compra"
                            "\n 5.-Precio de venta"
                            "\n 6.-Muestra por pantalla el registro actualizado"
                            "\n 7.-Salir\n");
                scanf("%d", &opcion);
                switch(opcion){
                    case 1:
                        do {
                            clave_valida = false; // Inicializamos la variable en cada iteración del bucle externo
                            do {
                                printf("\nIngrese la clave del producto: ");
                                if (scanf("%d%c", &DA, &c) != 2 || c != '\n')
                                {

                                    printf(RED "ERROR: Debe ingresar solo numeros enteros!\n"RESET);

                                    while (getchar() != '\n');
                                }
                                else if(DA<1000 || DA>9999 )
                                {

                                    printf(RED "ERROR: Solo se admiten claves de 4 numeros!\n"RESET);

                                }
                                else
                                {
                                    clave_valida = true; // Actualizamos la variable si la clave es válida
                                    break;
                                }
                            } while (true);

                            if (clave_valida) {
                                clave_existe = false;
                                for (i = 0; i < Productos ; i++) { // -1 para no revisar la fila extra
                                    if (fCED[i][0] == DA) {
                                        clave_existe = true;
                                        printf(RED"*La clave ingresada, ya existe utilice otra.*\n\n"RESET);
                                        break;
                                    }
                                }

                                if (!clave_existe) {
                                fCED[fila_actualizada][0] = DA; // Actualizamos la clave en la fila actualizada
                                break;
                            }
                            }
                        } while (clave_existe || i == Productos);

                        printf(GREEN"\n\n\t\t*El producto ha sido actualizado correctamente.*\n"RESET);

                        break;

                    case 2:
                        do
                        {
                            do
                            {
                                printf("\nIngresa la cantidad de productos en existencia:  ");
                                if (scanf("%d%c", &DA, &c) != 2 || c != '\n')
                                {

                                    printf(RED"ERROR: Debe ingresar solo numeros enteros!\n"RESET);

                                    while (getchar() != '\n');
                                }

                                if(DA<0)
                                {

                                    printf(RED"ERROR: La cantidad de existencia no puede ser inferior a 0!\n"RESET);

                                }

                                if(DA>=fCED[fila_actualizada][2])
                                {

                                    printf(RED"ERROR: La cantidad de existencia no puede ser mayor o igual a la de stock!\n"RESET);

                                }
                                else
                                {
                                    break;
                                }
                                } while (1);
                        }
                        while (DA < 0||DA>=fCED[i][2]);

                        fCED[fila_actualizada][1]=DA;
                        printf(GREEN"\n\n\t\t*El producto ha sido actualizado correctamente.*\n"RESET);

                        break;
                    case 3:
                        do
                        {
                            do
                            {
                                printf("\nIngresa la cantidad de stock:  ");
                                if (scanf("%d%c", &DA, &c) != 2 || c != '\n')
                                {

                                    printf(RED"ERROR: Debe ingresar solo numeros enteros!\n"RESET);

                                    while (getchar() != '\n');
                                }

                                if(DA< fCED[fila_actualizada][1])
                                {

                                    printf(RED"ERROR: La cantidad de stock no puede ser inferior a la de existencia!\n"RESET);

                                }

                                if(DA== fCED[fila_actualizada][1])
                                {

                                    printf(RED"ERROR: La cantidad de stock no puede ser igual a la de existencia!\n"RESET);

                                }

                                else
                                {
                                    break;
                                }
                                } while (1);
                        }
                        while (DA < 0 || (DA < fCED[fila_actualizada][1]));

                        fCED[fila_actualizada][2]=DA;
                        printf(GREEN"\n\n\t\t*El producto ha sido actualizado correctamente.*\n"RESET);

                        break;
                    case 4:
                        do
                        {
                            do
                            {
                                printf("\nIngresa el precio de compra: $");
                                if (scanf("%d%c", & DA, &c) != 2 || c != '\n')
                                {

                                    printf(RED"ERROR: Debe ingresar solo numeros enteros!\n"RESET);

                                    while (getchar() != '\n');
                                }
                                if(DA <= 0)
                                {

                                    printf(RED"ERROR: El precio de compra no puede ser igual o inferior a 0!\n"RESET);

                                }

                                if(DA >= fCED[fila_actualizada][4])
                                {

                                    printf(RED"ERROR: El precio de compra no puede ser igual o mayor al precio de venta!\n"RESET);

                                }

                                else
                                {
                                    break;
                                }
                                } while (1);
                        }while(DA < 0||DA>=fCED[fila_actualizada][4]);

                        fCED[fila_actualizada][3]=DA;
                        printf(GREEN"\n\n\t\t*El producto ha sido actualizado correctamente.*\n"RESET);

                        break;
                    case 5:
                        do
                        {
                            do
                            {
                                printf("\nIngresa el precio de venta: $");
                                if (scanf("%d%c", & DA, &c) != 2 || c != '\n')
                                {

                                    printf(RED"ERROR: Debe ingresar solo numeros enteros!\n"RESET);

                                    while (getchar() != '\n');
                                }

                                if(DA <= fCED[fila_actualizada][3])
                                {

                                    printf(RED"ERROR: El precio de venta no puede ser igual o menor al precio de compra!\n"RESET);

                                }

                                if(DA == 0)
                                {

                                    printf(RED"ERROR: EL precio de compra no puede ser igual o 0!\n"RESET);

                                }

                                else
                                {
                                    break;
                                }
                                } while (1);
                        }
                        while(DA == 0 || DA <= fCED[fila_actualizada][3]);

                        fCED[fila_actualizada][4]=DA;
                        printf(GREEN"\n\n\t\t*El producto ha sido actualizado correctamente.*\n"RESET);

                        break;
                    case 6:
                        imprimirlinea();
                        printf("\n\t|%20s | %20s |%18s |%20s |%19s |","Clave","Existencia","stock","Compra","Venta");
                        imprimirlinea();
                        printf("\n\t|%20d |%18d    |%18d |%20d |%20d|",fCED[fila_actualizada][0],fCED[fila_actualizada][1],fCED[fila_actualizada][2],fCED[fila_actualizada][3],fCED[fila_actualizada][4]);
                        imprimirlinea();
                        printf("\n ");
                        system("pause");
                        printf("\n ");
                        break;
                    case 7:
                        printf("FIN");
                        break;

                    default:
                        printf("\n\t\t\t\t\t ERROR!!! \n\t\t\t\t OPCION INGRESADA NO VALIDA ");
                        break;
                }
            }while( opcion!=7);
        }

        if (encontrado) {
            break;
        }
    }

    if (!encontrado)
        {

            printf(RED"\n\n\t\t\t\t\tPRODUCTO INEXISTENTE"RESET);
            system("pause>nul");

            getch();
            return;
        }


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100

int numProducts = 0;
char productIDs[MAX_PRODUCTS][11];
char productNames[MAX_PRODUCTS][50];
char productQuantities[MAX_PRODUCTS][20];
char ownerNames[MAX_PRODUCTS][50];
char ownerCellphones[MAX_PRODUCTS][20];
char ownerEmails[MAX_PRODUCTS][50];
char ownerAddresses[MAX_PRODUCTS][50];

void addProduct();
void viewProducts();
void generateID(char *id);

int main(int argc, char *argv[]) {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("*****Almacenes de todo*****\n");
        printf("Menu de opciones:\n");
        printf("1. Agregar Producto\n");
        printf("2. Ver productos\n");
        printf("3. Salir\n");
        printf("Ingresar opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ESCRIBIR LA INFORMACION SIN DEJAR ESPACIOS O UTILIZAR LOS SIGUIENTES SIGNOS ( : , ; , . , - , _ )\n");
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                printf("*****Gracias por usar la bodega****");
                exit(0);
        }
    }
}

void generateID(char *id) {
    id[0] = 'A' + rand() % 26;
    id[1] = 'A' + rand() % 26;
    for (int i = 2; i < 10; i++) {
        id[i] = '0' + rand() % 10;
    }
    id[10] = '\0';
}

void addProduct() {
    if (numProducts == MAX_PRODUCTS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("\n");
    printf("Ingrese el nombre del Arrendador %d: ", numProducts + 1);
    scanf("%s", ownerNames[numProducts]);
    printf("Ingrese el celular del Arrendador %d: ", numProducts + 1);
    scanf("%s", ownerCellphones[numProducts]);
    printf("Ingrese el correo del Arrendador %d: ", numProducts + 1);
    scanf("%s", ownerEmails[numProducts]);
    printf("Ingrese la direccion del Arrendador %d: ", numProducts + 1);
    scanf("%s", ownerAddresses[numProducts]);
    printf("Ingrese el producto %d: ", numProducts + 1);
    scanf("%s", productNames[numProducts]);
    printf("Ingrese la cantidad o unidades del producto %d: ", numProducts + 1);
    scanf("%s", productQuantities[numProducts]);

    generateID(productIDs[numProducts]);

    numProducts++;
    printf("\n");
    printf("********Producto agregado exitosamente********\n\n");
}

void viewProducts() {
    int i;
    if (numProducts == 0) {
        printf("No hay productos para mostrar.\n");
        return;
    }

    for (i = 0; i < numProducts; i++) {
        printf("\n");
        printf("*****Datos del Arrendador y su producto:*****\n\n");
        printf("ID: %s\n", productIDs[i]);
        printf("Nombre del arrendador: %s\n", ownerNames[i]);
        printf("Celular del arrendador: %s\n", ownerCellphones[i]);
        printf("Correo del arrendador: %s\n", ownerEmails[i]);
        printf("Direccion del arrendador: %s\n", ownerAddresses[i]);
        printf("Producto: %s\n", productNames[i]);
        printf("La cantidad guardada: %s\n", productQuantities[i]);
    }
}

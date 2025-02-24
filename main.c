#include <stdio.h>

/*Programa que simula una agenda digital de 100 contactos*/

struct agenda
{
    char nombre[50];
    char num_movil[15];
    char email[50];
    int id;
};


//Prototipos de funciones.
void ingresarContacto(int, struct agenda contacto[100]);
int buscarID(char[30], struct agenda contacto[100]);
void informacionContacto(int, struct agenda contacto[100]);
void eliminarContacto(int, struct agenda contacto[100]);

int main() {
    struct agenda contacto[100];
    int op, i, j, k, num_contacto=0, buscar_id, id_encontrado;
    char buscar_nombre[30];

    printf("Agenda Digital de 100 contactos. \n");

    do
    {
        printf("MENU: \n");
        printf("1. Agregar contacto  \n");
        printf("2. Mostrar contacto  \n");
        printf("3. Buscar contacto   \n");
        printf("4. Eliminar contacto \n");
        printf("0. Salir \n");
        printf("Seleccione una opcion\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            __fpurge(stdin);
            printf("1. Nuevo contacto. \n");

            if (num_contacto<100){
                printf("Ingrese la informacion solicitada: \n");

                ingresarContacto(num_contacto,contacto);

                printf("Contacto agregado con exito.\n");
                contacto[num_contacto].id = num_contacto;
                num_contacto++;
            } else {
                printf("La agenda está llena.\n");
            }
            
            break;
        
        case 2:
             __fpurge(stdin);
            printf("2. Mostrar contacto. \n");
            printf("Ingrese el nombre del contacto que desea imprimir: \n");
            scanf("%[^\n]",buscar_nombre);
            __fpurge(stdin);

            id_encontrado = buscarID(buscar_nombre,contacto);
    
            if (id_encontrado != 200){
                printf("Contacto encontrado: \n");
                informacionContacto(id_encontrado, contacto);
                printf("ID:%d \n",id_encontrado);
            } else if (id_encontrado == 200) {
                printf("Contacto NO encontrado. \n");
            }
            
            break;
        
        case 3:
            __fpurge(stdin);
            printf("3. Buscar contacto. \n");
            printf("Ingrese el nombre del contacto que desea buscar: \n");
            scanf("%[^\n]",buscar_nombre);
            __fpurge(stdin);

            id_encontrado = buscarID(buscar_nombre,contacto);
    
            if (id_encontrado != 200){
                printf("Contacto encontrado: \n");
                informacionContacto(id_encontrado, contacto);
                printf("ID:%d \n",id_encontrado);
            } else if (id_encontrado == 200) {
                printf("Contacto NO encontrado. \n");
            }
            break;

        case 4:
            __fpurge(stdin);
            printf("5. Eliminar contacto. \n");
            printf("Ingrese el nombre del contacto que desea eliminar: \n");
            scanf("%[^\n]",buscar_nombre);
            __fpurge(stdin);

            id_encontrado = buscarID(buscar_nombre,contacto);
    
            if (id_encontrado != 200){
                eliminarContacto(id_encontrado, contacto);
                printf("Contacto elimanado con exito. \n");
            } else if (id_encontrado == 200) {
                printf("Contacto NO encontrado. \n");
            }
            break;
        
        case 0:
        
            printf("Saliendo.... \n");
            
            break;
            
        default: 
            printf("Opcion no valida. \n");
        }

    } while (op != 0);
    

    return 0;

}

// Definición de funciones.
// Función que solicita la infomación de un nuevo contacto.
void ingresarContacto(int num_contacto, struct agenda contacto[100]){
    printf("Nombre: \n");
    scanf("%[^\n]",contacto[num_contacto].nombre);
    __fpurge(stdin);
    printf("Numero movil: \n");
    scanf("%[^\n]",contacto[num_contacto].num_movil);
    __fpurge(stdin);
    printf("Email: \n");
    scanf("%[^\n]",contacto[num_contacto].email);
    __fpurge(stdin);

}

// Función para buscar la ID de un contacto.
int buscarID(char buscar_nombre[30], struct agenda contacto[100]){
    int i=0, j, k=0, buscar_id;
    do{
        for (j = 0; buscar_nombre[j] != '\0'; j++){
            if (contacto[i].nombre[j] == buscar_nombre[j]){
                buscar_id = i;
            } else {
                i++;
            }
            k++;
        }
    } while (k <= 100);

    if (i >= 100){
        buscar_id = 200;
        return buscar_id;
    } else {
        return buscar_id;
    }
}

// Función para imprimir la información del contacto.
void informacionContacto(int id_encontrado, struct agenda contacto[100]){
    printf("Nombre: %s \n",contacto[id_encontrado].nombre);
    printf("Numero movil: %s \n",contacto[id_encontrado].num_movil);
    printf("Email: %s \n",contacto[id_encontrado].email);
}

// Función para "eliminar" un contacto.
void eliminarContacto(int id_encontrado, struct agenda contacto[100]){
    contacto[id_encontrado].nombre[0] = ' ';
    contacto[id_encontrado].nombre[1] = ' ';
    contacto[id_encontrado].num_movil[15] = ' ';
    contacto[id_encontrado].email[50] = ' ';
    contacto[id_encontrado].id = 300;
}
#include <stdio.h>
#include "funciones.h"

int main() {
    int opc, idEmpleado, diasSolicitados;
    char rutaArchivo[255];

    do {
        printf("\nMenu de Gestión de Recursos Humanos:\n");
        printf("1. Registrar Vacaciones\n");
        printf("2. Mostrar Vacaciones\n");
        printf("3. Aprobar Vacaciones\n");
        printf("4. Cargar asistencias desde archivo\n");
        printf("5. Mostrar asistencias\n");
        printf("6. Calcular atrasos\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Ingrese ID del empleado: ");
                scanf("%d", &idEmpleado);
                registrarVacaciones(idEmpleado);
                break;
            case 2:
                printf("Ingrese ID del empleado: ");
                scanf("%d", &idEmpleado);
                mostrarVacaciones(idEmpleado);
                break;
            case 3:
                printf("Ingrese ID del empleado: ");
                scanf("%d", &idEmpleado);
                printf("Ingrese días solicitados: ");
                scanf("%d", &diasSolicitados);
                aprobarVacaciones(idEmpleado, diasSolicitados);
                break;
            case 4:
                printf("Ingrese la ruta del archivo de asistencias: ");
                scanf("%s", rutaArchivo);
                cargarAsistenciasDesdeArchivo(rutaArchivo);
                break;
            case 5:
                printf("Ingrese ID del empleado: ");
                scanf("%d", &idEmpleado);
                mostrarAsistencias(idEmpleado);
                break;
            case 6:
                printf("Ingrese ID del empleado: ");
                scanf("%d", &idEmpleado);
                calcularAtrasos(idEmpleado);
                break;
            case 7:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opc != 7);

    return 0;
}

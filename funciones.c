#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarVacaciones(int idEmpleado) {
    struct Vacaciones vacaciones = {idEmpleado, 15, 0};  // Ejemplo: 15 días disponibles
    FILE *archivo = fopen("vacaciones.dat", "wb");
    fwrite(&vacaciones, sizeof(struct Vacaciones), 1, archivo);
    fclose(archivo);
    printf("Vacaciones registradas para el empleado %d.\n", idEmpleado);
}

void mostrarVacaciones(int idEmpleado) {
    struct Vacaciones vacaciones;
    FILE *archivo = fopen("vacaciones.dat", "rb");
    while (fread(&vacaciones, sizeof(struct Vacaciones), 1, archivo)) {
        if (vacaciones.idEmpleado == idEmpleado) {
            printf("Empleado %d: Días disponibles: %d, Días tomados: %d\n", idEmpleado, vacaciones.diasDisponibles, vacaciones.diasTomados);
            break;
        }
    }
    fclose(archivo);
}

void aprobarVacaciones(int idEmpleado, int diasSolicitados) {
    struct Vacaciones vacaciones;
    FILE *archivo = fopen("vacaciones.dat", "rb+");
    while (fread(&vacaciones, sizeof(struct Vacaciones), 1, archivo)) {
        if (vacaciones.idEmpleado == idEmpleado) {
            if (vacaciones.diasDisponibles >= diasSolicitados) {
                vacaciones.diasDisponibles -= diasSolicitados;
                vacaciones.diasTomados += diasSolicitados;
                fseek(archivo, -sizeof(struct Vacaciones), SEEK_CUR);
                fwrite(&vacaciones, sizeof(struct Vacaciones), 1, archivo);
                printf("Vacaciones aprobadas para el empleado %d.\n", idEmpleado);
            } else {
                printf("No hay suficientes días disponibles.\n");
            }
            break;
        }
    }
    fclose(archivo);
}

void cargarAsistenciasDesdeArchivo(char *rutaArchivo) {
    FILE *archivo = fopen(rutaArchivo, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s.\n", rutaArchivo);
        return;
    }

    struct Asistencia asistencia;
    FILE *archivoAsistencias = fopen("asistencias.dat", "wb");

    while (fscanf(archivo, "%d %s %s %s", &asistencia.idEmpleado, asistencia.fecha, asistencia.horaEntrada, asistencia.horaSalida) == 4) {
        // Calcular atrasos automáticamente (Ejemplo: retraso si hora de entrada es después de las 09:00)
        asistencia.atrasos = strcmp(asistencia.horaEntrada, "09:00") > 0 ? 1 : 0;

        fwrite(&asistencia, sizeof(struct Asistencia), 1, archivoAsistencias);
    }

    fclose(archivo);
    fclose(archivoAsistencias);
    printf("Asistencias cargadas desde el archivo %s.\n", rutaArchivo);
}

void mostrarAsistencias(int idEmpleado) {
    struct Asistencia asistencia;
    FILE *archivo = fopen("asistencias.dat", "rb");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo de asistencias.\n");
        return;
    }

    while (fread(&asistencia, sizeof(struct Asistencia), 1, archivo)) {
        if (asistencia.idEmpleado == idEmpleado) {
            printf("Empleado %d - Fecha: %s - Entrada: %s - Salida: %s - Atrasos: %d\n",
                   idEmpleado, asistencia.fecha, asistencia.horaEntrada, asistencia.horaSalida, asistencia.atrasos);
        }
    }

    fclose(archivo);
}

void calcularAtrasos(int idEmpleado) {
    struct Asistencia asistencia;
    int totalAtrasos = 0;
    FILE *archivo = fopen("asistencias.dat", "rb");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo de asistencias.\n");
        return;
    }

    while (fread(&asistencia, sizeof(struct Asistencia), 1, archivo)) {
        if (asistencia.idEmpleado == idEmpleado) {
            totalAtrasos += asistencia.atrasos;
        }
    }

    fclose(archivo);
    printf("Total de atrasos para el empleado %d: %d.\n", idEmpleado, totalAtrasos);
}

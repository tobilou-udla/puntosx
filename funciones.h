struct Vacaciones {
    int idEmpleado;
    int diasDisponibles;
    int diasTomados;
};

struct Asistencia {
    int idEmpleado;
    char fecha[10];  // Formato: DD/MM/AAAA
    char horaEntrada[5];  // Formato: HH:MM
    char horaSalida[5];   // Formato: HH:MM
    int atrasos;  // Número de retrasos
};

// Funciones para vacaciones
void registrarVacaciones(int idEmpleado);
void mostrarVacaciones(int idEmpleado);
void aprobarVacaciones(int idEmpleado, int diasSolicitados);

// Funciones para asistencias
void cargarAsistenciasDesdeArchivo(char *rutaArchivo);
void mostrarAsistencias(int idEmpleado);
void calcularAtrasos(int idEmpleado);

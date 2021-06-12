#include <iostream>
#include "./include/Course.h"
#include "./include/CourseMapper.h"
#include "./include/Student.h"
#include "./include/StudentMapper.h"
#include "./include/AssistanceManager.h"
#include <iostream>

using namespace std;

int main() {
//    CourseMapper *mapeadorCurso = new CourseMapper();
//    StudentMapper *mapeadorAlumno = new StudentMapper();

//    if (!mapeadorCurso->insertCourse(new Course(17, "Otra Materia")))
//        cout << "Error al insertar una materia" << endl;
//
//    if (!mapeadorCurso->updateCourse(10, "Actualizacion Ingles Tecnico I"))
//        cout << "Error al actualizar una materia" << endl;
//
//    if (!mapeadorCurso->deleteCourse(17))
//        cout << "Error al borrar una materia" << endl;
//
//    if (!mapeadorAlumno->insertStudent(alumno))
//        cout << "Error al insertar un estudiante" << endl;
//
//    if (!mapeadorAlumno->updateStudent(18, "Nuevo nombre", "nuevo Apellido"))
//        cout << "Error al actualizar un estudiante" << endl;

//    delete mapeadorCurso;
//    delete mapeadorAlumno;

    // Creo un objero asistencia pasándole el id del curso al que
    // se pretende pasar asistencia
    AssistanceManager *profesor = new AssistanceManager(1);
    profesor->takeAttendance("2021/04/27");

    cout << "\nPresione ENTER para finalizar... ";
    cin.sync();
    cin.get();
    return 0;
}

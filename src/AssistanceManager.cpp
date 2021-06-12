#include "../include/AssistanceManager.h"
#include <fstream>
#include <vector>

/* Cuando se crea un objeto AssistanceManager:
   LLeno el vector de objetos Student con los estudiantes del curso
   obteniendo los códigos del archivo StudentXCourse.txt,
   y la información de los archivos Student.txt y Course.txt respectivamente
*/
AssistanceManager::AssistanceManager(int _idCourse) {
    ifstream fileStudent, fileCourse, fileSXC;
    int idStudent;  // para guardar id estudiante del archivo
    int idCourse;   // para verificar el id curso del archivo
    string nameOfCourse = "", fullName = "";
    bool exit = false;
    vector <Student*> allStudents;
    vector <int> studentsID;

    // Primero, obtengo el nombre del curos del archivo Course.txt
    fileCourse.open("./DB/Course.txt");
    if (fileCourse.is_open()) {
        fileCourse >> idCourse;
        while (!fileCourse.eof() && !exit) {
            getline(fileCourse, nameOfCourse);
            nameOfCourse = nameOfCourse.substr(1, nameOfCourse.length()); // Elimino el blanco de la primarea posición
            if (idCourse == _idCourse) // Si coincide entonces ya tengo el nombre del curso y salgo
                exit = true;
            fileCourse >> idCourse;
        }
    }
    else
        cout << "Error al abrir el archivo Course.txt" << endl;

    fileCourse.close();

    // Seteo los atruburo courseName y courseID
    courseName = nameOfCourse;
    courseID = _idCourse;


    // Segundo, obtengo todos los id de los estudiantes perteneciente al curso
    fileSXC.open("./DB/StudentXCourse.txt");
    if (fileSXC.is_open()) {
        fileSXC >> idCourse >> idStudent;
        while (!fileSXC.eof()) {
            if (idCourse == _idCourse) { // si coincide guardo id del estudiante en el vector
                studentsID.push_back(idStudent);
            }
            fileSXC >> idCourse >> idStudent;
        }
    }
    else
        cout << "Error al abrir el archivo StudentXCourse.txt" << endl;

    fileSXC.close();


    /* Tercero, Cargo en el vector allStudents todos los alumnos del archivo Student.txt
       Para no tener que abrir y cerrar el archivo para obtener los datos
       de los estudiantes del curso correspondiente */

    fileStudent.open("./DB/Student.txt");
    if (fileStudent.is_open()) {
        int pos = 0;
        fileStudent >> idStudent;
        while (!fileStudent.eof()) {
            getline(fileStudent, fullName);
            // Obtuve el nombre y apellido completo con separador |
            // Ahora los separo para guardarlos en los atribtudos name y surname del objeto Student
            pos = fullName.find("|");
            allStudents.push_back(new Student(idStudent, fullName.substr(pos + 2, fullName.length()), fullName.substr(1, pos - 1)));
            fileStudent >> idStudent;
        }
    }
    else
        cout << "Error al abrir el archivo Student.txt" << endl;

    fileStudent.close();

    /* Cuarto, obtengo del vector allStudents los datos de cada alumno y
       los paso al atributo students (Seteo el atributo students) */

    for (unsigned int i = 0; i < studentsID.size(); i++) {
        for (unsigned int j = 0; j < allStudents.size(); j++)
            // Si coincide el identificador entonces lo paso a students
            if (studentsID[i] == allStudents[j]->getIdentifier())
               students.push_back(allStudents[j]);
    }
}

// Formato date = AAAA/MM/DD
void AssistanceManager::takeAttendance(string date) {
     fstream fileAssistance;
     char option;

     fileAssistance.open("./DB/Assistance.txt", ios_base::app | ios_base::in);

     cout << "\nCurso: " << courseName << endl
          << "(Ingresar p <presente> / a <ausente>)" << endl << endl;

     for (unsigned int i = 0; i < students.size(); i++)
        if (fileAssistance.is_open()) {
            cout << students[i]->getSurname() << " " << students[i]->getName() << ": ";
            cin >> option;
            option = toupper(option);

            // Primero, paso al archivo: fecha, cursoID, edtudianteID
            fileAssistance << date << " " << courseID << " " << students[i]->getIdentifier();

            // Segundo, paso al archivo: presente o ausente (1/0)
            if (option == 'P')
                fileAssistance << " " << 1 << endl;
            else
                fileAssistance << " " << 0 << endl;
        }

    fileAssistance.close();
}

void AssistanceManager::showAssistance(string date) {
}

int AssistanceManager::getCourseID() {
    return courseID;
}

string AssistanceManager::getCourseName() {
    return courseName;
}

AssistanceManager::~AssistanceManager() {
    //dtor
}

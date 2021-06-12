#include "../include/StudentMapper.h"
#include <fstream>
#include <vector>
#include <string>

StudentMapper::StudentMapper() {
    //ctor
}

bool StudentMapper::insertStudent(Student *student) {
    bool ok = true;
    fstream fileStudent;

    fileStudent.open("./DB/Student.txt", ios_base::app | ios_base::in);  // Insertar al final del archivo
    if (fileStudent.is_open()) {
        fileStudent << student->getIdentifier() << " " << student->getSurname()
                    << " " << "|" << " " << student->getName() << endl;
    }
    else
        ok = false;

    fileStudent.close();
    return ok;
}

bool StudentMapper::updateStudent(int _identifier, string _newName, string _newSurname) {
    bool ok = true;
    int id;
    string name = _newName;
    string surName = _newSurname;
    string fullName;
    vector <Student*> studentList;
    ifstream fileIN;
    ofstream fileOUT;


    fileIN.open("./DB/Student.txt");
    // Primero, paso todo el contenido del archivo Student.txt a un vector
    if (fileIN.is_open()) {
        fileIN >> id;
        while (!fileIN.eof()) {
            getline(fileIN, fullName);
            // Aca Separar el nombre y el apellido
            int pos = fullName.find("|");
            surName = fullName.substr(0, pos);
            name = fullName.substr(pos + 1, fullName.length() - 1);
            if (id == _identifier) {   // si coincide el id entonces actualizo la información
                name = " " + _newName;
                surName = " " + _newSurname + " ";
            }
            studentList.push_back(new Student(id, name, surName));
            fileIN >> id;
        }
    }
    else
        ok = false;

    fileOUT.open("./DB/Student.txt");
    // Segundo, paso el contenido actualizado del vector al archivo Student.txt
    if (fileOUT.is_open()) {
        for (unsigned int i = 0; i < studentList.size(); i++) {
            fileOUT << studentList[i]->getIdentifier()
                    << studentList[i]->getSurname() << "|"
                    << studentList[i]->getName() << endl;
        }
    }
    else
        ok = false;

    fileIN.close();
    fileOUT.close();

    return ok;
}

bool StudentMapper::deleteStudent(int _identifier) {
    return 0;
}

StudentMapper::~StudentMapper() {
    //dtor
}

#include "../include/CourseMapper.h"
#include <fstream>
#include <vector>

CourseMapper::CourseMapper() {
    //ctor
}

bool CourseMapper::insertCourse(Course *course) {
    bool ok = true;
    fstream fileCourse;

    fileCourse.open("./DB/Course.txt", ios_base::app | ios_base::in);  // Insertar al final del archivo
    if (fileCourse.is_open())
        fileCourse << course->getIdentifier() << " " << course->getName() << endl;
    else
        ok = false;

    fileCourse.close();
    return ok;
}

bool CourseMapper::updateCourse(int _identifier, string _newName) {
    bool ok = true;
    int id;
    string name = _newName;
    vector <Course*> courseList;
    ifstream fileIN;
    ofstream fileOUT;


    fileIN.open("./DB/Course.txt");
    // Primero, paso todo el contenido del archivo Course.txt a un vector
    if (fileIN.is_open()) {
        fileIN >> id;
        while (!fileIN.eof()) {
            getline(fileIN, name);
            if (id == _identifier)   // si coincide el id entonces actualizo la información
                name = " " + _newName;
            courseList.push_back(new Course(id, name));
            fileIN >> id;
        }
    }
    else
        ok = false;

    fileOUT.open("./DB/Course.txt");
    // Segundo, paso el contenido actualizado del vector al archivo Course.txt
    if (fileOUT.is_open()) {
        for (unsigned int i = 0; i < courseList.size(); i++) {
            fileOUT << courseList[i]->getIdentifier()
                    << courseList[i]->getName()
                    << endl;
        }
    }
    else
        ok = false;

    fileIN.close();
    fileOUT.close();

    return ok;
}

bool CourseMapper::deleteCourse(int _identifier) {
    bool ok = true;
    ifstream fileIN;
    ofstream fileOUT;
    vector <Course*> courseList;
    int id, pos = 0;
    string name;

    fileIN.open("./DB/Course.txt");
    if (fileIN.is_open()) {

        // Primero, paso el contenido del archivo a un vector
        fileIN >> id;
        while (!fileIN.eof()) {
            getline(fileIN, name);
            courseList.push_back(new Course(id, name));
            fileIN >> id;
        }

        // Segundo, borro el elemento que coincide con el id

        for (unsigned int i = 0; i < courseList.size(); i++) {
            if (_identifier == courseList[i]->getIdentifier())
                pos = i;
        }

        courseList.erase(courseList.begin() + pos);

    }
    else
        ok = false;

    fileIN.close();
    // Tercero, paso el contenido del vector al archivo Course.txt
    fileOUT.open("./DB/Course.txt");
    if (fileOUT.is_open()) {
        for (unsigned int i = 0; i < courseList.size() - 1; i++) {
            fileOUT << courseList[i]->getIdentifier()
                    << courseList[i]->getName()
                    << endl;
        }
    }
    else
        ok = false;
    fileOUT.close();

    return ok;
}

CourseMapper::~CourseMapper() {
    //dtor
}

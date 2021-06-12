#ifndef STUDENTMAPPER_H
#define STUDENTMAPPER_H
#include "Student.h"

class StudentMapper {
    public:
        StudentMapper();
        bool insertStudent(Student *student);
        bool updateStudent(int _identifier, string _name, string _surname);
        bool deleteStudent(int _identifier);
        virtual ~StudentMapper();
};

#endif // STUDENTMAPPER_H

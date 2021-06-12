#ifndef COURSEMAPPER_H
#define COURSEMAPPER_H
#include "Course.h"

class CourseMapper {
    public:
        CourseMapper();
        bool insertCourse(Course *course);  // falta controlar que no exista el identificador
        bool updateCourse(int _identifier, string _newName);
        bool deleteCourse(int _identifier);
        virtual ~CourseMapper();
};

#endif // COURSEMAPPER_H

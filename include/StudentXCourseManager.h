#ifndef STUDENTXCOURSEMANAGER_H
#define STUDENTXCOURSEMANAGER_H


class StudentXCourseManager {
    public:
        StudentXCourseManager();
        bool insertStudentCourse(int idStudent, int idCourse);
        bool deleteStudent(int idStudent); // Elimina un estudiante de una curso
        bool deleteCourse(int idCourse);   // Elimina un curso y todos sus estudientes
        virtual ~StudentXCourseManager();
};

#endif // STUDENTXCOURSEMANAGER_H

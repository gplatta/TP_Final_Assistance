#ifndef ASSISTANCEMANAGER_H
#define ASSISTANCEMANAGER_H
#include "Student.h"
#include <iostream>
#include <vector>


class AssistanceManager {
    private:
        string courseName;
        int courseID;
        vector <Student*> students;
    public:
        AssistanceManager(int _idCourse);
        void takeAttendance(string date);
        void showAssistance(string date);
        int getCourseID();
        string getCourseName();
        virtual ~AssistanceManager();
};

#endif // ASSISTANCEMANAGER_H

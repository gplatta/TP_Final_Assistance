#ifndef COURSE_H
#define COURSE_H
#include <iostream>

using namespace std;

class Course {
    private:
        int identifier;
        string name;
    public:
        Course();
        Course(int _identifier, string _name);
        void setIdentifier(int _identifier);
        int getIdentifier();
        void setName(string _name);
        string getName();
        virtual ~Course();
};

#endif // COURSE_H

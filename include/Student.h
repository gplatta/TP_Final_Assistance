#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
    private:
        int identifier;
        string name;
        string surname;
    public:
        Student();
        Student(int _identifier, string _name, string _surname);
        void setIdentifier(int _identifier);
        int getIdentifier();
        void setName(string _name);
        string getName();
        void setSurname(string _surname);
        string getSurname();
        virtual ~Student();
};

#endif // STUDENT_H

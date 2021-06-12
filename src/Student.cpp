#include "../include/Student.h"

Student::Student() {
    //ctor
}

Student::Student(int _identifier, string _name, string _surname) {
    identifier = _identifier;
    name = _name;
    surname = _surname;
}

void Student::setIdentifier(int _identifier) {
    identifier = _identifier;
}

int Student::getIdentifier() {
    return identifier;
}

void Student::setName(string _name) {
    name = _name;
}

string Student::getName() {
    return name;
}

void Student::setSurname(string _surname) {
    surname = _surname;
}

string Student::getSurname() {
    return surname;
}

Student::~Student() {
    //dtor
}

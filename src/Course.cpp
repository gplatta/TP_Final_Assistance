#include "../include/Course.h"

Course::Course() {
    //ctor
}

Course::Course(int _identifier, string _name) {
    identifier = _identifier;
    name = _name;
}

void Course::setIdentifier(int _identifier) {
    identifier = _identifier;
}

int Course::getIdentifier() {
    return identifier;
}

void Course::setName(string _name) {
    name = name;
}

string Course::getName() {
    return name;
}

Course::~Course() {
    //dtor
    //dtor
}

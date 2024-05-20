#ifndef PERSON_H
#define PERSON_H

#include "includes.h"

class Person {
protected:
    string student_name;
    string student_surname;
public:
    Person() : student_name("") , student_surname("") {}
    Person(const string& name, const string& surname) : student_name(name), student_surname(surname) {}
    //Konstruktoriai

    void SetName(string name){ student_name = name; }
    void SetSurname(string surname){ student_surname = surname; }
    //Setters

    string vardas() const { return student_name;}
    string pavarde() const { return student_surname;}
    //Getters

    virtual void f() = 0;
    //Padaro bazine klase Person abstrakcija

    ~Person() {}
    //Deconstructor
};

#endif
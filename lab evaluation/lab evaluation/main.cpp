//
//  main.cpp
//  lab evaluation
//
//  Created by Mayank Raj Gupta on 19/10/23.
//
// create a cpp code in which you are given an employee of an organisation. In that you have his personal information and professional information. Implement compile time and run time polymorphism which includes function overloading and function overriding, multiple and multilevel inheritance in it.

#include <iostream>
#include <string>
using namespace std;

class PersonalInfo {
    string name;
    int age;
public:
    PersonalInfo(const string Name, int Age){
        name = Name;
        age = Age;
    }
    void displayInfo() {
        cout << "Personal Info:\nName: " << name << "\nAge: " << age << endl;
    }
};


class ProfessionalInfo {
private:
    string company;
    string position;
    string employee_id;
    
public:
    ProfessionalInfo(const string Company, const string Position, const string id){
        company = Company;
        position = Position;
        employee_id = id;
        
    }
        
    void displayInfo() {
        cout << "Professional Info:\nCompany: " << company << "\nPosition: " << position << "\nEmployee ID: "<< employee_id<< endl;
    }
};

// Derived class with function overloading
// Multiple inheritance
class Employee : public PersonalInfo, public ProfessionalInfo {
    
public:
    Employee(const string Name, int Age, const string Company, const string Position, const string id)
        : PersonalInfo(Name, Age), ProfessionalInfo(Company, Position, id) {}

    // Function overriding
    // Run time polymorphism
    void displayInfo() {
        PersonalInfo::displayInfo();
        ProfessionalInfo::displayInfo();
    }

    // Function overloading
    // Compile time polymorphism
    void displayInfo(const string& department) {
        PersonalInfo::displayInfo();
        ProfessionalInfo::displayInfo();
        cout << "Department: " << department << endl;
    }
};

// Multilevel inheritance
class Manager : public Employee {
    
private:
    string department;
    
public:
    Manager(const string name, int age, const string company, const string position, const string department, const string employee_id)
        : Employee(name, age, company, position, employee_id), department(department) {}

    void displayInfo() {
        Employee::displayInfo(department);
    }
};

int main() {
    Employee emp("Abhijeet Kumar", 19, "Apple Inc", "Software Engineer", "BT22CSE103");
    Manager manager("Mayank Raj Gupta", 20, "Apple Inc.", "Manager","HR Department", "BT22CSE108");

    cout << "Employee Information:\n";
    emp.displayInfo();

    cout << "\nManager Information:\n";
    manager.displayInfo();

    return 0;
}


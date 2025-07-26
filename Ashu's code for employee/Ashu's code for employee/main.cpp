//
//  main.cpp
//  Ashu's code for employee
//
//  Created by Mayank Raj Gupta on 19/10/23.
//

#include <iostream>
using namespace std;
class employee
{
protected:
    string name;
    string empid;
    int age;
    string type;

public:
    employee(int age, string a, string b)
    {
        age = this->age;
        name = a;
        empid = b;
        // type=this->type;
    }
    employee(int age, string name)
    {
        name = this->name;
        empid = "";
        age = this->age;
    }
    employee(employee &ob)
    {
        this->name = ob.name;
        this->empid = ob.empid;
        this->age = ob.age;
    }

    void employeedetails()
    {
        cout << "Employee name: " << name;
        cout << endl
             << "age: " << age;
        cout << endl
             << "employee ID: " << empid;
    }

    virtual int salary(int basic) {}
};

class labour : public employee
{
    int r = 500;
    float sal = 0.0;

public:
    labour(int age, string name, string b) : employee(age, name, b)
    {
    }
    labour(int age, string name) : employee(age, name)
    {
    }
    int salary(int basic, int hour)
    { // method hiding

        sal = basic * hour + r;
        return sal;
    }
};

class tech : public employee
{
    int r = 5000;
    float sal = 0.0;

public:
    tech(int age, string name, string b) : employee(age, name, b)
    {
    }

    tech(int age, string name) : employee(age, name)
    {
    }

    tech(tech &ob) : employee(ob)
    {
    }

    int salary(int basic)
    {

        sal = basic * 30 + r;
        return sal;
    }
    float operator+(tech ob2)
    {
        float sum = this->sal + ob2.sal;

        return sum;
    }
};
class product : public employee
{
    int r = 2000;
    float sal = 0.0;

public:
    product(int age, string name, string b) : employee(age, name, b)
    {
    }

    product(int age, string name) : employee(age, name)
    {
    }

    int salary(int basic)
    {
        sal = basic * 30 + r;
        return sal;
    }
};

class managers : public employee
{
    int r = 7000;

public:
    managers(int age, string name, string b) : employee(age, name, b)
    {
    }

    managers(int age, string name) : employee(age, name)
    {
    }

    int salary(int basic)
    {

        float sal = basic * 30 + r;
    }
    friend void agecompare(managers ob1, managers ob2);
};
class admin
{
protected:
    int id;
    int age;

public:
    admin(int id, int age)
    {
        id = this->id;
        age = this->age;
    }
    int accessdetails(int a, int b)
    {
        cout << "patented documents of the company are:" << endl;
    }
    int accessdetails(int a)
    {
        cout << "non authorised entry" << endl;
    }
    ~admin()
    {
    }
};

void agecompare(managers ob1, managers ob2)
{
    if (ob1.age > ob2.age)
        cout << ob1.name << " is more experienced than " << ob2.name;
    else if (ob1.age < ob2.age)
        cout << ob2.name << " is more experienced than " << ob1.name;
}

int main()
{

    labour ob1(45, "harish", "bt22");
    employee *ptr;
    float sal1 = ob1.salary(30, 5);
    ob1.employeedetails();
    cout << "the salary of the given employee=" << sal1 << endl;

    labour ob2(43, "ratnesh");
    float sal2 = ob2.salary(100, 12);
    ob2.employeedetails();
    cout << "the salary of the given employee=" << sal2 << endl;

    tech ob3(19, "Jigyasha Singh", "1034");
    ptr = &ob3;
    float sal3 = ob3.salary(8000);
    ob3.employeedetails();
    cout << "the salary of the given employee=" << sal3 << endl;

    managers ob4(29, "Ashu Rajput", "1035");
    ptr = &ob4;
    float sal4 = ob4.salary(2000);
    ob4.employeedetails();
    cout << "the salary of the given employee=" << sal4 << endl;

    managers ob7(39, "Naman singh chauhan", "1035");
    ptr = &ob7;
    float sal7 = ob7.salary(2000);
    ob7.employeedetails();
    cout << "the salary of the given employee=" << sal7 << endl;

    product ob5(39, "Yash Singh Thakur", "1039");
    ptr = &ob5;
    float sal5 = ob5.salary(600);
    ob5.employeedetails();
    cout << "the salary of the given employee=" << sal5 << endl;

    // now manual input
    cout << "enter employee name,age,basic salary to be given,type,id and hours if labour" << endl;
    string ename, id, type;
    int age, sal, hour;
    cin >> ename >> age >> sal >> type >> id >> hour;

    if (type == "labour")
    {
        labour ob8(age, ename, id);
        float salary = ob8.salary(sal, hour);
        ob8.employeedetails();
        cout << "the salary of given employee is=" << salary << endl;
    }
    else if (type == "tech")
    {
        tech ob8(age, ename, id);
        float salary = ob8.salary(sal);
        ob8.employeedetails();
        cout << "the salary of given employee is=" << salary << endl;
    }

    else if (type == "managers")
    {
        tech ob8(age, ename, id);
        float salary = ob8.salary(sal);
        ob8.employeedetails();
        cout << "the salary of given employee is=" << salary << endl;
    }

    else if (type == "product")
    {
        product ob8(age, ename, id);
        float salary = ob8.salary(sal);
        ob8.employeedetails();
        cout << "the salary of given employee is=" << salary << endl;
    }
    else
        cout << "wrong type defined" << endl;

    admin ob9(548, 44);

    admin ob10(514, 34);
    agecompare(ob4, ob7);
    ob9.accessdetails(1);
    ob10.accessdetails(2, 3);

    tech object2(43, "sim");
    tech object(object2);
    return 0;
    tech ash(34, "kanank", "bt22cse080");
    tech mahindra(45, "pushkr", "bt32");
    float jiggi = ash.salary(500);
    float anvi = mahindra.salary(600);
    float sum = ash + mahindra;
    cout << "the sum of their salaries = " << sum << endl;
}

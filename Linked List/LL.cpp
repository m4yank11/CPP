#include <iostream>
using namespace std;

class Student{ //user defined data type
    public:
    string name;
    int age;
    int marks;
    Student(string n, int a, int m){
        name = n;
        age = a;
        marks = m;
    }
};
void change(Student* s){
    s->name = "Minku";
}
int main(){
    // Student s;
    // s.name = "Mayank Raj Gupta";
    // s.age = 21;
    // s.marks = 96;
    // cout<<s.name<<" "<<s.age<<" "<<s.marks<<endl;
    Student s2("Yash", 18, 90);
    cout<<s2.name<<" "<<s2.age<<" "<<s2.marks<<endl;
    // another way of declaring object
    // dynamic allocation of object
    Student* s = new Student("Mayank", 21, 96);
    cout<<s->name<<" "<<s->age<<" "<<s->marks<<endl;
    change(s);
    cout<<s->name<<" "<<s->age<<" "<<s->marks<<endl;
}
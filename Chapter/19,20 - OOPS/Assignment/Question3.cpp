#include<iostream>
#include<climits>
#include<string>

using namespace std;

class Person{
protected:
    string name;
    int age;
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
};

class Student: public Person{
    string studentID;
public:
    Student(string name,int age, string studentID): Person(name,age){
        this->studentID = studentID; 
    }
    void displayStudentInfo(){
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Sudent ID = " << studentID << endl;
    }
};

int main(){
    Student student("Alice",22,"S2314");
    student.displayStudentInfo();
    return 0;
}
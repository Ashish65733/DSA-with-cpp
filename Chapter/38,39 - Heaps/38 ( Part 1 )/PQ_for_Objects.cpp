#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Student{
public:
    string name;
    int marks;

    Student(string name,int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const{
        return this->marks < obj.marks; // > for min heap
    }
};

int main(){
    priority_queue<Student> pq;

    pq.push(Student("aman",85));
    pq.push(Student("bhumika",95));
    pq.push(Student("chetan",65));

    while(!pq.empty()){
        cout << "Top = " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}
#include<iostream>

using namespace std;

class Human{
    public:
    char gender;
    int age;

    Human(){
        cout<<"Constructor is called"<<endl;
        age = 0;
        gender = 'M';
    }

    int getAge(){
        return age;
    }

    void setAge(int a){
        age = a;
    }

    ~Human(){
        cout<<"Destructor is called"<<endl;
    }
};

int main(){
    // Static alocation
    // Human obj;

    // obj.age = 21;
    // cout<<"AGE -> "<<obj.age<<endl;

    // Dynamic alocation
    Human* obj2 = new Human();

    obj2->age = 21;
    cout<<"AGE -> "<<obj2->age<<endl;

    delete obj2;
}
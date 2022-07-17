#include<iostream>

using namespace std;

class Human{
    Human(){
        this->name = "Vaibhav";
        // this->age = 21;
        // this->gender = "M";
    }

    public:
    string name;

    // private:
    // int age;

    // protected:
    // string gender;

};

class Boy : public Human{
    void util(){
        cout<<this->name<<endl;
        // cout<<this->age<<endl;
        // cout<<this->gender<<endl; 
    }
};

int main(){
    Boy obj;

    cout<<obj.name<<endl;



}
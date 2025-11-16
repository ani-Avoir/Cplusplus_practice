#include<iostream>
#include<string>
using namespace std ;

class Person {
    protected:
    string name ;
    int age ;
    
    public:
    static int cur_id;
    virtual void getdata()= 0 ;
    virtual void putdata() = 0 ;
};
class Professor : public Person {
    protected:
    int publications;
    public:
    virtual void getdata() override;
    virtual void putdata() override;
};
class Student : public Person {
     protected:
      int marks[6];
      public:
      virtual void getdata() override;
      virtual void putdata() override;
};
int Person::cur_id ;
void Professor::getdata() {
    
    cur_id++ ;
    cin >> name >> age >> publications ;
}
void Student::getdata() {
    
    cur_id++ ;
    cin >> name >> age ;
    for( int i = 0 ; i < 6 ; i++ ) {
        cin >> marks[i] ;
    }
    
} 

void Professor:: putdata() {
    
    cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n' ;
}

void Student:: putdata() {
    
    int result = 0 ;
    for( int i = 0 ; i < 6 ; i++ ) {
        result += marks[i] ;

                 
    }
    cout << name << ' ' << age << ' ' << result  << ' ' << cur_id << '\n' ;
}
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

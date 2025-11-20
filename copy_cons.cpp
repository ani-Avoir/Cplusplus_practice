#include<iostream>
#include<string>
using namespace std ;

class A {

    double mvalue = 4.5 ;
    string mstring = "Hello" ;
    public:
    A() = default ;
    A( const A& obj );
    A operator=(const A& rhs) ;
  //  A( double invalue , string instring ) ;
    double getdoublevalue() const;
    string getstringvalue() const ;
};

//A::A( double invalue , string instring ) : mvalue(invalue) , mstring(instring) {}

A::A( const A& obj ) {

         mvalue = obj.mvalue ;
         mstring = obj.mstring ;
         cout << "copy constructor" << '\t';
}
A A::operator=( const A& rhs ) {

        if( this == &rhs ) {
                return *this ;
        }
        mvalue = rhs.mvalue ;
        mstring = rhs.mstring ;
        cout << "Inside overloaded operator =" << '\t' ;
        return *this ;
}
double A::getdoublevalue() const {

         return mvalue ;
}
string A::getstringvalue() const {

        return mstring ;
}

int main() {
          
       //   A obj1( 3.2 , "Hello World") ;
          A obj1 ;
          A obj2 ; 
          obj2 = obj1 ; // calls the overloaded operator
        cout << obj2.getdoublevalue() << '\t' << obj2.getstringvalue();
}

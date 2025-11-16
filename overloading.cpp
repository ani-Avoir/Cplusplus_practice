#include<iostream>
using namespace std ;

class A {

    int mvalue ;
    public:
    A( int invalue ) ;
  //  void set( int value ) ;
    A( const A& src );
    int getvalue() const ;
    friend void display( A obj ) ;
    A operator+=(const A& src);
    friend bool operator>=(const A& lhs , const A&rhs ) ;
};

A::A( int invalue ) : mvalue(invalue) {}
/*
void A::set( int value ) {
    mvalue = value ;
} */ 

A::A( const A& src ) {

        mvalue = src.mvalue ;
}

int A::getvalue() const {

        return mvalue ;
}

void display( A obj ) {

        cout << obj.getvalue() << '\t' ;
}

A A::operator+=( const A&src) {

     mvalue += src.mvalue ; 
     return *this ;
}

bool operator>=( const A& lhs , const A& rhs ) {

        return ( lhs.mvalue >= rhs.mvalue ) ;
}

int main() {

       A a(6) ;
       A b = a ;
       b += a ;
       
       display(b) ;
    
       (b >= a) ?  display(b) :  display(a) ;
}
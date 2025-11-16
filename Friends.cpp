#include<iostream>
using namespace std ;


class B ;
class A {

    int a  ;
    int b  ;
    public:
      A( int val , int value ) ;
      //  friend void B::display(const A& src);
      friend class B ;
     

};

class B {
    public:
      //  void display(const A& src) ;
      int display(const A& src) ;
};

int B::display( const A& src) {

    return (src.a + src.b) ;
}

A::A( int val , int value ): a(val) , b(value) {}

//void B::display( const A& src) {
   // cout << src.a << '\t' << src.b ;
//}

int main() {

    A obj( 5 , 10 ); 
    B b ;
  //  b.display(obj);
  cout << b.display(obj) << '\t' ; 
}

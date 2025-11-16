#include<iostream>
#include<memory>
using namespace std ;

class A {

    static int counter ;
    int mid ;
    public:

    void dosomething();

};

int A::counter ;

void A::dosomething() {

    mid = (++counter) ;
    cout << mid << '\t' ;
}

int main() {

  //  unique_ptr<A[]> myptr = make_unique<A[]>(5) ;
    unique_ptr<A> **ptr = new unique_ptr<A>*[2];

    
        ptr[0] = new unique_ptr<A>(make_unique<A>(2));
       // (*ptr[0])->dosomething();
}
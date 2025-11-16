#include<iostream>
using namespace std ;

class Super {

       int i ;
       public:
       Super(int x) : i(x) {} 
       virtual void someMethod() ;
};

class Sub : public Super {

        int j ;
        public:
        Sub(int x) ;
        void someMethod() override ;
        void someOtherMethod();
};

void Super::someMethod() {

    cout << "Super version" << '\n' ;
}

Sub::Sub( int i ) : Super(i) {}

void Sub::someMethod() {

    Super::someMethod();
}

void Sub::someOtherMethod() {

    cout << "inside some other method" << "\n" ;
}

int main() {

        Sub sub(2) ;
      //  Super *super = new Sub(2) ;
      //  super->someMethod();
        
          sub.someMethod();
      //  Super supper = sub ;
      //  supper.someMethod();


}
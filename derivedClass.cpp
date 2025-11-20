#include<iostream>
using namespace std ;

class Super {

       int i ;
       public:
       Super(int x) : i(x) {} 
       virtual void someMethod() ;
       void some() { cout << "Inside some" << "\t" ;}
       virtual void some(int i) { cout << "Inside some" << ' ' << i ;}

};

class Sub : public Super {

        int j ;
        protected:
        void someMethod() override ;
        public:
        Sub(int x) ;
        
        void someOtherMethod();
        using Super::some;
        void some( int i) override { cout << ' ' << i ; }
};

void Super::someMethod() {

    cout << "Super version" << '\n' ;
}

Sub::Sub( int i ) : Super(i) {}

void Sub::someMethod() {

    cout << "Inside Sub some method" ;
}

void Sub::someOtherMethod() {

    cout << "inside some other method" << "\n" ;
}

int main() {

        Sub sub(2) ;
      //  Super *super = new Sub(2) ;
      //  super->someMethod();
        
        //  sub.someMethod();
      //  Super supper = sub ;
      //  supper.someMethod();
     
     // sub.Super::some();
     Super* ref = &sub ;
     ref->someMethod();

}
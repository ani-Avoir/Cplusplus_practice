#include<iostream>

using namespace std ;

struct a {

       int b , c ;

};

struct a& foo( struct a& );

int main() {

        a var1 , var2 ;

        var1.b = 10 ;
        var1.c = 20 ;

        var2 = foo(var1) ;

        cout << var2.b << '\t' << var2.c ;

}

a& foo( struct a &d ) {

        d.c = d.c * d.c ;
        d.b = d.b * d.b ;
        return d ;

} 

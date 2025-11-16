#include<iostream>

using namespace std ;


const int SIZE = 8 ;

struct s_type {

      unsigned int a: SIZE ;
      unsigned int b: SIZE ;

} s_var ;


void displ_binary( unsigned int);

int main() {



     s_var.a = 5 ;
     s_var.b = 12 ;

     displ_binary( s_var.a );

     displ_binary( s_var.b ) ;

     return 0 ;

}

void displ_binary( unsigned int i ) {

      for( int n = SIZE - 1 , mask = 0 ; n >= 0 ; n-- ) {

          //  mask = ( 1 << n );
            if((( i >> n ) & 1) != 0 ) cout << "1" << '\t' ;
            else
                cout << "0" << '\t' ;
      }
      cout << "\n"  ;
}


#include<iostream>
#include<cmath>

using namespace std ;

void disp_binary(int);

int main() {

      char c = 'a';
      int i = 1 ; int cnt = 0 ;

      disp_binary(i) ;

      while( i != 0 ) {

               i <<= 1 ;
               cnt++ ;
      }

      cout << "Size of int is: " << cnt << "bits" << "\n" ;
      cnt = 0 ;

      while( c != '\0') {

             c <<= 1 ;
             cnt++ ;
      }
      cout << "Size of char is: " << cnt << "bits" ;
} 

void disp_binary( int i ) {

        int size_bits = sizeof(int) * 8 ; int mask = 0 ;

        for( int n = size_bits - 1 ; n >= 0 ; n-- ) {

                     mask = ( 1 << n );
                     if( (i & mask) !=0 ) cout << "1" << ' ' ;
                     else cout << "0" << ' ' ;

        }


}

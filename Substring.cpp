/* PROGRAM TO FIND THE FIRST OCCURRENCE OF A SUBSTRING IN A STRING */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int sub_str( char * , char * , int );

int main() {

      char str[50] ;
      char substring[20];
      int index ;

      cout << "Enter the String : " ;
      gets(str) ;
      cout << str ;
      cout << "Enter the Substring : " ;
      gets(substring);

      index = sub_str( str , substring , strlen(substring) ) ;
      ( index >= 0 ) ? cout << "Index is : " << index  : cout << "Not found" ;
} 

int sub_str( char str[] , char substring[] , int len ) {

      int index , found_index_first_occur ; int found = false ; int flag = false ;
      char *p , *q ;  int i = 0 ;

      for( index = 0 , found_index_first_occur = 0  ; str[index] ; index++ ) {


         p = &str[index];
         q = substring ;

         if( *p == ' ' ) {

            flag = true ;
         }

         while( *p && *p == *q && flag == true ) {
                 i++ ;
                 found_index_first_occur = index ;
                 p++ ; q++ ;
         }
         if( *q != '\0' ) i = 0 ;
         if( i == len ) found = true ;
         if( found == true ) {

            return found_index_first_occur ;

         }



      }

      return -1 ;


}


#include<iostream>
#include<string>
#include<sstream>
using namespace std ;

class SpreadsheetCell {

    string doubletostring(double value) const ;
    double stringtodouble( const string& istring) const ;
    double mvalue ;
    string mstring ;

    public:

       void convert_double_to_String(double invalue) ;
       void convert_string_to_double(const string& instring ) ;
      

};

void SpreadsheetCell::convert_double_to_String( double invalue) {

           mvalue = 0.0 ;
           mvalue = invalue ;
           mstring = doubletostring(mvalue) ;
           cout << mstring << "\t" ;  
}

void SpreadsheetCell::convert_string_to_double( const string& instring ) {

          mstring = instring ;
          mvalue = stringtodouble(mstring) ;
          cout << mvalue  ;
}

string SpreadsheetCell::doubletostring(double value) const {

          ostringstream ostr ; string mystring ;
          ostr << value ;
          mystring = ostr.str() ;
          return mystring ;


}

double SpreadsheetCell::stringtodouble( const string& istring) const {

         istringstream istr(istring) ;
         double temp ;
         istr >> temp ;

         if( istr.fail() || !istr.eof() ) {
            return 0 ;
         }
         istr.clear();
         return temp ;
}

int main() {

         SpreadsheetCell Cell ; 
         Cell.convert_double_to_String(42.5) ;
         Cell.convert_string_to_double("3.2") ;

      //  cout  <<  Cell.getstringvalue() << "\t"  ;
      //  cout << Cell.getdoublevalue() ;
         
         return 0 ;
}


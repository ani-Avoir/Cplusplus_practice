#include<iostream>
#include<memory>
using namespace std ;

class SpreadsheetCell{

        int mvalue ;
        public:
        SpreadsheetCell() = default ;
      //  SpreadsheetCell( int invalue );
        void setValue( int value );
        int getvalue() const ;
        SpreadsheetCell operator+( const SpreadsheetCell& cell ) ;
        SpreadsheetCell operator-( const SpreadsheetCell& cell ) ;
};

class Spreadsheet{

        int inWidth , inHeight ;
     //   SpreadsheetCell **mcells ;
     //   unique_ptr<SpreadsheetCell> **mcells ;
      // typedef unique_ptr<std::unique_ptr<SpreadsheetCell[]>[]> Mcells ;
      std::unique_ptr<std::unique_ptr<SpreadsheetCell[]>[]> mcells;  

        public:
        int getdimension() ;
        Spreadsheet( int x , int y );
        void setCellAt( int x , int y , const SpreadsheetCell& src) ;
        const SpreadsheetCell& getCellAt( int x , int y ) const ;
        ~Spreadsheet();


};

//SpreadsheetCell::SpreadsheetCell(int invalue) : mvalue(invalue) {}

void SpreadsheetCell::setValue( int value ) {

    mvalue = value ;
}
int SpreadsheetCell::getvalue() const {
    return mvalue ;
}

SpreadsheetCell SpreadsheetCell::operator+( const SpreadsheetCell& cell ) {

        SpreadsheetCell newcell ;
        newcell.setValue(mvalue + cell.mvalue );
        return newcell ;
}

SpreadsheetCell SpreadsheetCell::operator-( const SpreadsheetCell& cell ) {

        SpreadsheetCell newcell ;
        if( mvalue > cell.mvalue) {
                newcell.setValue(mvalue - cell.mvalue );
        }else {
                newcell.setValue(cell.mvalue - mvalue );
        }
        
        return newcell ;
}


int Spreadsheet::getdimension() {
    return inWidth * inHeight ;
}

Spreadsheet::Spreadsheet( int x , int y ) : inWidth(x) , inHeight(y) {

      //  mcells = new SpreadsheetCell* [inWidth];
     //  mcells = new unique_ptr<SpreadsheetCell[]>[inWidth] ;
     
       mcells = std::make_unique<std::unique_ptr<SpreadsheetCell[]>[]>(inWidth);
      
        for( int i = 0 ; i < inWidth ; i++ ) {
        //   mcells[i] = new SpreadsheetCell [inHeight] ;
         // mcells[i] = new unique_ptr<SpreadsheetCell[]>(new SpreadsheetCell[inHeight]);
                //  mcells[i] = unique_ptr<SpreadsheetCell[]>(make_unique<SpreadsheetCell[]>(inHeight));
                mcells[i] = std::make_unique<SpreadsheetCell[]>(inHeight);
        }
    }

void Spreadsheet::setCellAt( int x , int y , const SpreadsheetCell& src ) {

        mcells[x][y] = src ;
}

const SpreadsheetCell& Spreadsheet::getCellAt( int x , int y ) const {

        return mcells[x][y];
}

Spreadsheet::~Spreadsheet() {
    /*
    for( int i = 0 ; i < inWidth ; i++ ) {

            delete  [] mcells[i] ;
            mcells[i] = nullptr ;
    } */
  //  delete [] mcells ;
 //   mcells = nullptr ; 
}

int main() {

        Spreadsheet s( 2 , 3 ); int result = 0 ;
     //   SpreadsheetCell *ptr = new SpreadsheetCell[ s.getdimension()];
        unique_ptr<SpreadsheetCell[]> ptr(new SpreadsheetCell[s.getdimension()]);
        for( int i = 0 ; i < s.getdimension() - 2 ; i++ ) {
                ptr[i].setValue(i);
                cout << ptr[i].getvalue() << '\t' ; 
        }
        cout << '\n' ;
        s.setCellAt( 0 , 0 , ptr[0]);
        s.setCellAt( 0 , 1 , ptr[1]);
        s.setCellAt( 1 , 0 , ptr[2]);
        s.setCellAt( 1 , 1 , ptr[3]);

      //  result = s.getCellAt( 0 , 1 ).getvalue();

      //  cout << result ;

      ptr[4] = ptr[0] + ptr[1] + ptr[2] + ptr[3] ;
      ptr[5] = ptr[3] - ptr[2] ;

    //  cout << ptr[4].getvalue();

        for( int i = 0 ; i < s.getdimension()  ; i++ ) {
                cout << ptr[i].getvalue() << '\t' ; 
        }
    

       // delete [] ptr ;
      //  ptr = nullptr ;

        return 0 ;

}



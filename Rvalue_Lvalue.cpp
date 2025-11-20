#include<iostream>
using namespace std ;

class intArray{

    int *ptr ;
    int Len ;
    int mvalue ;
    public:
    intArray( int len , int value ) ;
    intArray( intArray&& rhs ) ;
    virtual ~intArray() { delete [] ptr ; ptr = nullptr ;}
    void display() { cout << mvalue ; }
};

intArray::intArray( int len , int value ) : Len(len) , ptr( new int[Len]) , mvalue(value) {}

intArray::intArray( intArray && rhs) {

        ptr = rhs.ptr ;
        Len = rhs.Len ;
        mvalue = rhs.mvalue ;
        rhs.ptr = nullptr ;
}
 intArray func() {

    intArray obj(5 , 5) ;
    return obj ;
}

int main() {

    intArray arr = func() ;
    arr.display();
}

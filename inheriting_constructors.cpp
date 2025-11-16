#include<iostream>
#include<string>
using namespace std;

class Super {

    
    string mstr ;
    public:
    Super( const string& str ) ;
};

class Sub : public Super{

    int mvalue ;
    public:
    using Super::Super ;
    Sub( int i) ;
    void getValue() const ;
};

Super::Super(const string& str) : mstr(str) {
    cout << mstr ;
}
Sub::Sub( int i) :Super("") ,  mvalue(i) {}
void Sub::getValue() const {

    cout << mvalue <<  '\t' ;
}

int main() {

    Sub s1(2);
    Sub s2("Hello world") ;
    s1.getValue();
}
#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
using namespace std ;

int main() {

  //  vector<int>vec{ 5 , 6 , 1 , 3 , 8 , 9 } ;
    unique_ptr<vector<int>> ptr = make_unique<vector<int>>( initializer_list<int>{ 5,9,2,8,1,2} );
    int value = 2 , cnt = 0 ;

  //  auto count = count_if( cbegin(vec) , cend(vec) , [value]( int i) { return i > value ; });

   // cout << "Found " << count << " values" << " > " << value ;
    for_each( ptr->begin() , ptr->end() , [&value , &cnt ]( int& element ){

            if( element > value ) {
                    cnt++ ;
            }

    });

    cout << "Found " << cnt << " values" << " > " << value ;

}


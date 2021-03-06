//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <string>

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;





int main(){

    string alpha = "abcdefghijklmnopkrstuvwxyzABCEDFGHIJKLMNOPQRSTUVWXYZ";
    string numer = "0123456789";

    string::size_type pos = 0;

    string teststring = "ab2c3d7R4E6";

    //FIND_FIRST_OF

    while((pos = teststring.find_first_of(alpha, pos)) != string::npos){
        cout << "Found character at position " << pos
             << " with value: " << teststring[pos]
             << endl;
        ++pos;
    }

    pos = 0;

    while((pos = teststring.find_first_of(numer, pos)) != string::npos){
        cout << "Found number at position " << pos
             << " with value: " << teststring[pos]
             << endl;
        ++pos;
    }

    //FIND_FIRST_NOT_OF

    pos = 0;

    while((pos = teststring.find_first_not_of(numer, pos)) != string::npos){
        cout << "Found character at position " << pos
             << " with value: " << teststring[pos]
             << endl;
        ++pos;
    }

    pos = 0;

    while((pos = teststring.find_first_not_of(alpha, pos)) != string::npos){
        cout << "Found number at position " << pos
             << " with value: " << teststring[pos]
             << endl;
        ++pos;
    }

}











//#define NDEBUG
#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
//#include <cstring> //c-style string functions
//#include <cstddef> //for size_t type and ptr_diff type
//#include <cctype> //for chararacter related functions
//#include <stdexcept> //Plain/Runtime/Logic exception classes
//#include <initializer_list> //for initializer_list type
//#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
//#include <cassert> //assert preprocessor macro
//#include <array>
//#include <list>
//#include <deque>
//#include <forward_list>
//#include <stack> //sequential container adaptor
//#include <queue> //sequential container adaptor, includes priority_queue
//#include <algorithm>
//#include <numeric> //more container algorithms
//#include <functional> //for bind library function (and ref/cref)
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support


using namespace std;

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X(string s) {std::cout << "X(string)" << std::endl; }
    X& operator=(const X&) { std::cout << "operator=" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl;}
};

int main(){


    string s = "hello";

    cout << "Stage 1" << endl;

    vector<X> a(10, s);

    cout << "Stage 2" << endl;

    a.reserve(50);

    cout << "Stage 3" << endl;

    string t = "bitches";

    vector<X> b(15, t);

    cout << "Stage 4" << endl;

    a = b;



}









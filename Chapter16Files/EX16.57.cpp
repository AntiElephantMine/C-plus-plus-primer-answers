//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <cctype> //for chararacter related functions
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <stack> //sequential container adaptor
#include <queue> //sequential container adaptor, includes priority_queue
#include <algorithm>
#include <numeric> //more container algorithms
#include <functional> //for bind library function (and ref/cref), and library defined function objects
#include <map> //for map and multimap associative containers
#include <set> //for set and multiset associative containers
#include <unordered_map> //for unordered_map and unordered_multimap
#include <unordered_set> //for unordered_set and unordered_multiset
#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class
#include <type_traits> //type transformation templates
//
//
////difference_type (iterator arithmetic) and ::size_type are for strings/vectors
////ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)
//
////-c is for separate compilation (creates .o object files)
////-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
////-std=c++11 for C++11 support

using namespace std;


template <typename T> string debug_rep(const T&);
template <typename T> string debug_rep(T*);
string debug_rep(const string&);
string debug_rep(char* p);
string debug_rep(const char* p);
template <typename T> ostream& print(ostream&, T const &);
template <typename T, typename... Args> ostream& print(ostream&, T const &, const Args&...);
template <typename... Args> ostream& errorMsg(ostream&, const Args&...);

template <typename T> string debug_rep(const T& t){
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T* t){
    ostringstream ret;
    ret << "pointer: " << t;

    if(t) ret << " " << debug_rep(*t);
    else ret << " null pointer";

    return ret.str();
}

string debug_rep(const string& s){
    return "\"" + s + "\"";
}

string debug_rep(char* p){
    return debug_rep(string(p));
}

string debug_rep(const char* p){
    return debug_rep(string(p));
}

template <typename T> ostream& print(ostream& os, const T& t){
    return os << t;
}

template <typename T, typename... Args> ostream& print(ostream& os, T const & t, const Args&... rest){
    os << t << ", ";
    return print(os, rest...);
}

template <typename... Args> ostream& errorMsg(ostream& os, const Args&... rest){
    return print(os, debug_rep(rest)...);
}

int main(){


    errorMsg(cout, "holy", "shittttttt", string("woah"), 2, 3);



}














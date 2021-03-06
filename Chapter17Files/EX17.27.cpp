//#define NDEBUG
//#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
//#include <string>
//#include <vector>
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
//#include <functional> //for bind library function (and ref/cref), and library defined function objects
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
//#include <memory> //for dynamic memory smart pointers
//#include <new> //nothrow and bad_alloc types, and allocator class
//#include <type_traits> //type transformation templates
//#include <tuple> //tuple class
//#include <bitset> //bitset class
//#include <regex> //regex library

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

#include <iostream>
#include <string>
#include <regex>

using namespace std;
using namespace regex_constants;

int main(){

    string pattern = "(\\d{5})((-)?(\\d{4}))?";

    regex r(pattern);

    string formatNine = "$1-$4";

    cout << "Please enter a zipcode: ";

    for(string codes; cin >> codes;){
        smatch s;
        if(regex_match(codes, s, r)){
            cout << "Valid zipcode: ";
            if(s[2].matched && !s[3].matched) cout << s.format(formatNine) << endl; //if the last 4 digits was found with no '-'
            else cout << s.str() << endl;
        }
        else cout << "Invalid zipcode." << endl;
        cout << "\nPlease enter another zipcode: ";
    }

    //valid: 123456789, 12345-6789, 12345
    //invalid: 1234, 12345-, 12345678, 1234567890 (subsets of some of these would be valid if we did regex_search instead of _match)

}















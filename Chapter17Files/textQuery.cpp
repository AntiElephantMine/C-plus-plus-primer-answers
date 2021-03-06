#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm> //for removePunc
#include "textQuery.h"

using namespace std;

std::string& removePunc(string& s){
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
    return s;
}

textQuery::textQuery(ifstream& input): lines(make_shared<vector<string>>()) {

    lineNo linenumber = 0;
    for(string s; getline(input, s); ++linenumber){
        istringstream tempProcess(s);
        for(string tempString; tempProcess >> tempString;){
            auto& sPtr = appearLines[removePunc(tempString)];
            if(!sPtr) sPtr = make_shared<set<lineNo>>();
            sPtr->insert(linenumber);
        }
        lines->push_back(s);
    }

}

textQuery::queryResult textQuery::query(const string& s) const {

    static shared_ptr<set<lineNo>> nodata = make_shared<set<lineNo>>();

    auto found = appearLines.find(s);
    if(found != appearLines.end()) return queryResult(s, found->second, lines);
    else return queryResult(s, nodata, lines);
    /*previously I had nodata replaced with make_shared<set<lineNo>>(), the problem with this is that it allocates memory on the heap
    every time query is called, better to have a single static which allocates on the heap just once*/

}

ostream& print(ostream& os, const textQuery::queryResult& r){

    os << (get<0>(r)) << " appears " << (get<1>(r))->size() << " time" << ((get<1>(r))->size() == 1 ? "" : "s") << endl;
    for(const auto& c : *(get<1>(r)))
        os << "\t(line " << c+1 << ") " << (*(get<2>(r)))[c] << endl;

    return os;

}

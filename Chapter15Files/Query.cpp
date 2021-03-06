#include <algorithm> //set_intersection
#include "Query.h"

using namespace std;

Query::Query(const string& s): q(new WordQuery(s)) { }

Query operator~(const Query& rhs){
    return shared_ptr<Query_Base>(new NotQuery(rhs));
}
Query operator&(const Query& lhs, const Query& rhs){
    return shared_ptr<Query_Base>(new AndQuery(lhs, rhs));
}
Query operator|(const Query& lhs, const Query& rhs){
    return shared_ptr<Query_Base>(new OrQuery(lhs, rhs));
}
ostream& operator<<(ostream& lhs, const Query& rhs){
    return lhs << rhs.rep();
}


queryResult NotQuery::eval(const textQuery& t) const {

    auto not_lines = make_shared<set<lineNo>>();
    auto result = q.eval(t);
    auto sz = result.get_file()->size();
    auto beg = result.begin(), end = result.end();

    for(decltype(sz) n = 0; n != sz; ++n){
        if(beg == end || *beg != n)
            not_lines->insert(n);
        else ++beg;
    }

    return queryResult(rep(), not_lines, result.get_file());

}

queryResult AndQuery::eval(const textQuery& t) const {

    auto lhsQuery = lhs.eval(t), rhsQuery = rhs.eval(t);
    auto and_lines = make_shared<set<lineNo>>();

    set_intersection(lhsQuery.begin(), lhsQuery.end(),
                     rhsQuery.begin(), rhsQuery.end(), inserter(*and_lines, and_lines->begin()));

    return queryResult(rep(), and_lines, lhsQuery.get_file());

}

queryResult OrQuery::eval(const textQuery& t) const {

    auto lhsQuery = lhs.eval(t), rhsQuery = rhs.eval(t);
    auto or_lines = make_shared<set<lineNo>>(lhsQuery.begin(), lhsQuery.end());

    or_lines->insert(rhsQuery.begin(), rhsQuery.end());

    return queryResult(rep(), or_lines, lhsQuery.get_file());

}


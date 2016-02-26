#ifndef STRINGNODEID_H
#define STRINGNODEID_H

#include <string>
#include "nodeId.h"

namespace graph {

class CStringNodeId: public CNodeId {
    std::string str;
  public:
    CStringNodeId () : str("") {}
    CStringNodeId (const std::string& s) : str(s) {}
    ~CStringNodeId() { /* delete str; */ }
    const std::string& getString() { return str; }
    bool operator== (const CNodeId&);
    bool operator> (const CNodeId&);
    bool operator< (const CNodeId&);
    void print();
};

} // namespace graph

#endif /* STRINGNODEID_H */

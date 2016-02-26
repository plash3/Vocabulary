#ifndef NODEID_H
#define NODEID_H

/**
  abstract base class CNodeId
*/

namespace graph {

class CNodeId {
  public:
    virtual ~CNodeId() {}
    virtual bool operator== (const CNodeId&) =0;
    virtual bool operator> (const CNodeId&) =0;
    virtual bool operator< (const CNodeId&) =0;
    virtual void print() =0;
};

} // namespace graph

#endif /* NODEID_H */

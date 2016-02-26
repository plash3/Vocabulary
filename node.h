#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "nodeId.h"

/**
  Base class CNode represents a vertex in a graph. It can be used
  as is. Or retrofitted with a distance for use in a weihted graph.
*/

namespace graph {

class CNode {
    int level;
    CNode* parent;
  protected:
    CNodeId* id;
  public:
    CNode(CNodeId* id, int l, CNode* n) : id(id), level(l), parent(n) {}
    virtual ~CNode() { delete id; }
    CNodeId* getId() { return id; }
    int getLevel() { return level; }
    bool operator== (const CNode& rhs) { return *id == *rhs.id; }
    bool operator== (const CNodeId& nid) { return *id == nid; }
    virtual bool operator> (const CNode& rhs) { return *id > *rhs.id; }
    virtual bool operator< (const CNode& rhs) { return *id < *rhs.id; }
    virtual void print() {
      std::cout << "{";
      id->print();
      if (parent) {
        std::cout << "->";
        parent->id->print();
      }
      std::cout << " " << level;
      std::cout << "}";
    }
};

} // namespace graph

#endif /* NODE_H */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"

/**
  abstract base class CGraph
*/

namespace graph {

class CGraph {
  protected:
    /**
      A set of visited nodes.
    */
    std::vector<CNode*> vstd_vertices;
    /**
      Checks that a node has not been seen.
    */
    bool checkVisitedSet (CNodeId*);
  public:
    virtual ~CGraph ();
    /**
      Build a set of neighbours of a vertex in the graph
      by trying all outgoing edges, but ignoring vertices
      from previous levels.
    */
    virtual std::vector<CNodeId*> getAdjacencyList (CNode*) =0;
    /**
      Breadth-first search (BFS) - Graph traversal algorithm;
      Explore graph level by level from starting node s.
      Input: A graph G and a starting vertex root of the graph.
      Output: All vertices reachable from root labeled as explored.
    */
    void breadthFirstSearch (CNode*);
    /**
      Prints all vertices of the explored graph
      reachable from root level by level.
    */
    virtual void print ();
};

} // namespace graph

#endif /* GRAPH_H */

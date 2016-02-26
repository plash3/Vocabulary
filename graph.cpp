#include <iostream>
#include "graph.h"

namespace graph {

/**
  Check that a node has been seen.
*/
bool CGraph::checkVisitedSet (CNodeId* nid) {
  bool result = false;
  for (std::vector<CNode*>::iterator it = vstd_vertices.begin(); it != vstd_vertices.end(); it++) {
    if (**it == *nid) {
      result = true;
      break;
    }
  }
  return result;
}

CGraph::~CGraph () {
  std::vector<CNode*>::iterator it = vstd_vertices.begin();
  it++;
  // the starting node is passed from outside
  while (it != vstd_vertices.end()) {
    delete *it;
    it++;
  }
}

/**
  Breadth-first search (BFS) - Graph traversal algorithm;
  Explore graph level by level from s.
  Input: A starting vertex s of the Graph.
  Output: All vertices reachable from s labeled as explored.
*/
void CGraph::breadthFirstSearch (CNode* s) {
  // a set of explored vertices initially empty;
  // a vertex becomes explored when it leaves a frontier queue
  vstd_vertices.push_back (s);
  // the frontier is implemented as a FIFO queue; it contains
  // a list of nodes discovered (or visited) but not explored
  // (children nodes have not been visited);
  std::vector<CNode*> frontier (1, s);
  int level = 0;
  std::vector<CNode*> next_level;
  while (!frontier.empty()) {
    // a queue of discovered nodes on a current level
    level++;
    for (std::vector<CNode*>::iterator fit = frontier.begin(); fit != frontier.end(); fit++) {
      // for every node in frontier
      std::vector<CNodeId*> adjl = getAdjacencyList (*fit);
      for (std::vector<CNodeId*>::iterator dit = adjl.begin(); dit != adjl.end(); dit++) {
        // for each node that is adjacent to current
        // if the node has not been seen
        if (checkVisitedSet (*dit)) {
          delete *dit;
          continue;
        }
        CNode* v = new CNode (*dit, level, *fit);
        vstd_vertices.push_back (v);
        next_level.push_back (v);
      }
    }
    frontier = std::move(next_level);
  }
  return;
}

void CGraph::print () {
  std::cout << "Explored vertices:" << std::endl;
  int level = 0;
  for (std::vector<CNode*>::iterator it = vstd_vertices.begin(); it != vstd_vertices.end(); it++) {
    if ((*it)->getLevel() > level) {
      level = (*it)->getLevel();
      std::cout << std::endl;
    }
    (*it)->print();
  }
  std::cout << std::endl;
}

} // namespace graph

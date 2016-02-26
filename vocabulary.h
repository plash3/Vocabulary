#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <map>
#include "graph.h"
#include "stringNodeId.h"
#include "word.h"

using namespace std;

/**
  class CVocabulary

  Vocabulary is a collection of words. They can be strings
  of random characters and not necessarily English words.

  Let each word in the vocabulary represent a vertex in an
  undirected graph. In this graph, two vertices (words) are
  connected (i.e. there is an edge between these two vertices)
  if the edit distance between the two words is 1 (edit
  distance of 1 between word w1 and word w2 means that you
  can obtain w1 from w2 by a single character
  deletion/insertion/substitution).

  Write a function, that accepts the vocabulary (in the form
  of a set) and a word (a word by definition must be contained
  in the vocabulary):
  def word_clique(vocab, w):
      ...

  This function should return the set of all words reachable
  from w (i.e. all words x such that there is a path in the
  graph from x to w).
*/

namespace graph {

class CVocabulary: public CGraph {
    /**
      Vocabulary is composed of words, organazed in a map.
      Words of the same lenght are grouped together: the map key
      is the length of the words (int) and the value is a vector
      of strings (of same legth).
    */
    std::map<int,std::vector<string*>> vocabulary;
    bool word_not_in (const string&, std::vector<string*>);
  public:
    CVocabulary () {}
    CVocabulary (std::map<int,std::vector<string*>> v) : vocabulary(v) {}
    ~CVocabulary () {}
    void add_word (string*);
    std::vector<CNodeId*> getAdjacencyList (CNode*);
    void print ();
};

} // namespace graph

#endif /* VOCABULARY_H */

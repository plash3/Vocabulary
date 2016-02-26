#include <iostream>

#include "node.h"
#include "stringNodeId.h"
#include "vocabulary.h"

using namespace graph;

int main() {
  string sarr[] = {"i", "ie", "ice", "ire", "is", "isle", "icy", "frog", "ere", "err", "erro", "error" };
  
  CVocabulary vcblr;
  for (int i = 0; i < 12; i++) {
    vcblr.add_word (&sarr[i]);
  }

  CNodeId* nid = new CStringNodeId ("ire");
  CNode* n = new CNode (nid, 0, NULL);
  vcblr.breadthFirstSearch (n);
  vcblr.print();

  delete n;

  return 0;
}

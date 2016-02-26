#include "vocabulary.h"

namespace graph {

bool CVocabulary::word_not_in (const string& s, std::vector<string*> v) {
  bool result = true;
  for (std::vector<string*>::iterator it = v.begin(); it != v.end(); it++) {
    if (s == **it) {
      result = false;
      break;
    }
  }
  return result;
}

/**
  Adds a word to the vocabulary. Checks that there is no
  duplicate values. Disperses words in various bundles
  arranging them by their legths.
*/
void CVocabulary::add_word (string* s) {
  int lngth = s->length();
  // if there is a word in the vocabulary of the same lenght
  // then append the word to that bundle
  if (vocabulary.count(lngth) > 0) {
    if (word_not_in (*s, vocabulary.at(lngth))) {
      vocabulary.at(lngth).push_back (s);
    }
  } else {
    std::vector<string*> bundle (1, s);
    vocabulary.insert (std::pair<int,std::vector<string*>> (lngth,bundle));
  }
}

/**
  Build a set of neighbours of a vertex in the graph by trying
  all outgoing edges, but ignoring vertices from previous levels.
*/
std::vector<CNodeId*> CVocabulary::getAdjacencyList (CNode* n) {
  std::vector<CNodeId*> adjl;
  CStringNodeId* nid = static_cast<CStringNodeId*>( n->getId() );
  string s = nid->getString();
  int lngth = s.length();
  // Edit distance of 1 between a pair of strings can be met
  // if one word is 1 character longer than the other.
  for (int l = lngth - 1; l < lngth + 2; l++) {
    if (vocabulary.count(l) > 0) {
      // scan a bundle of words of legth l
      for (std::vector<string*>::iterator it = vocabulary.at(l).begin(); it != vocabulary.at(l).end(); it++) {
        // check on edit distance between 2 words is 1
        // avoiding duplicates - itself
        if (s == **it) {
          continue;
        }
        if (word::is_edit_distance_one (s, **it)) {
          CNodeId* snid = new CStringNodeId { **it };
          adjl.push_back (snid);
        }
      }
    }
  }
  return adjl;
}

void CVocabulary::print () {
  std::cout << "Vocabulary:" << std::endl;
  for (std::map<int,std::vector<string*>>::iterator t = vocabulary.begin(); t != vocabulary.end(); t++) {
    std::cout << t->first << " =>";
    // t->second is vector<string*>
    for (std::vector<string*>::iterator it = t->second.begin(); it != t->second.end(); it++) {
      std::cout << " " << **it;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  CGraph::print ();
}

} // namespace graph

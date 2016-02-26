#ifndef WORD_H
#define WORD_H

#include <stdlib.h>
#include <string>

using namespace std;

namespace graph {
namespace word {

/**
  Check if edit distance between two words is 1. Edit distance of 1
  between word w1 and word w2 means that w1 can be obtained from w2
  by a single character deletion / insertion / substitution.
*/
bool is_edit_distance_one (const string&, const string&);

/**
  Check that a shorter word can be obtained from
  a longer one by a single character deletion.
*/
inline bool is_edit_distance_one_deletion (const string&, const string&, int);

} // namespace word
} // namespace graph

#endif /* WORD_H */

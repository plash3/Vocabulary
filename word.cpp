#include "word.h"

namespace graph {
namespace word {

/**
  Check if edit distance between two words is 1. Edit distance of 1
  between word w1 and word w2 means that w1 can be obtained from w2
  by a single character deletion / insertion / substitution.
*/
bool is_edit_distance_one (const string& s, const string& t) {
  bool result = true;
  int ls = s.length();
  int lt = t.length();
  int diff = abs(ls - lt);
  if (diff > 1) {
    result = false;
  } else if (diff == 0) {
    for (int i=0, cnt=0; i < ls; i++) {
      if (s[i] != t[i]) {
        cnt++;
        if (cnt > 1) {
          result = false;
          break;
        }
      }
    }
  } else { // diff == 1
    if (ls < lt) {
      result = is_edit_distance_one_deletion (s, t, ls);
    } else {
      result = is_edit_distance_one_deletion (t, s, lt);
    }
  }
  return result;
}

/**
  Check that a shorter word can be obtained from
  a longer one by a single character deletion.
*/
bool is_edit_distance_one_deletion (const string& shorter, const string& longer, int ln) {
  bool result = true;
  // consider a sample - 'ABCEF' and 'ABCDEF';
  // when it comes to 'D' it has to skip a letter
  // and proceed to the next one
  for (int i=0, cnt=0; i < ln; i++) {
    if (shorter[i] != longer[i+cnt]) {
      cnt++;
      if (cnt > 1) {
        result = false;
        break;
      }
      if (shorter[i] != longer[i+cnt]) { // cnt > 1
        result = false;
        break;
      }
    }
  }
  return result;
}

} // namespace word
} // namespace graph

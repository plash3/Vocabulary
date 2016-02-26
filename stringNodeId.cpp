#include <iostream>
#include "stringNodeId.h"

/**
  Defines tailored objects comparing.
*/

namespace graph {

bool CStringNodeId::operator== (const CNodeId& rhs) {
  const CStringNodeId* nid = static_cast<const CStringNodeId*>(&rhs);
  return str == nid->str;
}

bool CStringNodeId::operator> (const CNodeId& rhs) {
  const CStringNodeId* nid = static_cast<const CStringNodeId*>(&rhs);
  return str > nid->str;
}

bool CStringNodeId::operator< (const CNodeId& rhs) {
  const CStringNodeId* nid = static_cast<const CStringNodeId*>(&rhs);
  return str < nid->str;
}

void CStringNodeId::print () {
  std::cout << str;
}

} // namespace graph

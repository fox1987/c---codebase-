// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-13 14:47:14
// Description:
#include "consist_hash.h"
#include "logging.h"

namespace base {
#define MaxNum 4294967296
ConsistHash::ConsistHash(): m_rnode_num(0) {
}

bool ConsistHash::AddNode(const std::string& name) {
  ++m_rnode_num;
  int i = 1;
  while (i < m_rnode_num) {
    i = i<< 1;
  }
  uint num = MaxNum / i * (m_rnode_num * 2 - i - 1) - 1;
  m_node_map.insert(NodeMap::value_type(num, Node(name)));
  VLOG(3) << "Add " << name << " : " << num;
  return true;
}
bool ConsistHash::DelNode(const std::string& name) {
  for (NodeMap::iterator it = m_node_map.begin();
        it != m_node_map.end();
        ++it) {
    if (it->second.name == name) {
      m_node_map.erase(it);
      return true;
    }
  }
  VLOG(3) << "Not found " << name;
  return  false;
}
Node& ConsistHash::Lookup(uint val) {
  for (NodeMap::iterator it = m_node_map.begin();
        it != m_node_map.end();
        ++it) {
    if (it->first >= val) {
      return it->second;
    }
  }
  VLOG(3) << "Not Found in One circle";
  return  m_node_map.begin()->second;
}
}

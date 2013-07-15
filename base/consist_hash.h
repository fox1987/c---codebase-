// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-13 14:23:13
// Description:
#ifndef CONSIST_HASH_H_
#define CONSIST_HASH_H_
#include <set>
#include <map>
#include <string>

namespace base {
typedef struct Node {
  Node(const std::string& n) : name(n) {
  } 
  std::string name;
}Node;
typedef unsigned int uint;
typedef std::map<uint, Node> NodeMap;
class ConsistHash {
  public:
    ConsistHash();
    Node& Lookup(uint val);
    bool AddNode(const std::string& name);
    bool DelNode(const std::string& name);

    int rnode_num() {return m_rnode_num;}
  private:
    int m_rnode_num;
    NodeMap m_node_map;
};
}
#endif

// Copyright 2013 Inc. All Rights Reserved.
// Date: 2013-08-30 08:49:18
// Description:
#ifndef TRIE_TREE_H_
#define TRIE_TREE_H_
#include <map>
namespace base {
struct TrieTreeNode;
typedef  std::map<char, TrieTreeNode*> NodeContainer;
typedef struct TrieTreeNode {
  TrieTreeNode() : count(1), flag(false) {
  }
  int count;  // 出现次数
  bool flag;  // 是否单词
  NodeContainer next;  // 下个节点，字符为0-9, a-z, A-Z 共62个
} TrieTreeNode;
class TrieTree {
  public:
    TrieTree();
    ~TrieTree();
    void Insert(const char* str);
    bool Search(const char* str);
  private:
    void DeleteTrieTree(TrieTreeNode* p);
    TrieTreeNode* root_;
};
}
#endif

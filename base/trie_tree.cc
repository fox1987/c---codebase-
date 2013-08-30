// Copyright 2013 Inc. All Rights Reserved.
// Date: 2013-08-30 08:50:01
// Description:
#include "trie_tree.h"
namespace base {
TrieTree::TrieTree() {
  root_ = new TrieTreeNode();
}

TrieTree::~TrieTree() {
  DeleteTrieTree(root_);
}

void TrieTree::DeleteTrieTree(TrieTreeNode* p) {
  if (!p) {return;}
  for (NodeContainer::iterator it = p->next.begin();
        it != p->next.end(); ++it) {
    if (it->second) {
      DeleteTrieTree(it->second);
    }
  }
  delete p;
}
void TrieTree::Insert(const char* str) {
  const char* c = str;
  TrieTreeNode *p = root_;
  while(*c != '\0') {
    if (p->next.find(*c) == p->next.end()) {
      p->next[*c] = new TrieTreeNode();
    } else {
      ++(p->next[*c]->count);
    }
    p = p->next[*c];
    ++c;
  }
  p->flag = true;
}

bool TrieTree::Search(const char* str) {
  const char* c = str;
  TrieTreeNode *p = root_;
  while (*c != '\0') {
    if (p->next.find(*c) == p->next.end()) {
      return false;
    }
    p = p->next[*c];
    ++c;
  }
  if (p->flag) {
    return true;
  }
  return false;
}
}

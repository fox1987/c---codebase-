// Copyright 2013 Inc. All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-06-26 08:50:01
// Description:
#include "skiplist.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "logging.h"
using namespace std;
namespace base {

const int kRandomArea = 10;
const double kProb = 0.5;
SkipList::SkipList(int max_level) : max_level_(max_level) {
  srand(time(NULL));
  CreateList();
}

SkipList::~SkipList() {
  SkipListNode* node = header_->level[0].forward;
  SkipListNode* tmp_node;
  while(node) {
    tmp_node = node;
    node = node->level[0].forward;
    FreeNode(tmp_node);
  }
  FreeNode(header_);
}

SkipListNode* SkipList::CreateNode(int level, double value) {
  SkipListNode* node = (SkipListNode*) malloc(sizeof(*node) +
        level * sizeof(SkipListLevel)); 
  if (node == NULL) {
    VLOG(0) << "malloc fail" << level;
  }
  node->value = value;
  return node;
}

bool SkipList::Insert(double value) {
  SkipListNode* update[max_level_];
  SkipListNode* tmp = header_;
  // 寻找插入的位置
  // 使用update保存其位置
  for (int j = level_-1; j >= 0; --j) {
    while(tmp->level[j].forward && tmp->level[j].forward->value < value) {
      tmp = tmp->level[j].forward;
    }
    update[j] = tmp;
  }
  int level = RandomLevel();
  // cout << "value : " << value << " level : " << level << endl;
  SkipListNode* node = CreateNode(level, value);
  if (level > level_) {
    for (int j = level_; j < level; ++j) {
      update[j] = header_;
    }
    level_ = level;
  }
  // 插入节点
  // 将其forward指向其前一个几点的forward
  // 将前一个节点的forward指向该节点
  for (int i = 0; i < level; ++i) {
    node->level[i].forward = update[i]->level[i].forward;
    update[i]->level[i].forward = node;
  }
  // 设置节点backward，backward为最底层的后一个节点，即比其小的节点
  node->backward = (update[0] == header_ ? NULL: update[0]);
  if (node->level[0].forward) {
    node->level[0].forward->backward = node;
  } else {
    tail_ = node;
  }
  ++length_;
  return true;
}
void SkipList::FreeNode(SkipListNode* node) {
  free(node);
}

bool SkipList::Find(double value) {
  SkipListNode* node = header_;
  for (int i = level_-1; i >= 0; --i) {
    while(node->level[i].forward && node->level[i].forward->value < value) {
      node = node->level[i].forward;
    }
    if (node->level[i].forward && node->level[i].forward->value == value) {
      VLOG(3) << "Found " << value << " in skiplist in level " << i << endl;
      return true;
    }
  }
  VLOG(3) << "Not found " << value << " in skiplist" << endl;
  return false;
}

bool SkipList::Delete(double value) {
  SkipListNode* node = header_;
  int find_level = -1;
  bool found = false;
  SkipListNode* update[level_];
  for (int i = level_-1; i >= 0; --i) {
    while(node->level[i].forward && node->level[i].forward->value < value) {
      node = node->level[i].forward;
    }
    if (node->level[i].forward && node->level[i].forward->value == value) {
      VLOG(3) << "Found " << value << " in skiplist in level " << i << endl;
      update[i] = node;
      if (!found) {
        found = true;
        find_level = i;
      }
    }
  }
  if (found) {
    SkipListNode* del_node = update[0]->level[0].forward;
    for (int i = find_level; i >=0; --i) {
      // 修改forward
      update[i]->level[i].forward = del_node->level[i].forward;
    } 
    // 修改backward
    if (del_node->level[0].forward) {
      del_node->level[0].forward->backward = del_node->backward;
    }
    FreeNode(del_node);
    --length_;
  } else {
    VLOG(3) << "Not found " << value << " in skiplist" << endl;
    return true;
  }
}
void SkipList::CreateList() {
  header_ = CreateNode(max_level_, 0);
  level_ = 1;
  length_ = 0;
  tail_ = NULL;
  for (int j = 0; j < max_level_; ++j) {
    header_->level[j].forward = NULL;
  }
  header_->backward = NULL;
}

int SkipList::RandomLevel() {
  int level = 1;
  while (rand() % kRandomArea < (kProb * kRandomArea)) {
    ++level;
    if (level >= max_level_) break;
  }
  return level;
}

void SkipList::Show() {
  for (int j = 0; j < level_; ++j) {
    cout << "Level[" << j << "] : ";
    SkipListNode* node = header_->level[j].forward;
    while(node) {
      cout << node->value << "->";
      node = node->level[j].forward;
    }
    cout << "NULL" << endl;
  }
}
}

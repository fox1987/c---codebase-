// Copyright 2013  Inc. All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-06-26 08:49:40
// Description: SkipList
#ifndef SKIPLIST_H_
#define SKIPLIST_H_
namespace base {

struct SkipListNode;

typedef struct SkipListLevel {
    struct SkipListNode* forward;
}SkipListLevel;
typedef struct SkipListNode  {
  double value;
  struct SkipListNode* backward;
  SkipListLevel level[];
} SkipListNode;

class SkipList {
  public:
    SkipList(int max_level = 8);
    ~SkipList();
    // print skiplist node info
    void Show();
    bool Insert(double value);
    bool Find(double value);
    bool Delete(double value);
    int RandomLevel();

    int max_level()const { return max_level_;}
    int length()const { return length_;}

  private:
    void CreateList();
    SkipListNode* CreateNode(int level, double value);
    void FreeNode(SkipListNode* node);

    int level_;
    unsigned long length_;
    SkipListNode* header_;
    SkipListNode* tail_;
    int max_level_;
};
}
#endif  // SKIPLIST_H_

#ifndef UNTITLED1_TABLE_H
#define UNTITLED1_TABLE_H
 class table
 {
 public:
     struct SingleNode
     {
         int value;
         SingleNode *next;
     };

     struct DoubleNode
     {
         int value;
         DoubleNode *pre;
         DoubleNode *next;
     };
 };
#endif //UNTITLED1_TABLE_H

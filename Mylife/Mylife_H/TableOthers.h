#ifndef UNTITLED1_TABLEOTHERS_H
#define UNTITLED1_TABLEOTHERS_H

#include <stack>
#include <vector>
#include <iostream>
#include "table.h"

using namespace std;

class TableOthers: public table {
public:

    /**
     * shead = reverseList(shead);
     * @param head
     * @return
     */
    static SingleNode* reverseList(SingleNode *head);

    static DoubleNode* reverseList(DoubleNode *head);
    /**
     * printList(dhead);
     * @param head
     */
    static void printList(SingleNode *head);

    static void printList(DoubleNode *head);
    /**
     * input(int lenght)
     * @param n
     */
    static void input(int n);

    /**
     * 在行列都排好序的矩阵中找数
     * @param matrix
     * @param k
     * @return
     */
    static bool isContanin(vector<vector<int> >& matrix, int k);

    /**
     * printComPart(head1,head2);
     * @param head1
     * @param head2
     */
    static void printComPart(SingleNode *head1,SingleNode *head2);

    /**
     * easy
     *  isPalindrome1
     *  isPalindrome2
     * @param head
     * @return
     */
    static bool isPalindrome1(SingleNode *head);

    static bool isPalindrome2(SingleNode *head);

    /**
     * hard
     * @param head
     * @return
     */
    static bool isPalindrome3(SingleNode *head);

    /**
     * printlist
     * @param head
     */
    static void printLists(SingleNode *head);

};


#endif //UNTITLED1_TABLEOTHERS_H

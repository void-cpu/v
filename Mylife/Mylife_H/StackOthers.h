#ifndef UNTITLED1_STACKOTHERS_H
#define UNTITLED1_STACKOTHERS_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "DogAndCat.h"

class StackOthers {
public:

    /**得到最大值的一个栈功能实现
     * 输入： pushStack(int number)
     * 输出：int popStack()
     * @param number
     */
    static void maxpushStack(int number);

    static int popStack();

    /**得到最小值的一个栈功能实现
     * 输入： pushStack(int number)
     * 输出：int popStack()
     * @param number
     */
    static void minpushStack(int number);

    /**
     * QueueToStack的一个栈功能的实现
     * @param x
     */
    static void QueueToStack_push(int x);

    static void QueueToStack_pop();

    static bool QueueToStack_empty();

    static int QueueToStack_top();


    /**
     * StackToQueue的一个栈功能的实现
     * @param x
     */
    static void StackToQueue_push(int x);

    static void StackToQueue_pop();

    static bool StackToQueue_empty();

    /**
     * 转圈打印数组
     * 1.piralOrderPrint:
     * 打印完一圈然后再去打印一圈
     *
     * 2.printEdge：
     * 当tr==dr时候，说明这个数组只有一行
     * 当tC==dC时候，说明这个数组只有一列
     * 如果都不是呢，
     * curC=tC,curR=tR;即curC为左上角的纵坐标，curR为右上角的纵坐标。
     * @param matrix
     */
    static void spiralOrderPrint(std::vector< std::vector<int> > matrix);

    /**
    *旋转90度打印数组
    * @param matrix
    */
    static void spiralOrderPrint90(std::vector<std::vector<int> > matrix);

    static void Rotate(std::vector<std::vector<int> > &matrix);

    /**
     * 之字打印数组
     * @param Array
     */
    static void PrintZhi(std::vector<std::vector<int> > Array);

private:
    static std::vector<int> printMatrix(std::vector<std::vector<int> > Array, int n, int m);

    static void PrintLeven(std::vector<std::vector<int> > Array, int tr, int tc, int dr, int dc, bool f);

    static void printEdge(std::vector<std::vector<int> > m, int tR, int tC, int dR, int dC);

    static int top();

    static void printEdgeprintEdge(std::vector<std::vector<int> > m, int tR, int tC, int dR, int dC);

    static std::stack<int> Datestack, Helpskack,stack1, stack2;

    static std::queue<int> Date, Help;

     static std::vector<std::vector<int> > Array;

};

#endif //UNTITLED1_STACKOTHERS_H

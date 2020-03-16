//
// Created by void on 2020/3/16.
//

#ifndef UNTITLED1_SORTOTHERS_H
#define UNTITLED1_SORTOTHERS_H


class SortOthers{
public:

    static void Patitions(int Array[], int len, int number);

    static int LittleSums(int a[], int len);

    static int GetMax(int *Array, int Leftindex, int Rightindex);

    static int GetMin(int *Array, int Leftindex, int Rightindex);

    /***
           * minArr的作用是记录每个桶中的最小数
           * maxArr的作用是记录每个桶中的最大数
           * hasNum的作用是记录桶中是否有数
           * MaxGap=>记录最大差值
           * LastMax=>记录当前空桶的上一个桶的最大值
           * i=>循环变量
           * while的作用是，可能会有多个空桶，遍历桶，找到其中的空桶
       ***/
    static int maxGap(int Array[], int lenght);

    static void rendom(int Array[], int Lenght);

private:

    static int mergeSum(int a[], int b[], int l, int m, int r);

    static void swap(int Array[], int i, int j);

    /*
    t(n)=at(n/b)+O(n^d);
    n为数据总量，b为平均分成几份，a为出现的次数，O（n^d）为额外时间复杂度
    if(log(b,a))>d=>O(nlog(b,a);
    else if(log(b,a)==d)=>O(n^d*log(b,a));
    else log(b,a)<d =>O(n^d);
    master前提：你划分的子过程的规模是一样的。
*/
    static int littlesum(int a[], int b[], int l, int r);

    static int max(int number1, int number2);

    static int min(int minnumber1, int minnumber2);

    static int bocketNum(int a[], int i, int min, int max, int len);
};


#endif //UNTITLED1_SORTOTHERS_H

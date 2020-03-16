#include "../Mylife_H/SortOthers.h"


void SortOthers::Patitions(int *Array, int len, int number) {
    int p = 0, left = 0, right = len - 1;
    while (p <= right)
    {
        if (Array[p] < number)
            swap(Array, p++, left);
        else if (Array[p] > number)
            swap(Array, p, right--);
        else
            p++;
    }
}

void SortOthers::swap(int *Array, int i, int j) {
    int temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}

int SortOthers::LittleSums(int *a, int len) {
    int *b = new int[len], Liltlesum = littlesum(a, b, 0, len - 1);
    delete[] b;
    return Liltlesum;
}

int SortOthers::littlesum(int *a, int *b, int l, int r) {
    if (l >= r)
        return 0;
    int m = (l + r) / 2;
    return littlesum(a, b, l, m) + littlesum(a, b, m + 1, r) + mergeSum(a, b, l, m, r);
}

int SortOthers::mergeSum(int *a, int *b, int l, int m, int r) {
    int Sum = 0, i = l, j = m + 1, k = l;
    while (k <= r)
    {
        if (i > m)
            b[k++] = a[j++];
        else if (j > r)
            b[k++] = a[i++];
        else
        {
            if (a[i] > a[j])
                b[k++] = a[j++];
            else
            {
                Sum += a[i] * (r - j + 1);
                b[k++] = a[i++];
            }
        }
    }

    for (int k = l; k <= r; k++)
        a[k] = b[k];
    return Sum;
}

int SortOthers::GetMax(int *Array, int Leftindex, int Rightindex) {
    if (Leftindex == Rightindex)
        return Array[Leftindex];
    int minndex = (Leftindex + Rightindex) / 2;
    return max(GetMax(Array, Leftindex, minndex), GetMax(Array, minndex + 1, Rightindex));
}

int SortOthers::max(int number1, int number2) {
    int maxnumber=number1>number2?number1:number2;
    return maxnumber;
}

int SortOthers::GetMin(int *Array, int Leftindex, int Rightindex) {
    if (Leftindex == Rightindex)
        return Array[Leftindex];
    int minndex = (Leftindex + Rightindex) / 2;
    return min(GetMin(Array, Leftindex, minndex), GetMin(Array, minndex + 1, Rightindex));
}

int SortOthers::min(int minnumber1, int minnumber2) {
    int minnumber=minnumber1>minnumber2?minnumber2:minnumber1;
    return minnumber;
}

int SortOthers::maxGap(int *Array, int lenght) {
    int minnumber = GetMin(Array, 0, lenght - 1), maxnumber = GetMax(Array, 0, lenght - 1), *minArr = new int[lenght + 1], *maxArr = new int[lenght + 1];
    bool *hasNum =new bool[lenght + 1];

    /*
        求出每一个数所在的桶的编号
    */

    for (int i = 0; i < lenght; ++i)
    {
        int bocketID = bocketNum(Array, i, minnumber, maxnumber, lenght);
        minArr[bocketID] = hasNum[bocketID] ? min(minArr[bocketID], Array[i]) : Array[i];
        maxArr[bocketID] = hasNum[bocketID] ? max(maxArr[bocketID], Array[i]) : Array[i];
        hasNum[bocketID] = true;
    }

    int MaxGap = 0, LastMax = 0, i = 0;

    while (i < lenght + 1)
    {
        while (i < lenght + 1 && hasNum[i])
            i++;
        if (i == lenght + 1)
            break;
        LastMax = maxArr[i - 1];
        while (i < lenght + 1 && !hasNum[i])
            i++;
        if (i == lenght + 1)
            break;
        MaxGap = max(MaxGap, minArr[i] - LastMax);
    }
    return MaxGap;
}

int SortOthers::bocketNum(int *a, int i, int min, int max, int len) {
    return (a[i] - min) * len / (max - min);
}

void SortOthers::rendom(int *Array, int Lenght) {
    for (int k = 0; k < Lenght; k++)
    {
        Array[k] = rand() % Lenght;
    }
}
#include <iostream>
#include <ntdef.h>
#include <commctrl.h>
#include <algorithm>
#define MaxLenght 10000
#include "../Mylife_H/Sort.h"

void Sort::maxSelectSort(int *Array, int lenght) {
    for (int i = 0; i < lenght; i++)
    {
        for (int j = i + 1; j < lenght; j++)
            if (Array[i] < Array[j])
                swap(Array, i, j);
    }
}

void Sort::swap(int *Array, int i, int j) {
    int temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}

void Sort::minSelectSort(int *Array, int lenght) {
    for (int i = 0; i < lenght; i++)
    {
        for (int j = i + 1; j < lenght; j++)
            if (Array[i] > Array[j])
                swap(Array, i, j);
    }
}

void Sort::PrintArray(int *Array, int Lenght) {
    for (int i = 0; i < Lenght; i++)
        std::cout << Array[i] << " ";
}

void Sort::maxBubbleSort(int *Array, int lenght) {
    for (int i = 0; i < lenght - 1; i++)
    {
        for (int j = 0; j < lenght - 1; j++)
            if (Array[j] < Array[j + 1])
                swap(Array, j, j + 1);
    }
}

void Sort::minBubbleSort(int *Array, int lenght) {
    for (int i = 0; i < lenght - 1; i++)
    {
        for (int j = 0; j < lenght - 1; j++)
            if (Array[j] > Array[j + 1])
                swap(Array, j, j + 1);
    }
}

void Sort::minInsertionSort(int *Array, int lenght) {
    for (int i = 1; i < lenght; i++)
    {
        for (int j = i - 1; j >= 0 && Array[j] > Array[j + 1]; j--)
            swap(Array, j, j + 1);
    }
}

void Sort::maxInsertionSort(int *Array, int lenght) {
    for (int i = 1; i < lenght; i++)
    {
        for (int j = i - 1; j >= 0 && Array[j] < Array[j + 1]; j--)
            swap(Array, j, j + 1);
    }
}

void Sort::MergerSort(int *Array, int Lenght) {
    int *Arrayhelp = new int[Lenght];
    mergeSortHelper(Array, Arrayhelp, 0, Lenght - 1);
    delete[] Arrayhelp;
}

void Sort::mergeSortHelper(int *Array, int *Arrayhelp, int Left, int Right) {
    if (Left >= Right)
        return;
    int Mid = (Left + Right) / 2;
    mergeSortHelper(Array, Arrayhelp, Left, Mid);
    mergeSortHelper(Array, Arrayhelp, Mid + 1, Right);
    Merger(Array, Arrayhelp, Left, Mid, Right);
}

void Sort::Merger(int *Array, int *Arrayhelp, int Left, int Mid, int Right) {
    int i = Left, j = Mid + 1, k = Left;
    while (k <= Right)
    {
        if (i > Mid)
            Arrayhelp[k++] = Array[j++];
        else if (j > Right)
            Arrayhelp[k++] = Array[i++];
        else
            Arrayhelp[k++] = Array[i] > Array[j] ? Array[j++] : Array[i++];
    }
    for (int k = Left; k <= Right; k++)
        Array[k] = Arrayhelp[k];
}

void Sort::QuickSort(int *Array, int Left, int Right) {
    if (Left < Right)
    {
        int Mid = patition_Sort(Array, Left, Right);
        QuickSort(Array, Left, Mid);
        QuickSort(Array, Mid + 1, Right);
    }
}

int Sort::patition_Sort(int *Array, int Left, int Right) {
    int i = Left, j = Right + 1, temp = Array[Left];
    /*i为左半部分的第一个下标 ,j为右半部分的第一个下标 ，temp为//第一个元素 。whille循环功能是从左到右找更大的，从右到左找更小的。*/
    while (true)
    {
        /*检查数组是否有序，如果无序，则i和j分别存储前面比a[p]大，后面比a[p]小的元素的值*/
        while (i < Right && Array[++i] < temp)
            ;
        while (Array[--j] > temp)
            ;
        if (i >= j)
            break; /*数组无序*/
        swap(Array, i, j);
    }
    swap(Array, j, Left);
    return j;
}

void Sort::RandQuickSort(int *Array, int Left, int q) {
    if (Left < q)
    {
        int Right = random_patition(Array, Left, q);
        RandQuickSort(Array, Left, Right - 1);
        RandQuickSort(Array, Right + 1, q);
    }
}

int Sort::random_patition(int *Array, int Left, int Right) {
    int tempHelp, i = Left - 1, k = Left + rand() % (Right - Left + 1);
    //仍然将随机的枢轴交换到最后
    swap(Array, Right, k);
    tempHelp = Array[Right];
    /*保证左边的值永远比temp小,如果是比第i项大，好，去交换值，这样据保证了左半部分一定是有顺序的，而右面却没有  */
    for (int j = Left; j <= Right - 1; j++)
        if (Array[j] <= tempHelp)
            swap(Array, ++i, j);
    //最后主元交换，因为当结束后所有数据都有序了，但是第i+项和末尾项应该位置是相反的，及最后的那一项即为所求项。
    swap(Array, i + 1, Right);
    return ++i;
}

void Sort::heapSort(int *Array, int Lenght) {
    for (int i = Lenght / 2 - 1; i >= 0; i--)
        adjust(Array, Lenght, i);
    // 调整大根堆,将当前最大的放置到数组末尾,将未完成排序的部分继续进行堆排序
    for (int i = Lenght - 1; i >= 1; i--)
    {
        swap(Array, 0, i);
        adjust(Array, i, 0);
    }
}

void Sort::adjust(int *Array, int Lenght, int indexs) {
    int Leftindex = 2 * indexs + 1, Rightindex = 2 * indexs + 2, maxIdx = indexs;
    if (Leftindex < Lenght && Array[Leftindex] > Array[maxIdx])
        maxIdx = Leftindex;
    if (Rightindex < Lenght && Array[Rightindex] > Array[maxIdx])
        maxIdx = Rightindex;
    if (maxIdx != indexs)
    {
        swap(Array, maxIdx, indexs);
        adjust(Array, Lenght, maxIdx);
    }
}

void Sort::CountSort(int *Array, int n) {
    std::string errorstring = "你输入的数据过大，本算法适用于极小规模运算";
    if (n > 100)
    {
        std::cout << errorstring;
        return;
    }
    int *sorted_arr = new int[n], *count_arr = new int[MaxLenght], i;
    //初始化计数数组,统计i的次数
    for (i = 0; i < MaxLenght; i++)
        count_arr[i] = 0;
    for (i = 0; i < n; i++)
        count_arr[Array[i]]++;

    //对所有的计数累加,逆向遍历源数组（保证稳定性），根据计数数组中对应的值填充到先的数组中
    for (i = 1; i < 100; i++)
        count_arr[i] += count_arr[i - 1];
    for (i = n; i > 0; i--)
    {
        sorted_arr[count_arr[Array[i - 1]] - 1] = Array[i - 1];
        count_arr[Array[i - 1]]--;
    }

    for (int i = 0; i < n; i++)
        Array[i] = sorted_arr[i];
}

void Sort::RadixSort(int *Array, int n) {
    int d = maxbit(Array, n), radix = 1, TempHelp[MaxLenght], count[MaxLenght];
    for (int i = 0; i < d; i++)
    {
        /**
            * 首先进行清桶的操作,
            * 统计每个桶中含有数字的数量,
            * 将tmp中的位置依次分配给每个桶,
            * 意思就是为每个桶里面还有的数量都留下够用的空间
        **/
        for (int j = 0; j < 10; j++)
            count[j] = 0;
        for (int j = 0; j < n; j++)
        {
            int k = (Array[j] / radix) % 10;
            count[k]++;
        }
        for (int j = 1; j < 10; j++)
            count[j] += count[j - 1];
        /**
            * 这里想不明白可以理解为相邻两个数位之间的差表示的就是给这个桶分配的空间；
        **/
        /**
            * 将桶中的记录依次收集到tmp中,
            * 得到他在哪一个桶里面,因为上面已经给这个桶留下了相应的空间，
            * 所以只需要一次向后减1，就可以排到适当的位置
        **/
        for (int j = n - 1; j >= 0; j--)
        {
            int k = (Array[j] / radix) % 10;
            TempHelp[count[k] - 1] = Array[j];
            count[k]--;
        }
        /**
            * 将临时数组的内容复制到data数组中
        **/
        for (int j = 0; j < n; j++)
            Array[j] = TempHelp[j];
        radix *= 10;
    }
}

int Sort::maxbit(int *Array, int n) {
    int max_num = 1, num = 10;
    for (int i = 0; i < n; i++)
    {
        while (Array[i] >= num)
        {
            num *= 10;
            max_num++;
        }
    }
    return max_num;
}


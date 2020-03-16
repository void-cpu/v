#ifndef UNTITLED1_SORT_H
#define UNTITLED1_SORT_H

class Sort {
public:

    static void maxSelectSort(int Array[], int lenght);

    static void minSelectSort(int Array[], int lenght);

    static void PrintArray(int Array[], int Lenght);

    static void maxBubbleSort(int Array[], int lenght);

    static void minBubbleSort(int Array[], int lenght);

    static void minInsertionSort(int Array[], int lenght);

    static void maxInsertionSort(int Array[], int lenght);

    static void MergerSort(int Array[], int Lenght);

    static void QuickSort(int Array[], int Left, int Right);

    static void RandQuickSort(int *Array, int Left, int q);

    static void heapSort(int Array[], int Lenght);

    static void CountSort(int Array[], int n);
    /**
        函数说明：
            实现基数排序
        参数说明：
            data：数据数组
            n：data数组的最高位
    **/
    static void RadixSort(int Array[], int n);

private:

    static void swap(int Array[], int i, int j);

    static void Merger(int Array[], int Arrayhelp[], int Left, int Mid, int Right);

    static void mergeSortHelper(int Array[], int Arrayhelp[], int Left, int Right);

    static int patition_Sort(int Array[], int Left, int Right);

    static int random_patition(int Array[], int Left, int Right);

    static void adjust(int Array[], int Lenght, int indexs);

    static int maxbit(int Array[], int n);
};

#endif //UNTITLED1_SORT_H

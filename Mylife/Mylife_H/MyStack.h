#ifndef UNTITLED1_MYSTACK_H
#define UNTITLED1_MYSTACK_H
/**
        *类的作用：实现栈的基本功能。
        * MyStack函数功能:初始化栈空间
        *deleteMyStack函数功能:回收栈空间内存
        *clearStack函数功能:清空栈
        *stackEmpty函数功能:判空栈，若空返回true
        *stackFull函数功能:判满栈，若满返回true
        *stackLength函数功能:栈中元素个数
        *push(elem)函数功能:元素入栈，栈顶上升
        *stackpop(char &elem)函数功能:元素出栈，栈顶下降
        *stackTraverse(bool isFromBottom)函数功能:遍历栈中元素 isFromBottom=1，从栈底遍历
        **m_pBuffer 栈空间指针
        *m_isize 栈容量
        * m_itop 栈顶，也是栈中元素个数
    * **/
class MyStack {
public:
    explicit MyStack(int size);

    ~MyStack();

    static void clearStack();

    static bool stackEmpty();

    static bool stackFull();

    static int stackLength();

    static void stackpush(char elem);

    static void stackpop(char &elem);

    static void stackTraverse(bool isFromBottom);
private:
    static char *m_pBuffer;
    static int m_isize, m_itop;
};


#endif //UNTITLED1_MYSTACK_H

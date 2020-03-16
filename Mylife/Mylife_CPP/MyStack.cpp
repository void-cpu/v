//
// Created by void on 2020/3/16.
//
#include <iostream>
#include "../Mylife_H/MyStack.h"

MyStack::MyStack(int size) {
    m_isize = size;
    m_pBuffer = new char[size];
    m_itop = 0;
}

MyStack::~MyStack() {
    delete[] m_pBuffer;
}

void MyStack::clearStack() {
    m_itop = 0;
}

bool MyStack::stackEmpty() {
    return 0 == m_itop;
}

bool MyStack::stackFull() {
    return m_isize == m_itop;
}

int MyStack::stackLength() {
    return m_itop;
}

void MyStack::stackpush(char elem) {
    if (stackFull())
        return;
    m_pBuffer[m_itop] = elem;
    m_itop++;
}

void MyStack::stackpop(char &elem) {
    if (stackEmpty())
        return;
    m_itop--;
    elem = m_pBuffer[m_itop];
}

void MyStack::stackTraverse(bool isFromBottom) {
    if (isFromBottom)
        for (int i = 0; i < m_itop; i++)
           std:: cout << m_pBuffer[i] << " ";
    else
        for (int i = m_itop - 1; i >= 0; i--)
            std::cout << m_pBuffer[i] << " ";
}

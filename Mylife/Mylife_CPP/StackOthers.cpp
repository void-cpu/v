//
// Created by void on 2020/3/16.
//

#include "../Mylife_H/StackOthers.h"

void StackOthers::maxpushStack(int number) {
    stack1.push(number);
    if (stack2.empty())
        stack2.push(number);
    else if (number >= stack2.top())
        stack2.push(number);
}

int StackOthers::popStack() {
    int num1;
    if (stack1.top() == stack2.top())
    {
        stack1.pop();
        num1 = stack2.top();
        stack2.pop();
    }
    else
    {
        num1 = stack1.top();
        stack1.pop();
    }
    return num1;
}

void StackOthers::minpushStack(int number) {
    stack1.push(number);
    if (stack2.empty())
        stack2.push(number);
    else if (number <= stack2.top())
        stack2.push(number);
}

void StackOthers::QueueToStack_push(int x) {
    if (!Date.empty())
    {
        Help.push(x);
        while (!Date.empty())
        {
            Help.push(Date.front());
            Date.pop();
        }
    }else{
        Date.push(x);
        while (!Help.empty())
        {
            Date.push(Help.front());
            Help.pop();
        }
    }
}

void StackOthers::QueueToStack_pop() {
    if (!Date.empty() && Help.empty())
        std::cout << "The Stack is empty." << std::endl;
    else if (!Date.empty())
        Date.pop();
    else
        Help.pop();
}

bool StackOthers::QueueToStack_empty() {
    return (Date.empty() && Help.empty());
}

int StackOthers::QueueToStack_top() {
    if (!Date.empty() && Help.empty())
        std::cout << "The Stack is empty" << std::endl;
    else if (!Date.empty())
        return Date.front();
    else
        return Help.front();
}

void StackOthers::StackToQueue_push(int x) {
    if (!Datestack.empty())
    {
        Helpskack.push(x);
        while (!Datestack.empty())
        {
            Helpskack.push(Datestack.top());
            Datestack.pop();
        }
    }else{
        Datestack.push(x);
        while (!Helpskack.empty())
        {
            Datestack.push(Helpskack.top());
            Helpskack.pop();
        }
    }
}

void StackOthers::StackToQueue_pop() {
    if (!Datestack.empty() && Helpskack.empty())
        std::cout << "The Queue is empty" << std::endl;
    else if (!Datestack.empty())
        Datestack.pop();
    else
        Helpskack.pop();
}

bool StackOthers::StackToQueue_empty() {
    return (Datestack.empty() && Helpskack.empty());
}

int StackOthers::top() {
    if (!Datestack.empty())
        return Datestack.top();
    else
        Helpskack.top();
}

void StackOthers::spiralOrderPrint(std::vector<std::vector<int> > matrix) {
    int tR = 0, tC = 0, dR = matrix.size() - 1, dC = matrix[0].size() - 1;
    while (tR <= dR && tC <= dC)printEdge(matrix, tR++, tC++, dR--, dC--);
}

void StackOthers::printEdge(std::vector<std::vector<int> > m, int tR, int tC, int dR, int dC) {
    if (tR == dR){
        for (int i = tC; i <= dC; i++)
            std::cout << m[tR][i] << " ";
    }else if (tC == dC){
        for (int i = tR; i < dR; i++)
            std::cout << m[tC][i] << " ";
    }else{
        int curC = tC, curR = tR;
        while (curC != dC)
            std::cout << m[tR][curC++] << " ";
        while (curR != dR)
            std::cout << m[curR++][dC] << " ";
        while (curC != tC)
            std::cout << m[dR][curC--] << " ";
        while (curR != tR)
            std::cout << m[curR--][tC] << " ";
    }
}

void StackOthers::spiralOrderPrint90(std::vector<std::vector<int> > matrix) {
    int tR = 0, tC = 0, dR = matrix.size() - 1, dC = matrix[0].size() - 1;
    while (tR <= dR && tC <= dC) printEdgeprintEdge(matrix, tR++, tC++, dR--, dC--);
}

void StackOthers::Rotate(std::vector<std::vector<int> > &matrix) {
    if (matrix.empty())
        return;
    else{
        int tmp, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m / 2; i++)
            for (int j = i + 1; j < n - i; j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
    }
}

void StackOthers::printEdgeprintEdge(std::vector<std::vector<int> > m, int tR, int tC, int dR, int dC) {
    int times = dC - tC;
    int tmp = 0;
    for (int i = 0; i != times; i++)
    {
        tmp = m[tR][tC + i];
        m[tR][tC + i] = m[dR - i][tC];
        m[dR - i][tC] = m[dR][dC - i];
        m[dR][dC - i] = m[tR + i][dC];
        m[tR + i][dC] = tmp;
    }
}

void StackOthers::PrintZhi(std::vector<std::vector<int> > Array) {
    int Aa, Ab, Ba, Bb, ENDR = Array.size() - 1, ENDC = Array[0].size() - 1;
    bool FormUp = false;

    while (Aa != ENDR + 1)
    {
        PrintLeven(Array, Aa, Ab, Ba, Bb, FormUp);
        Aa = Ab == ENDC ? Aa + 1 : Aa;
        Ab = Ab == ENDC ? Ab : Ab + 1;
        Bb = Bb == ENDR ? Bb + 1 : Bb;
        Ba = Ba == ENDR ? Ba : Ba + 1;
        FormUp = !FormUp;
    }
    std::cout << std::endl;
}

std::vector<int> StackOthers::printMatrix(std::vector<std::vector<int> > Array, int n, int m) {
    std::vector<int> ans;
    int dir = 1;

    for (int i = 0; i < n; i++){
        if (dir > 0){
            for (int j = 0; j < m; j++)
                ans.push_back(Array[i][j]);
        }else{
            for (int j = m - 1; j >= 0; j--)
                ans.push_back(Array[i][j]);
        }
        dir = -1 * dir;
    }
    return ans;
}

void StackOthers::PrintLeven(std::vector<std::vector<int> > Array, int tr, int tc, int dr, int dc, bool f) {
    if (f){
        while (tr != dr + 1)
            std::cout << Array[tr++][tc--] << " ";
    }else{
        while (dr != tr - 1)
            std::cout << Array[dr--][dc++] << " ";
    }
}



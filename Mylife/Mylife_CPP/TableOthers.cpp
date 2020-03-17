#include "../Mylife_H/TableOthers.h"

table::SingleNode *TableOthers::reverseList(table::SingleNode *head) {
    SingleNode *pre = nullptr;
    SingleNode *next = nullptr;
    //head为当前，pre为之前，next为之后
    while(nullptr != head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

table::DoubleNode *TableOthers::reverseList(table::DoubleNode *head)  {
    DoubleNode *pre = nullptr;
    DoubleNode *next = nullptr;
    while(nullptr != head)
    {
        next = head->next;
        head->next = pre;
        head->pre = next;    //多了一步前置处理
        pre = head;
        head = next;
    }
    return pre;
}

void TableOthers::printList(table::SingleNode *head)  {
    while(nullptr != head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void TableOthers::printList(table::DoubleNode *head){
        while(nullptr != head)
        {
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
}

void TableOthers::input(int n) {
    SingleNode *shead = nullptr,*sptr = nullptr;
    DoubleNode *dhead = nullptr,*dptr = nullptr;
    for(int i =0;i<n;i++)
    {
        if(nullptr == shead && nullptr == dhead)
        {
            shead = new SingleNode;
            shead->value = i;
            shead->next = nullptr;
            sptr = shead;

            dhead = new DoubleNode;
            dhead->value = i;
            dhead->next = nullptr;
            dhead->pre = nullptr;
            dptr = dhead;
            continue;
        }
        sptr->next = new SingleNode;
        sptr = sptr->next;
        sptr->value = i;
        sptr->next = nullptr;

        dptr->next = new DoubleNode;
        dptr->next->pre = dptr;
        dptr = dptr->next;
        dptr->value = i;
        dptr->next = nullptr;
    }
}

bool TableOthers::isContanin(vector<vector<int> > &matrix, int k) {
    int row = 0;
    int col = matrix[0].size() - 1;
    while(row < matrix.size() && col > -1)
    {
        if(matrix[row][col] == k)
            return true;
        else if(matrix[row][col] > k)
            --col;
        else
            ++row;
    }
    return false;
}

void TableOthers::printComPart(table::SingleNode *head1, table::SingleNode *head2){
    cout << "Common Part: " << endl;
    while(nullptr != head1 && nullptr != head2)
    {
        if(head1->value < head2->value)
            head1 = head1->next;
        else if(head1->value > head2->value)
            head2 = head2->next;
        else
        {
            cout << head1->value << " " ;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    cout << endl;
}

bool TableOthers::isPalindrome1(table::SingleNode *head) {
        stack<SingleNode> s;
        SingleNode *cur = head;
        while(nullptr != cur)
        {
            s.push(*cur);    //将链表节点全部压入栈中
            cur  = cur->next;
        }
        while(nullptr != head)
        {
            if(head->value != s.top().value)
                return false;
            s.pop();
            head = head->next;
        }
        return true;
}

void TableOthers::printLists(table::SingleNode *head) {
        while(nullptr != head)
        {
            cout << head->value << " " ;
            head = head->next;
        }
        cout << endl;
}

bool TableOthers::isPalindrome2(table::SingleNode *head)     {
    if(nullptr == head || nullptr == head->next)
        return true;
    SingleNode *right = head->next;
    SingleNode *cur = head;
    while(nullptr != cur->next && nullptr != cur->next->next)
    {
        right = right->next;
        cur = cur->next->next;
    }
    stack<SingleNode> s;
    while(nullptr != right)
    {
        s.push(*right);        //将链表的右半部分压入栈
        right = right->next;
    }
    while(!s.empty())
    {
        if(head->value != s.top().value)
            return false;
        s.pop();
        head = head->next;
    }
    return true;
}

bool TableOthers::isPalindrome3(table::SingleNode *head)     {
    if(nullptr == head || nullptr == head->next)
        return true;
    SingleNode *n1(head),*n2(head);
    while(nullptr != n2 && nullptr != n2->next)
    {
        n1 = n1->next;    //找到中间节点
        n2 = n2->next->next;
    }
    n2 = n1->next;    //右半部分的第一个节点
    n1->next =nullptr;
    SingleNode *n3 = nullptr;
    while(nullptr != n2)    //反转右半部分链表
    {
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    n3 = n1;    //记录最后一个节点
    n2 = head;    //记录头节点
    bool res = true;
    while(nullptr != n1 && nullptr != n2)
    {
        if(n1->value != n2->value)
        {
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    n1 = n3->next;
    n3->next = nullptr;
    while(nullptr != n1)
    {
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
    return res;
}

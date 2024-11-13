#include<iostream>
#include <stdlib.h>
using namespace std;
typedef int SElemType;
typedef int Status;

#define OK 1
#define ERROR 0

// 链栈结构体定义 
typedef struct SNode {
    SElemType data;
    SNode* next;
} SNode, * LinkStack;

// 将元素e入栈 
Status Push(LinkStack& S, SElemType e) {
    SNode* newNode = new SNode;
    if (!newNode) return ERROR;  // 分配失败
    newNode->data = e;
    newNode->next = S;
    S = newNode;
    return OK;
}

// 出栈，用e返回出栈元素 
Status Pop(LinkStack& S, SElemType& e) {
    if (S == NULL) return ERROR;  // 栈空
    SNode* p = S;
    e = p->data;
    S = S->next;
    delete p;
    return OK;
}

// 返回栈顶元素 
Status GetTop(LinkStack S, SElemType& e) {
    if (S == NULL) return ERROR;  // 栈空
    e = S->data;
    return OK;
}

// 清空栈，变为空栈 
void Clear(LinkStack& S) {
    SNode* p;
    while (S) {
        p = S;
        S = S->next;
        delete p;
    }
}

// 遍历栈元素（从栈顶到栈底） 
void Traverse(LinkStack S) {
    SNode* p = S;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 判断输入字符串是否为回文
void HuiWen() {
    string str;
    cout << "输入字符串: ";
    cin >> str;

    LinkStack S = NULL;
    for (char ch : str) {  // 将字符串压入栈中
        Push(S, ch);
    }

    bool isPalindrome = true;
    for (char ch : str) {  // 出栈检查回文
        SElemType top;
        Pop(S, top);
        if (ch != top) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "\"" << str << "\" 是回文" << endl;
    else
        cout << "\"" << str << "\" 不是回文" << endl;
}

// 主程序
int main(void) {
    LinkStack st = NULL;
    int c = 0;
    while (c != 7) {
        cout << endl << "1. 入栈";
        cout << endl << "2. 出栈";
        cout << endl << "3. 读栈顶";
        cout << endl << "4. 遍历栈";
        cout << endl << "5. 清空栈";
        cout << endl << "6. 回文判断";
        cout << endl << "7. 退出";
        cout << endl << "选择功能(1~7):";
        cin >> c;

        SElemType e;
        switch (c) {
        case 1:
            cout << "输入入栈元素: ";
            cin >> e;
            if (Push(st, e) == OK)
                cout << "元素 " << e << " 入栈成功！" << endl;
            else
                cout << "入栈失败！" << endl;
            break;
        case 2:
            if (Pop(st, e) == OK)
                cout << "出栈元素: " << e << endl;
            else
                cout << "栈为空，无法出栈！" << endl;
            break;
        case 3:
            if (GetTop(st, e) == OK)
                cout << "栈顶元素: " << e << endl;
            else
                cout << "栈为空！" << endl;
            break;
        case 4:
            cout << "栈中元素为: ";
            Traverse(st);
            break;
        case 5:
            Clear(st);
            cout << "栈已清空！" << endl;
            break;
        case 6:
            HuiWen();
            break;
        case 7:
            cout << "程序退出！" << endl;
            Clear(st);  // 退出前清空栈
            break;
        default:
            cout << "无效的选择，请重新输入！" << endl;
        }
    }
    return 0;
}

#include<iostream>
using namespace std;
typedef int SElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

// 顺序栈结构体定义 
typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
} SqStack;

// 初始化栈 
Status InitStack(SqStack& S) {
    S.base = new SElemType[STACK_INIT_SIZE];
    if (!S.base) return ERROR;  // 分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

// 将元素e入栈 
Status Push(SqStack& S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {  // 栈满，扩展空间
        SElemType* newbase = new SElemType[S.stacksize + STACKINCREMENT];
        if (!newbase) return ERROR;  // 分配失败
        for (int i = 0; i < S.stacksize; i++) {
            newbase[i] = S.base[i];
        }
        delete[] S.base;
        S.base = newbase;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

// 出栈，用e返回出栈元素 
Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base) return ERROR;  // 栈空
    e = *--S.top;
    return OK;
}

// 返回栈顶元素 
Status GetTop(SqStack S, SElemType& e) {
    if (S.top == S.base) return ERROR;  // 栈空
    e = *(S.top - 1);
    return OK;
}

// 清空栈，变为空栈 
void Clear(SqStack& S) {
    S.top = S.base;
}

// 遍历栈元素（从栈底到栈顶） 
void Traverse(SqStack S) {
    SElemType* p = S.base;
    while (p != S.top) {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

// 进制转换函数, 将十进制数dec转化为n进制数, 并输出转换后结果 
void Convert(int dec, int n) {
    SqStack S;
    InitStack(S);
    while (dec != 0) {
        Push(S, dec % n);
        dec /= n;
    }
    SElemType e;
    while (Pop(S, e) == OK) {
        if (e < 10)
            cout << e;
        else
            cout << char(e - 10 + 'A');
    }
    cout << endl;
}

// 主程序 
int main(void) {
    SqStack st;
    InitStack(st);
    int c = 0;
    while (c != 7) {
        cout << endl << "1. 入栈";
        cout << endl << "2. 出栈";
        cout << endl << "3. 读栈顶";
        cout << endl << "4. 遍历栈";
        cout << endl << "5. 清空顺序栈";
        cout << endl << "6. 进制转换";
        cout << endl << "7. 退出";
        cout << endl << "选择功能(1~7):";
        cin >> c;
        SElemType e;
        int dec, n;
        switch (c) {
        case 1:
            cout << "输入入栈元素:";
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
            cout << "输入十进制数和目标进制 (例如: 100 2): ";
            cin >> dec >> n;
            cout << dec << " 的 " << n << " 进制表示为: ";
            Convert(dec, n);
            break;
        case 7:
            cout << "程序退出！" << endl;
            break;
        default:
            cout << "无效的选择，请重新输入！" << endl;
        }
    }
    delete[] st.base;
    return 0;
}

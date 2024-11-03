#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;

// 结点定义 
typedef struct LNode {
    ElemType data;  // 数据域
    struct LNode* next;  // 指针域
} Lnode, * LinkList;

// 按照值大小插入元素，构造有序单链表
void InsertInOrder(LinkList& L, ElemType e) {
    Lnode* newNode = new Lnode;
    newNode->data = e;
    newNode->next = nullptr;

    // 如果链表为空或者插入的元素比头结点小
    if (!L || L->next == nullptr || L->next->data >= e) {
        newNode->next = L ? L->next : nullptr; // 如果L为空，直接插入
        if (L) {
            L->next = newNode;
        }
        else {
            L = new Lnode; // 创建头结点
            L->next = newNode;
        }
        return;
    }

    // 查找插入位置
    Lnode* current = L->next;
    Lnode* prev = L;

    while (current && current->data < e) {
        prev = current;
        current = current->next;
    }

    newNode->next = current;
    prev->next = newNode;
}

// 遍历单链表 
void Traverse(LinkList L) {
    Lnode* current = L->next; // 跳过头结点
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(void) {
    LinkList L = nullptr; // 初始化链表
    int n;
    cout << "输入要插入的元素个数: ";
    cin >> n;

    cout << "输入元素: ";
    for (int i = 0; i < n; ++i) {
        ElemType e;
        cin >> e;
        InsertInOrder(L, e); // 按顺序插入元素
    }

    cout << "有序单链表中的元素为: ";
    Traverse(L); // 遍历输出链表

    return 0;
}

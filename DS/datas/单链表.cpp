#include<iostream>
using namespace std;
typedef int ElemType;
typedef int Status;

// 结点定义 
typedef struct LNode {
    ElemType data;  // 数据域
    struct LNode* next;  // 指针域
} Lnode, * LinkList;

//1. 用尾插法构造单链表
void CreateListTail(LinkList& L, int n) {
    L = new Lnode; // 创建头结点
    L->next = nullptr;
    Lnode* tail = L;
    for (int i = 0; i < n; ++i) {
        Lnode* newNode = new Lnode;
        cin >> newNode->data;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
}

//2. 用头插法构造单链表
void CreateListHead(LinkList& L, int n) {
    L = new Lnode; // 创建头结点
    L->next = nullptr; // 初始化头结点的指针
    for (int i = 0; i < n; ++i) {
        Lnode* newNode = new Lnode;
        cin >> newNode->data;
        newNode->next = L->next; // 插入到头部
        L->next = newNode; // 更新头结点的指针
    }
}

//3. 返回单链表中第i个结点的值 
Status GetElem(LinkList L, int i, ElemType& e) {
    int index = 1;
    Lnode* current = L->next; // 跳过头结点
    while (current && index < i) {
        current = current->next;
        index++;
    }
    if (!current || index > i) return 0; // 返回0表示失败
    e = current->data;
    return 1; // 成功
}

//4. 在单链表i位置插入元素e 
Status ListInsert(LinkList& L, int i, ElemType e) {
    if (i < 1) return 0;
    Lnode* newNode = new Lnode;
    newNode->data = e;
    newNode->next = nullptr;
    Lnode* current = L;
    int index = 0;
    while (current && index < i - 1) {
        current = current->next;
        index++;
    }
    if (!current) return 0; // 插入位置无效
    newNode->next = current->next;
    current->next = newNode;
    return 1; // 成功
}

//5. 删除单链表中位于i位置的结点
Status ListDelete(LinkList& L, int i, ElemType& e) {
    if (!L->next) return 0; // 链表为空
    Lnode* current = L;
    int index = 0;
    while (current->next && index < i - 1) {
        current = current->next;
        index++;
    }
    if (!current->next || index > i - 1) return 0; // 未找到第i个元素
    Lnode* toDelete = current->next;
    e = toDelete->data;
    current->next = toDelete->next;
    delete toDelete;
    cout << "已删除第" << i << "个元素" << endl;
    return 1; // 成功
}

//6. 清空单链表 
void ClearList(LinkList& L) {
    Lnode* current = L;
    while (current) {
        Lnode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    L = nullptr;
}

//7. 遍历单链表 
void Traverse(LinkList L) {
    Lnode* current = L->next; // 跳过头结点
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//8. 销毁单链表 
void DestroyList(LinkList& L) {
    ClearList(L);
}

//9. 删除单链表中值为e的结点
void DeleteElem(LinkList& L, ElemType e) {
    if (!L->next) {
        cout << "链表为空" << endl;
        return;
    }
    Lnode* current = L;
    while (current->next) {
        if (current->next->data == e) {
            Lnode* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
            cout << "已删除" << e << "元素" << endl;
            return;
        }
        current = current->next;
    }
    cout << "未找到" << e << "元素" << endl;
}

int main(void) {
    LinkList L;
    L = new Lnode; // 头结点
    L->next = nullptr;
    int c = 0;
    while (c != 9) {
        cout << endl << "1. 头插法创建单链表";
        cout << endl << "2. 尾插法创建单链表";
        cout << endl << "3. 在单链表中查找第i个元素";
        cout << endl << "4. 在单链表中第i个位置插入元素";
        cout << endl << "5. 在单链表中删除第i个元素";
        cout << endl << "6. 在单链表中删除e元素";
        cout << endl << "7. 遍历单链表";
        cout << endl << "8. 销毁单链表";
        cout << endl << "9. 退出";
        cout << endl << "选择功能(1~9):";
        cin >> c;
        switch (c) {
        case 1: {
            int n;
            cout << "输入元素个数: ";
            cin >> n;
            CreateListHead(L, n);
            Traverse(L);
            break;
        }
        case 2: {
            int n;
            cout << "输入元素个数: ";
            cin >> n;
            CreateListTail(L, n);
            Traverse(L);
            break;
        }
        case 3: {
            int i;
            ElemType e;
            cout << "输入位置i: ";
            cin >> i;
            if (GetElem(L, i, e))
                cout << "第" << i << "个元素是: " << e << endl;
            else
                cout << "未找到第" << i << "个元素" << endl;
            break;
        }
        case 4: {
            int i;
            ElemType e;
            cout << "输入位置i和元素e: ";
            cin >> i >> e;
            if (ListInsert(L, i, e))
            {
                cout << "插入成功" << endl;
                Traverse(L);
            }
            else
                cout << "插入失败" << endl;
            break;
        }
        case 5: {
            int i;
            ElemType e;
            cout << "输入位置i: ";
            cin >> i;
            if (ListDelete(L, i, e))
            {
                cout << "已删除第" << i << "个元素，值为" << e << endl;
                Traverse(L);
            }
            else
                cout << "删除失败" << endl;
            break;
        }
        case 6: {
            ElemType e;
            cout << "输入值e: ";
            cin >> e;
            DeleteElem(L, e);
            Traverse(L);
            break;
        }
        case 7: {
            Traverse(L);
            break;
        }
        case 8: {
            DestroyList(L);
            cout << "销毁成功！";
            break;
        }
        case 9: {
            cout << "结束操作" << endl;
            exit(0);
            break;
        }
        }
    }
    return 0;
}


#include<iostream>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define OVERFLOW -2
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
typedef int ElemType;
typedef int Status;
using namespace std;

//顺序表结构体定义 
typedef  struct {
	ElemType* elem;    // 存储空间基址
	int length;        // 当前长度
	int listsize;      // 当前分配的存储容量 
} SqList;  // 顺序表

// 1.构造一个最大容量为 LIST_INIT_SIZE的顺序表 
Status InitList(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
} // InitList

// 2.在顺序表中查询第一个满足判定条件的数据元素，若存在，则返回它的位序，否则返回 0
int LocateElem(SqList &L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	int j = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			j = i + 1;
			return j;
		}
	}
	return 0;
} // LocateElem 

// 3.在顺序表L的第 i 个位置插入新的元素e 
Status ListInsert(SqList& L, int i, ElemType e) {
	L.length = L.length + 1;
	for (int j = L.length; j >= i; j--)
		L.elem[j] = L.elem[j-1];
	L.elem[i - 1] = e;
	return 1;
} // ListInsert                         

// 4.删除顺序表L的第 i 个元素，用e 返回其值 
Status ListDelete(SqList& L, int i, ElemType& e) {
	e = L.elem[i - 1];
	for (int j = i - 1; j < L.length; j++)
		L.elem[j] = L.elem[j + 1];
	L.length = L.length - 1;
	return e;
} // ListDelete

//5查找顺序表中的最大值，并将最大值移动到顺序表的末尾。其余元素线性关系不变。
//给出函数定义
Status findmax(SqList& L)
{
	int max=0;
	int max_p = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] > max)
		{
			max = L.elem[i];
			max_p = i; //列表序列
		}
	}
	L.elem[L.length] = max;
	L.length++;
	ListDelete(L, max_p+1,L.elem[L.length]);//先删除最大值在原表中的数据
	return 1;
}

//依次输入线性表的元素，存储在顺序结构中 
Status CreateList(SqList& L) {
	int lsize = 0;
	cout << "输入线性表元素个数:" << endl;
	cin >> lsize;
	if (lsize > L.listsize)
		return ERROR;
	cout << "输入线性表元素:" << endl;
	for (int i = 0; i < lsize; i++)
		cin >> L.elem[i];
	L.length = lsize;
	return TRUE;
}

//遍历输出顺序表的元素 
void Traverse(SqList L) {
	cout << "顺序表的数据为:";
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << " ";
}

//比较函数 
Status compare(ElemType a, ElemType b) {
	if (a == b)
		return TRUE;
	else
		return FALSE;
}

//销毁顺序表 
void DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}

int main(void) {
	int position;
	ElemType elem;
	SqList sl;
	int c = 0;
	while (c != 9) {
		cout << endl << "1. 创建空顺序表";
		cout << endl << "2. 将线性表元素存入顺序表";
		cout << endl << "3. 在顺序表中插入元素";
		cout << endl << "4. 在顺序表中删除元素";
		cout << endl << "5. 在顺序表中查找元素";
		cout << endl << "6. 查找最大值并移动至末尾";
		cout << endl << "7. 遍历顺序表";
		cout << endl << "8. 销毁顺序表";
		cout << endl << "9. 退出";
		cout << endl << "选择功能(1~9):";
		cin >> c;
		switch (c) {
		case 1: {
			if (InitList(sl))
				cout << "空顺序表创建成功。";
			else
				cout << "空顺序表创建失败。";
			break;
		}
		case 2: {
			if (CreateList(sl))
				Traverse(sl);
			else
				cout << "顺序表存储失败.";
			break;
		}
		case 3: {
			cout << "请输入插入位置：" << endl;
			cin >> position;
			cout << "请输入要插入的数据:";
			cin >> elem;
			if (ListInsert(sl, position, elem)) {
				cout << "插入成功！";
				Traverse(sl);
			}
			else {
				cout << "插入失败！";
				Traverse(sl);
			}
			break;
		}
		case 4: {
			cout << "输入要删除数据的位置：" << endl;
			cin >> position;
			if (ListDelete(sl, position, elem)) {
				cout << "删除成功！";
				Traverse(sl);
			}
			else {
				cout << "删除失败！";
				Traverse(sl);
			}
			break;
		}
		case 5: {
			cout << "请输入查找的数据:" << endl;
			cin >> elem;
			position = LocateElem(sl, elem, compare);
			cout << "你所查找的数据在第" << position << "个位置" << endl;
			Traverse(sl);
			break;
		}
		case 6: {
			//请学生完成对“查找最大值并移动至末尾”函数的测试
			findmax(sl);
			Traverse(sl);
			// 遍历输出修改之后的顺序表
			break;
		}
		case 7: {
			Traverse(sl);
			break;
		}
		case 8: {
			DestroyList(sl);
			cout << "销毁完毕" << endl;
			break;
		}
		case 9: {
			cout << "结束操作" << endl;
			exit(0);
			break;
		}
		}
	}
}

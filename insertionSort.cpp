//插入排序

#include <iostream>
#include <ctime>

using namespace std;

/*
template<class T>
void insert(T a[], int n, const T& x) { //把x插入有序数组a[0:n-1]中合适位置
	int i;
	for(i = n-1; i >= 0 && x < a[i]; i--) { //从后往前逐个检查
		a[i+1] = a[i];
	}
	a[i+1] = x;
}

template<class T>
void insertionSort(T a[], int n) {
	for(int i = 1; i < n; i++) {
		T t = a[i];
		insert(a, i, t);
	}
}
*/

template<class T>
void insertionSort(T a[], int n) {
	for(int i = 1; i < n; i++) {
		T t = a[i];
		//把a[i]插入到a[0:i-1]
		int j;
		for(j = i-1; j >= 0 && t < a[j]; j--) {
			a[j+1] = a[j];
		}
		a[j+1] = t;
	}
}

int main() {
	int a[1000], step = 10;
	double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000; //每毫秒滴答一次

	cout << "The worst-case time, in milliseconds, are" << endl;
	cout << "n \tRepetitions \t Total Ticks \tTime per Sort" <<endl;

	for(int n = 0; n <= 1000; n += step) { //用最坏测试数据初始化
		//为实例特征n测量运行时间
		long numberOfRepetitions = 0;
		clock_t startTime = clock();
		do {
			numberOfRepetitions++;

			for(int i = 0; i < n; i++) { //用最坏测试数据初始化
				a[i] = n - i;
			}

			insertionSort(a, n);
		} while(clock() - startTime < 1000); //重复运行，直到有足够的时间流逝
		
		double elapsedMillis = (clock() - startTime) / clocksPerMillis;
		cout << n << '\t' << numberOfRepetitions << '\t' << elapsedMillis 
		     << '\t' << elapsedMillis / numberOfRepetitions << endl;

		if(n == 100) step = 100;
	}
	return 0;
}


//用链表实现插入排序
typedef struct node
{
    int data;
    struct node *next;
}Node;

void insertAfter(Node *p, Node *pNew)//在指针变量p指向的节点后插入指针变量pNew指向的节点
{
    if(p == NULL || pNew == NULL)//安全检查
    {
        return;
    }
    pNew->next = p->next;
    p->next = pNew;
}

void listInsertBySort(Node **phead, int data)
{
    //安全检查
    if(phead == NULL)
    {
        return;
    }
    //创建新节点
    Node *pNew = createNode(data);
    if(pNew == NULL)
    {
        return;
    }
    if(*phead == NULL)//head为空，原链表中无节点
    {
        *phead = pNew;
        return;//退出函数返回
    }
    //否则原链表中有节点
    //找第一个比data大的节点的前一个节点，并由prev记录
    Node *p = *phead;//由p遍历链表已有的节点
    Node *prev = NULL;//prev指向p所指向的节点的前一个节点
    while(p != NULL)
    {
        if(p->data > data)//找到了第一个比data大的节点
        {
            break;//退出循环
        }
        prev = p;
        p = p->next;
    }
    if(prev != NULL)
    {
        insertAfter(prev, pNew);
    }else
    {
        //插入到链表的头部
        pNew->next = *phead;//*phead即head
        *phead = pNew;
    }
}

#include <iostream>
#include <string>
using namespace std;

//链表结构体，key为每个节点持有的密码0~9
typedef struct node {
	int key = -1;
	struct node* next = NULL;
}Node;

string keyword;//密码序列

//创建循环链表，返回尾节点指针
Node* creatlist(int n)
{
    cout<<"请依次输入每个节点的key值："<<endl;
	Node* head, * p, * pre;
	head = new Node;
	cin >> head->key;
	pre = head;
	while (--n)
	{
		p = new Node;
		cin >> p->key;
		pre->next = p;
		pre = p;
		p = p->next;
	}
	pre->next = head;
	return pre; //tail
}

//计算密码序列，存进keyword中
void getkey(Node* tail, int i, int m)
{
	int t = 1;//t可以当作临时指针，用处很大
	Node* pre = tail, * p = pre->next;//pre为p的前置指针，p为目标指针，初始p指向头节点

	//先找到第i个节点的位置，将p指向它
	while (t < i)
	{
		t++;
		pre = pre->next;
		p = pre->next;
	}

    //此时p已经指向了第i个节点，将t置1，表示开始数了
	t = 1;
	do {
        //没有数到m就是简单的指针后移
		if (t < m) {
			t++;
			pre = pre->next;
			p = pre->next;
		}
        //数到m就取该节点的密码，加到keyword的尾部，并且链表仍然是循环链表
		else {
			t = 1;
			keyword.insert(keyword.end(), p->key + '0');
			pre->next = p->next;
			delete p;
			p = pre->next;

			//判断链表只剩一个节点时直接取该节点密码，并跳出循环
			if (p->next == p)
			{
				keyword.insert(keyword.end(), p->key + '0');
				break;
			}
		}
	} while (true);
}

int main()
{
    //n个人 从第i个人开始数1，数到m的人出列
	int m, n, i;
	cout<<"请输入人数、起始节点序号、数几个出一次："<<endl;
	cin >> n >> i >> m;
	Node* tail = creatlist(n);
	getkey(tail, i, m);
	cout << "密码序列是: " << keyword << endl;
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

//����ṹ�壬keyΪÿ���ڵ���е�����0~9
typedef struct node {
	int key = -1;
	struct node* next = NULL;
}Node;

string keyword;//��������

//����ѭ����������β�ڵ�ָ��
Node* creatlist(int n)
{
    cout<<"����������ÿ���ڵ��keyֵ��"<<endl;
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

//�����������У����keyword��
void getkey(Node* tail, int i, int m)
{
	int t = 1;//t���Ե�����ʱָ�룬�ô��ܴ�
	Node* pre = tail, * p = pre->next;//preΪp��ǰ��ָ�룬pΪĿ��ָ�룬��ʼpָ��ͷ�ڵ�

	//���ҵ���i���ڵ��λ�ã���pָ����
	while (t < i)
	{
		t++;
		pre = pre->next;
		p = pre->next;
	}

    //��ʱp�Ѿ�ָ���˵�i���ڵ㣬��t��1����ʾ��ʼ����
	t = 1;
	do {
        //û������m���Ǽ򵥵�ָ�����
		if (t < m) {
			t++;
			pre = pre->next;
			p = pre->next;
		}
        //����m��ȡ�ýڵ�����룬�ӵ�keyword��β��������������Ȼ��ѭ������
		else {
			t = 1;
			keyword.insert(keyword.end(), p->key + '0');
			pre->next = p->next;
			delete p;
			p = pre->next;

			//�ж�����ֻʣһ���ڵ�ʱֱ��ȡ�ýڵ����룬������ѭ��
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
    //n���� �ӵ�i���˿�ʼ��1������m���˳���
	int m, n, i;
	cout<<"��������������ʼ�ڵ���š���������һ�Σ�"<<endl;
	cin >> n >> i >> m;
	Node* tail = creatlist(n);
	getkey(tail, i, m);
	cout << "����������: " << keyword << endl;
	system("pause");
	return 0;
}

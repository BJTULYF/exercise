#include <iostream>
#include "Graph.h"
#include <queue>
using namespace std;

//------------------------�ڽӾ���------------------------

void CreatGraph(MGraph& G)
{
    int i,v1,v2,t;
    char e1,e2;
    ClearGraph(G);

    cout<<"�����붥�����ͻ�����"<<endl;
    cin>>G.vexnum>>G.arcnum;

    cout<<"�밴˳�����붥�㣺"<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }

    cout<<"���������������������Ԫ���Լ�Ȩֵ��"<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        cin>>e1>>e2>>t;
        v1=findvertex(G,e1);
        v2=findvertex(G,e2);
        G.adjMatrix[v1][v2]=G.adjMatrix[v2][v1]=t;
    }
}

//����ĳ��������±꣬����ֵΪ�±�ֵ
int findvertex(MGraph G, char ch)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i] == ch)
            return i;
    }
    return -1;
}

//���ж�����Ϣ��Ϊ�գ��ڽӾ�����ΪINF
void ClearGraph(MGraph& G)
{
    for(int i=0;i<MAX_VERTEX_NUM;i++)
    {
        G.vexs[i]='\0';
        for(int j=0;j<MAX_VERTEX_NUM;j++)
        {
            G.adjMatrix[i][j]=INF;
        }
    }
}

//ͼG ��ʼ��
void MiniSpanTree_PRIM(MGraph G, char ch)
{
	struct {
		char adjvex;//��ǰ������Ϣ
		int lowcost;//��СȨֵ��Ϊ0��ʾ�Ӷ��㼯��ȥ��
	}closeedge[MAX_VERTEX_NUM];//������������

	//���ҵ�ָ����ʼ�����λ�ã��±꣩
	int k = findvertex(G,ch), i, j, sum=0;

	//�����е�Ȩֵ���븨�����飬������ǰ������Ϊָ������ʼ����
	for (i = 0; i < G.vexnum; i++)
	{
		if (i != k) closeedge[i] = { ch,G.adjMatrix[k][i] };
	}

	closeedge[k].lowcost = 0;//��ָ���Ķ���Ӷ��㼯��ȥ��

	cout << endl << "�����ʽΪ�ߵ��������㼰��Ȩֵ" << endl;
	cout << "i\tj\tr(i,j)" << endl;

	//n�����������n-1���ߣ�ѭ��n-1����Ѱ����Щ��
	for (i = 1; i < G.vexnum; i++)
	{
		//kָ���뵱ǰ�����ڽӵ�Ȩֵ��С�ı�ָ��ĵ��λ�ã��±꣩
		for (j = 0; j < G.vexnum; j++)
		{
			if (closeedge[j].lowcost)//���ȱ�֤������㻹�ڶ��㼯��
			{
				if (!closeedge[k].lowcost || //k�п���ָ��Ļ��ǵ�ǰ����
					closeedge[j].lowcost <= closeedge[k].lowcost) //Ȩֵ��С
						k = j;
			}	
		}

		sum += closeedge[k].lowcost;//�����

		//���i,j,r(i,j)
		cout << closeedge[k].adjvex << '\t' << G.vexs[k] << '\t' << closeedge[k].lowcost << endl;

		closeedge[k].lowcost = 0;//����ǰ����Ӷ��㼯��ȥ��

		//��Ϊ��ǰ���㷢���仯���������鵱ǰ������Ȩֵ��Ҫ����
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.adjMatrix[k][j] < closeedge[j].lowcost)
				closeedge[j] = { G.vexs[k],G.adjMatrix[k][j] };
		}
	}

	cout << "����ۣ� " << sum << endl;
}

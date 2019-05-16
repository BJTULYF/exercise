#include <iostream>
#include "Graph.h"
#include <queue>
using namespace std;

//------------------------邻接矩阵------------------------

void CreatGraph(MGraph& G)
{
    int i,v1,v2,t;
    char e1,e2;
    ClearGraph(G);

    cout<<"请输入顶点数和弧数："<<endl;
    cin>>G.vexnum>>G.arcnum;

    cout<<"请按顺序输入顶点："<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }

    cout<<"请输入各条弧的两个顶点元素以及权值："<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        cin>>e1>>e2>>t;
        v1=findvertex(G,e1);
        v2=findvertex(G,e2);
        G.adjMatrix[v1][v2]=G.adjMatrix[v2][v1]=t;
    }
}

//查找某个顶点的下标，返回值为下标值
int findvertex(MGraph G, char ch)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i] == ch)
            return i;
    }
    return -1;
}

//所有顶点信息置为空，邻接矩阵置为INF
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

//图G 起始点
void MiniSpanTree_PRIM(MGraph G, char ch)
{
	struct {
		char adjvex;//当前顶点信息
		int lowcost;//最小权值，为0表示从顶点集中去除
	}closeedge[MAX_VERTEX_NUM];//辅助顶点数组

	//先找到指定起始顶点的位置（下标）
	int k = findvertex(G,ch), i, j, sum=0;

	//将所有的权值读入辅助数组，并将当前顶点置为指定的起始顶点
	for (i = 0; i < G.vexnum; i++)
	{
		if (i != k) closeedge[i] = { ch,G.adjMatrix[k][i] };
	}

	closeedge[k].lowcost = 0;//将指定的顶点从顶点集中去掉

	cout << endl << "输出格式为边的两个顶点及其权值" << endl;
	cout << "i\tj\tr(i,j)" << endl;

	//n个顶点的树有n-1条边，循环n-1次来寻找这些边
	for (i = 1; i < G.vexnum; i++)
	{
		//k指向与当前顶点邻接的权值最小的边指向的点的位置（下标）
		for (j = 0; j < G.vexnum; j++)
		{
			if (closeedge[j].lowcost)//首先保证这个顶点还在顶点集中
			{
				if (!closeedge[k].lowcost || //k有可能指向的还是当前顶点
					closeedge[j].lowcost <= closeedge[k].lowcost) //权值最小
						k = j;
			}	
		}

		sum += closeedge[k].lowcost;//总造价

		//输出i,j,r(i,j)
		cout << closeedge[k].adjvex << '\t' << G.vexs[k] << '\t' << closeedge[k].lowcost << endl;

		closeedge[k].lowcost = 0;//将当前顶点从顶点集中去掉

		//因为当前顶点发生变化，辅助数组当前顶点与权值需要修正
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.adjMatrix[k][j] < closeedge[j].lowcost)
				closeedge[j] = { G.vexs[k],G.adjMatrix[k][j] };
		}
	}

	cout << "总造价： " << sum << endl;
}

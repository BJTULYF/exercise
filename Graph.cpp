#include <iostream>
#include "Graph.h"
#include <queue>
using namespace std;

//------------------------�ڽӾ���------------------------

void CreatGraph(MGraph& G)
{
    int i,v1,v2;
    char e1,e2;
    ClearGraph(G);

    cout<<"�����붥�����ͻ�����"<<endl;
    cin>>G.vexnum>>G.arcnum;

    cout<<"�밴˳�����붥�㣺"<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }

    cout<<"���������������������Ԫ�أ�"<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        cin>>e1>>e2;
        v1=findvertex(G,e1);
        v2=findvertex(G,e2);
        G.adjMatrix[v1][v2]=G.adjMatrix[v2][v1]=true;
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

//���ж�����Ϣ��Ϊ�գ��ڽӾ�����Ϊ0
void ClearGraph(MGraph& G)
{
    for(int i=0;i<MAX_VERTEX_NUM;i++)
    {
        G.vexs[i]='\0';
        for(int j=0;j<MAX_VERTEX_NUM;j++)
        {
            G.adjMatrix[i][j]=false;
        }
    }
}

//������ͼG ��ʼ��
void DFSTraverse(MGraph G, int k, void(*visit)(char))
{
    bool visited[MAX_VERTEX_NUM];

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //���ȱ�����k��ͨ�ĵ�
    DFS(G, k, visited, visit);

    //�������е㣬ȷ��û����©�ĵ�
    for(int v=0;v<k;v++)
    {
        if(!visited[v])
        {
            DFS(G, v, visited, visit);
        }
    }
    for(int v=k+1;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            DFS(G, v, visited, visit);
        }
    }
}

//�ݹ�������ȱ���ÿ�������ڵ�δ�����ʵĵ�
void DFS(MGraph G, int v, bool visited[], void(*visit)(char))
{
    visit(G.vexs[v]);
    visited[v]=true;
    for(int w=0;w<G.vexnum;w++)
    {
        if(G.adjMatrix[v][w] && !visited[w])
        {
            DFS(G, w, visited, visit);
        }
    }
}

//������ͼG ��ʼ��
void BFSTraverse(MGraph G, int k, void(*visit)(char))
{
    queue<int> Q;
    bool visited[MAX_VERTEX_NUM];
    int t;

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //���ȱ�����k��ͨ�ĵ�
    Q.push(k);
    visited[k]=true;
    while(!Q.empty())
    {
        t = Q.front(); Q.pop();
        visit(G.vexs[t]);
        for(int i=0;i<G.vexnum;i++)
        {
            if(G.adjMatrix[t][i] && !visited[i])
            {
                Q.push(i);
                visited[i]=true;
            }
        }
    }

    //�������е㣬ȷ��û����©�ĵ�
    for(int v=0;v<k;v++)
    {
        if(!visited[v])
        {
            Q.push(v);
            visited[v]=true;
            while(!Q.empty())
            {
                t = Q.front(); Q.pop();
                visit(G.vexs[t]);
                for(int i=0;i<G.vexnum;i++)
                {
                    if(G.adjMatrix[v][i] && !visited[i])
                    {
                        Q.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
    }
    for(int v=k+1;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            Q.push(v);
            visited[v]=true;
            while(!Q.empty())
            {
                t = Q.front(); Q.pop();
                visit(G.vexs[t]);
                for(int i=0;i<G.vexnum;i++)
                {
                    if(G.adjMatrix[v][i] && !visited[i])
                    {
                        Q.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
    }
}

//------------------------�ڽӱ�------------------------

void CreatGraph(ALGraph& G)
{
    int i,v1,v2;
    char e1,e2;
    ArcNode *p,*t;

    cout<<"�����붥�����ͻ�����"<<endl;
    cin>>G.vexnum>>G.arcnum;

    cout<<"�밴˳�����붥�㣺"<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=nullptr;
    }

    cout<<"���������������������Ԫ�أ�"<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        cin>>e1>>e2;
        v1=findvertex(G,e1);
        v2=findvertex(G,e2);

        //��e2��Ϊe1���ڽӵ�
        if(!G.vertices[v1].firstarc)
        {
            G.vertices[v1].firstarc=new ArcNode;
            G.vertices[v1].firstarc->adjvex=v2;
            G.vertices[v1].firstarc->nextarc=nullptr;
        }
        else
        {
            p=G.vertices[v1].firstarc;
            t=p->nextarc;
            while(t)
            {
                p=p->nextarc;
                t=p->nextarc;
            }
            p->nextarc=new ArcNode;
            t=p->nextarc;
            t->adjvex=v2;
            t->nextarc=nullptr;
        }

        //��e1��Ϊe2���ڽӵ�
        if(!G.vertices[v2].firstarc)
        {
            G.vertices[v2].firstarc=new ArcNode;
            G.vertices[v2].firstarc->adjvex=v1;
            G.vertices[v2].firstarc->nextarc=nullptr;
        }
        else
        {
            p=G.vertices[v2].firstarc;
            t=p->nextarc;
            while(t)
            {
                p=p->nextarc;
                t=p->nextarc;
            }
            p->nextarc=new ArcNode;
            t=p->nextarc;
            t->adjvex=v1;
            t->nextarc=nullptr;
        }
    }
}

//����ĳ��������±꣬����ֵΪ�±�ֵ
int findvertex(ALGraph G, char ch)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data == ch)
            return i;
    }
    return -1;
}

void ClearGraph(ALGraph& G)
{
    ArcNode *p,*t;
    for(int i=0;i<G.vexnum;i++)
    {
        G.vertices[i].data='\0';
        p=G.vertices[i].firstarc;
        if(p)
        {
            if(p->nextarc)
            {
                t=p->nextarc;
                while(t)
                {
                    delete p;
                    p=t;
                    t=t->nextarc;
                }
            }
            else
            {
                delete p;
            }
        }
    }
}

//������ͼG ��ʼ��
void DFSTraverse(ALGraph G, int k, void(*visit)(char))
{
    bool visited[MAX_VERTEX_NUM];

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //���ȱ�����k��ͨ�ĵ�
    DFS(G, k, visited, visit);

    //�������е㣬ȷ��û����©�ĵ�
    for(int v=0;v<k;v++)
    {
        if(!visited[v])
        {
            DFS(G, v, visited, visit);
        }
    }
    for(int v=k+1;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            DFS(G, v, visited, visit);
        }
    }
}

//��ÿ�����㶼���ȷ����������ڵ�һ����
void DFS(ALGraph G, int v, bool visited[], void(*visit)(char))
{
    ArcNode* p;
    if(!visited[v])
    {
        visited[v] = true;
        visit(G.vertices[v].data);
        p=G.vertices[v].firstarc;
        while(p)
        {
            DFS(G, p->adjvex, visited, visit);
            p=p->nextarc;
        }
    }
}

//������ͼG ��ʼ��
void BFSTraverse(ALGraph G, int k, void(*visit)(char))
{
    queue<int> Q;
    bool visited[MAX_VERTEX_NUM];
    int t;
    ArcNode* p;

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //���ȱ�����k��ͨ�ĵ�
    Q.push(k);
    visited[k]=true;
    while(!Q.empty())
    {
        t=Q.front(); Q.pop();
        visit(G.vertices[t].data);
        p=G.vertices[t].firstarc;
        while(p)
        {
            if(!visited[p->adjvex])
            {
                Q.push(p->adjvex);
                visited[p->adjvex]=true;
            }
            p=p->nextarc;
        }
    }

    //�������е㣬ȷ��û����©�ĵ�
    for(int v=0;v<k;v++)
    {
        if(!visited[v])
        {
            Q.push(v);
            visited[v]=true;
            while(!Q.empty())
            {
                t=Q.front(); Q.pop();
                visit(G.vertices[t].data);
                p=G.vertices[t].firstarc;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        Q.push(p->adjvex);
                        visited[p->adjvex]=true;
                    }
                    p=p->nextarc;
                }
            }
        }

    }
    for(int v=k+1;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            Q.push(v);
            visited[v]=true;
            while(!Q.empty())
            {
                t=Q.front(); Q.pop();
                visit(G.vertices[t].data);
                p=G.vertices[t].firstarc;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        Q.push(p->adjvex);
                        visited[p->adjvex]=true;
                    }
                    p=p->nextarc;
                }
            }
        }
    }
}

//------------------------ͨ�ú���------------------------
void VisitFunc(char ch)
{
    cout<<ch<<ends;
}

#include <iostream>
#include "Graph.h"
#include <queue>
using namespace std;

//------------------------邻接矩阵------------------------

void CreatGraph(MGraph& G)
{
    int i,v1,v2;
    char e1,e2;
    ClearGraph(G);

    cout<<"请输入顶点数和弧数："<<endl;
    cin>>G.vexnum>>G.arcnum;

    cout<<"请按顺序输入顶点："<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }

    cout<<"请输入各条弧的两个顶点元素："<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        cin>>e1>>e2;
        v1=findvertex(G,e1);
        v2=findvertex(G,e2);
        G.adjMatrix[v1][v2]=G.adjMatrix[v2][v1]=true;
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

//所有顶点信息置为空，邻接矩阵置为0
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

//参数：图G 起始点
void DFSTraverse(MGraph G, int k, void(*visit)(char))
{
    bool visited[MAX_VERTEX_NUM];

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //优先遍历与k连通的点
    DFS(G, k, visited, visit);

    //遍历所有点，确保没有遗漏的点
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

//递归深度优先遍历每个点相邻的未被访问的点
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

//参数：图G 起始点
void BFSTraverse(MGraph G, int k, void(*visit)(char))
{
    queue<int> Q;
    bool visited[MAX_VERTEX_NUM];
    int t;

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //优先遍历与k连通的点
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

    //遍历所有点，确保没有遗漏的点
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

//------------------------邻接表------------------------

void CreatGraph(ALGraph& G)
{
    int i,v1,v2;
    char e1,e2;
    ArcNode *p,*t;

    cout<<"请输入顶点数和弧数："<<endl;
    cin>>G.vexnum>>G.arcnum;

    cout<<"请按顺序输入顶点："<<endl;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=nullptr;
    }

    cout<<"请输入各条弧的两个顶点元素："<<endl;
    for(i=0;i<G.arcnum;i++)
    {
        cin>>e1>>e2;
        v1=findvertex(G,e1);
        v2=findvertex(G,e2);

        //将e2作为e1的邻接点
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

        //将e1作为e2的邻接点
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

//查找某个顶点的下标，返回值为下标值
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

//参数：图G 起始点
void DFSTraverse(ALGraph G, int k, void(*visit)(char))
{
    bool visited[MAX_VERTEX_NUM];

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //优先遍历与k连通的点
    DFS(G, k, visited, visit);

    //遍历所有点，确保没有遗漏的点
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

//对每个顶点都优先访问与他相邻的一个点
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

//参数：图G 起始点
void BFSTraverse(ALGraph G, int k, void(*visit)(char))
{
    queue<int> Q;
    bool visited[MAX_VERTEX_NUM];
    int t;
    ArcNode* p;

    for(int i=0;i<MAX_VERTEX_NUM;i++) visited[i]=false;

    //优先遍历与k连通的点
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

    //遍历所有点，确保没有遗漏的点
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

//------------------------通用函数------------------------
void VisitFunc(char ch)
{
    cout<<ch<<ends;
}

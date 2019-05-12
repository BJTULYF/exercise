#ifndef _GRAPH
#define _GRAPH

#define MAX_VERTEX_NUM  20//最大顶点个数

//------------------------邻接矩阵------------------------

//邻接矩阵表示的图
typedef struct
{
    char vexs[MAX_VERTEX_NUM];//顶点向量
    bool adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
    int vexnum, arcnum;//顶点数、弧数
}MGraph;

void CreatGraph(MGraph& G);//创建图

int findvertex(MGraph G, char ch);//查找顶点序号

void ClearGraph(MGraph& G);//清空图

void DFSTraverse(MGraph G, int, void(*visit)(char));//深搜

void DFS(MGraph G, int v, bool visited[], void(*visit)(char));//递归深度优先遍历

void BFSTraverse(MGraph G, int, void(*visit)(char));//广搜

//------------------------邻接表------------------------

//弧结构体
typedef struct ArcNode
{
    int adjvex;//该弧所指向的顶点的位置
    struct ArcNode* nextarc;//下一条弧
}ArcNode;

//顶点结构体
typedef struct VNode
{
    char data;//顶点信息
    ArcNode* firstarc;//第一条依附该顶点的弧
}VNode, AdjList[MAX_VERTEX_NUM];

//邻接表表示的图
typedef struct
{
    AdjList vertices;//顶点数组
    int vexnum, arcnum;//顶点数、弧数
}ALGraph;

void CreatGraph(ALGraph& G);//创建图

int findvertex(ALGraph G, char ch);//查找顶点序号

void ClearGraph(ALGraph& G);//清空图

void DFSTraverse(ALGraph G, int, void(*visit)(char));//深搜

void DFS(ALGraph G, int v, bool visited[], void(*visit)(char));//递归深度优先遍历

void BFSTraverse(ALGraph G, int, void(*visit)(char));//广搜

//------------------------通用函数------------------------

void VisitFunc(char ch);//顶点操作函数

#endif // _GRAPH

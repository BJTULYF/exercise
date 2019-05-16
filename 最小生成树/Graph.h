#ifndef _GRAPH
#define _GRAPH

#define INF INT_MAX
#define MAX_VERTEX_NUM  20//最大顶点个数

//------------------------邻接矩阵------------------------

//邻接矩阵表示的图
typedef struct
{
    char vexs[MAX_VERTEX_NUM];//顶点向量
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
    int vexnum, arcnum;//顶点数、弧数
}MGraph;

void CreatGraph(MGraph& G);//创建图

int findvertex(MGraph G, char ch);//查找顶点序号

void ClearGraph(MGraph& G);//清空图

void MiniSpanTree_PRIM(MGraph G, char ch);//普利姆算法求邻接矩阵表示的图的最小生成树

#endif // _GRAPH

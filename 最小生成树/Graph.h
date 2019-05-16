#ifndef _GRAPH
#define _GRAPH

#define INF INT_MAX
#define MAX_VERTEX_NUM  20//��󶥵����

//------------------------�ڽӾ���------------------------

//�ڽӾ����ʾ��ͼ
typedef struct
{
    char vexs[MAX_VERTEX_NUM];//��������
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
    int vexnum, arcnum;//������������
}MGraph;

void CreatGraph(MGraph& G);//����ͼ

int findvertex(MGraph G, char ch);//���Ҷ������

void ClearGraph(MGraph& G);//���ͼ

void MiniSpanTree_PRIM(MGraph G, char ch);//����ķ�㷨���ڽӾ����ʾ��ͼ����С������

#endif // _GRAPH

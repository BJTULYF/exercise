#ifndef _GRAPH
#define _GRAPH

#define MAX_VERTEX_NUM  20//��󶥵����

//------------------------�ڽӾ���------------------------

//�ڽӾ����ʾ��ͼ
typedef struct
{
    char vexs[MAX_VERTEX_NUM];//��������
    bool adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
    int vexnum, arcnum;//������������
}MGraph;

void CreatGraph(MGraph& G);//����ͼ

int findvertex(MGraph G, char ch);//���Ҷ������

void ClearGraph(MGraph& G);//���ͼ

void DFSTraverse(MGraph G, int, void(*visit)(char));//����

void DFS(MGraph G, int v, bool visited[], void(*visit)(char));//�ݹ�������ȱ���

void BFSTraverse(MGraph G, int, void(*visit)(char));//����

//------------------------�ڽӱ�------------------------

//���ṹ��
typedef struct ArcNode
{
    int adjvex;//�û���ָ��Ķ����λ��
    struct ArcNode* nextarc;//��һ����
}ArcNode;

//����ṹ��
typedef struct VNode
{
    char data;//������Ϣ
    ArcNode* firstarc;//��һ�������ö���Ļ�
}VNode, AdjList[MAX_VERTEX_NUM];

//�ڽӱ��ʾ��ͼ
typedef struct
{
    AdjList vertices;//��������
    int vexnum, arcnum;//������������
}ALGraph;

void CreatGraph(ALGraph& G);//����ͼ

int findvertex(ALGraph G, char ch);//���Ҷ������

void ClearGraph(ALGraph& G);//���ͼ

void DFSTraverse(ALGraph G, int, void(*visit)(char));//����

void DFS(ALGraph G, int v, bool visited[], void(*visit)(char));//�ݹ�������ȱ���

void BFSTraverse(ALGraph G, int, void(*visit)(char));//����

//------------------------ͨ�ú���------------------------

void VisitFunc(char ch);//�����������

#endif // _GRAPH

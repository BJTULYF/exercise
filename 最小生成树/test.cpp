#include <iostream>
#include "Graph.h"
using namespace std;
void testMGraph()
{
	MGraph G;
	char ch;
	CreatGraph(G);
	cout << "��������ʼ���㣺 ";
	cin >> ch;
	MiniSpanTree_PRIM(G,ch);
}
int main()
{
	testMGraph();
	return 0;
}
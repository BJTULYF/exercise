#include "Graph.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void testMGraph()
{
    int choice,k;
    char ch;
    MGraph G;
    system("cls");
    cout<<"您的选择是： 邻接矩阵"<<endl;
    CreatGraph(G);
    while(true)
    {
        system("cls");
        cout<<"请选择：1、深搜 2、广搜 0、回主菜单"<<endl;
        cout<<"您的选择： ";
        cin>>choice;
        if(choice)
        {
            switch(choice)
            {
            case 1:
                system("cls");
                cout<<"您的选择是：深搜"<<endl;
                cout<<"请选择遍历起始顶点：";
                cin>>ch;
                k=findvertex(G,ch);
                DFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            case 2:
                system("cls");
                cout<<"您的选择是：广搜"<<endl;
                cout<<"请选择遍历起始顶点：";
                cin>>ch;
                k=findvertex(G,ch);
                BFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            default:
                system("cls");
                cout<<"您的输入不合法，请重新输入。"<<endl;
                cout<<"按任意键回到上一级菜单"<<endl<<endl;
            }
            system("pause");
        }
        else
        {
            ClearGraph(G);
            break;
        }
    }
}

void testALGraph()
{
    int choice,k;
    char ch;
    ALGraph G;
    system("cls");
    cout<<"您的选择是： 邻接表"<<endl;
    CreatGraph(G);
    while(true)
    {
        system("cls");
        cout<<"请选择：1、深搜 2、广搜 0、回主菜单"<<endl;
        cout<<"您的选择： ";
        cin>>choice;
        if(choice)
        {
            switch(choice)
            {
            case 1:
                system("cls");
                cout<<"您的选择是：深搜"<<endl;
                cout<<"请选择遍历起始顶点：";
                cin>>ch;
                k=findvertex(G,ch);
                DFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            case 2:
                system("cls");
                cout<<"您的选择是：广搜"<<endl;
                cout<<"请选择遍历起始顶点：";
                cin>>ch;
                k=findvertex(G,ch);
                BFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            default:
                system("cls");
                cout<<"您的输入不合法，请重新输入。"<<endl;
                cout<<"按任意键回到上一级菜单"<<endl<<endl;
            }
            system("pause");
        }
        else
        {
            ClearGraph(G);
            break;
        }
    }
}

int main()
{
    int choice;
    while(true)
    {
        system("cls");
        cout<<"请选择操作："<<endl;
        cout<<"1: 邻接矩阵"<<endl;
        cout<<"2: 邻接表"<<endl;
        cout<<"0: 退出程序"<<endl<<endl;
        cout<<"您的选择： ";
        cin>>choice;
        if(choice)
            switch(choice)
            {
            case 1:
                testMGraph();
                break;
            case 2:
                testALGraph();
                break;
            default:
                system("cls");
                cout<<"您的输入不合法，请重新输入！"<<endl;
                cout<<"请按任意键返回主菜单"<<endl<<endl;
                system("pause");
            }
        else break;
    }
    return 0;
}

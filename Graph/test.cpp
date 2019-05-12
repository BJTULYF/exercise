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
    cout<<"����ѡ���ǣ� �ڽӾ���"<<endl;
    CreatGraph(G);
    while(true)
    {
        system("cls");
        cout<<"��ѡ��1������ 2������ 0�������˵�"<<endl;
        cout<<"����ѡ�� ";
        cin>>choice;
        if(choice)
        {
            switch(choice)
            {
            case 1:
                system("cls");
                cout<<"����ѡ���ǣ�����"<<endl;
                cout<<"��ѡ�������ʼ���㣺";
                cin>>ch;
                k=findvertex(G,ch);
                DFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            case 2:
                system("cls");
                cout<<"����ѡ���ǣ�����"<<endl;
                cout<<"��ѡ�������ʼ���㣺";
                cin>>ch;
                k=findvertex(G,ch);
                BFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            default:
                system("cls");
                cout<<"�������벻�Ϸ������������롣"<<endl;
                cout<<"��������ص���һ���˵�"<<endl<<endl;
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
    cout<<"����ѡ���ǣ� �ڽӱ�"<<endl;
    CreatGraph(G);
    while(true)
    {
        system("cls");
        cout<<"��ѡ��1������ 2������ 0�������˵�"<<endl;
        cout<<"����ѡ�� ";
        cin>>choice;
        if(choice)
        {
            switch(choice)
            {
            case 1:
                system("cls");
                cout<<"����ѡ���ǣ�����"<<endl;
                cout<<"��ѡ�������ʼ���㣺";
                cin>>ch;
                k=findvertex(G,ch);
                DFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            case 2:
                system("cls");
                cout<<"����ѡ���ǣ�����"<<endl;
                cout<<"��ѡ�������ʼ���㣺";
                cin>>ch;
                k=findvertex(G,ch);
                BFSTraverse(G,k,VisitFunc);
                cout<<endl;
                break;
            default:
                system("cls");
                cout<<"�������벻�Ϸ������������롣"<<endl;
                cout<<"��������ص���һ���˵�"<<endl<<endl;
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
        cout<<"��ѡ�������"<<endl;
        cout<<"1: �ڽӾ���"<<endl;
        cout<<"2: �ڽӱ�"<<endl;
        cout<<"0: �˳�����"<<endl<<endl;
        cout<<"����ѡ�� ";
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
                cout<<"�������벻�Ϸ������������룡"<<endl;
                cout<<"�밴������������˵�"<<endl<<endl;
                system("pause");
            }
        else break;
    }
    return 0;
}

#include <iostream>
using namespace std;

//二叉树的结构
typedef struct BiTree{
    int key;//关键字
    struct BiTree *lchild, *rchild;//左右子树
}BTNode, *BT;

void CreatTree(BT &T, int *arr, int length);//创建二叉树
bool Search_Insert(BT &T, int key);//查找插入一体化
void InOrderTraversal(BT T);//中序遍历

//创建二叉树.使用到了插入函数
//参数:树T,关键字序列arr,序列长度length  无返回值
void CreatTree(BT &T, int *arr, int length){
    for(int i = 0; i < length; ++i){
        Search_Insert(T, arr[i]);
    }
}

//递归查找关键字,找到返回true
//未找到创建一个节点插入到树的叶子上,并返回false
//参数:树T,关键字key  返回值为bool,表示关键字是否存在
bool Search_Insert(BT &T, int key){
    if(!T){
        T = new BTNode;
        T->key = key;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return 0;
    }
    else if(T->key == key) return 1;
    else if(key < T->key) Search_Insert(T->lchild, key);
    else Search_Insert(T->rchild, key);
}

//中序遍历
void InOrderTraversal(BT T){
    if(T){
        InOrderTraversal(T->lchild);
        cout << T->key << ' ';
        InOrderTraversal(T->rchild);
    }
}

int main(){
    //直接定义一个默认的关键字序列,便于测试
    int arr[] = {23, 45, 16, 37, 3, 99, 22};
    int length = 7;
    BT T = nullptr;
    int key;//key是用户用于查找和插入的关键字变量
    CreatTree(T, arr, length);//基于arr创建一个BS树

    //打印创建好的BS树
    cout << "中序遍历结果： ";
    InOrderTraversal(T);
    cout << endl;

    //循环操作,可使用Ctrl+Z直接结束程序
    while(true){
        cout << "请输入要查找的关键字： ";
        cin >> key;

        //函数返回值为true表示查找到了,为false表示没找到
        //没有找到的话该函数会自行插入该关键字
        if(Search_Insert(T,key)){
            cout << "查找成功！" << endl;
        }else{
            cout << "未查找到，已成功插入该关键字！" << endl;

            //要把插入后的BS树打印出来
            cout << "插入后中序遍历结果： ";
            InOrderTraversal(T);
            cout << endl;
        }
    }
}
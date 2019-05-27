#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    int *elem;//哈希表元素数组,动态分配,必要时重建
    int count;//当前数据元素个数
    int hashsize;//当前哈希表表长
}HashTable;

void CreatHash(HashTable &H, int *arr, int length, int &divisor);//创建哈希表
bool SearchHash(HashTable H, int key, int &p, int &c, int divisor);//查找
bool InsertHash(HashTable &H, int key, int divisor);//插入
int get_divisor(int length);//得到最合适的除数
void PrintHash(HashTable H);//打印哈希表

//创建哈希表
//参数: 哈希表结构体H, 待处理关键字序列arr, 序列长length
void CreatHash(HashTable &H, int *arr, int length, int &divisor){
    int i;
    //装载因子=记录数/表长 <= 0.7
    //表长 >= 记录数/0.7
    //取表长 = [记录数/0.7]向上取整
    H.hashsize = ceil(length/0.7);
    H.count = 0;
    H.elem = new int[H.hashsize];
    divisor = get_divisor(H.hashsize);
    for(i=0; i<H.hashsize; ++i) H.elem[i] = 0;
    for(i=0; i<length; ++i) InsertHash(H, arr[i], divisor);
}

//查找
//参数: 哈希表结构体H, 关键字key, 插入位置p, 冲突次数c, 除数divisor
//冲突次数从0开始计数, 查找次数是冲突次数+1
bool SearchHash(HashTable H, int key, int &p, int &c, int divisor){
    p = key%divisor;
    while(H.elem[p] && H.elem[p]!=key){
        p += ++c;
    }
    if(H.elem[p]==key) return true;
    else return false;
}

//插入
//参数: 哈希表结构体H, 关键字key, 除数divisor
bool InsertHash(HashTable &H, int key, int divisor){
    int c = 0, p;
    //在哈希表中查找,找到返回true;未找到则插入该关键字,返回false
    if(SearchHash(H, key, p, c, divisor)) return true;
    else{
        H.elem[p] = key;
        ++H.count;
        return false;
    }
}

//原则上除数应该是最接近表长且小于表长的一个素数
//参数: 哈希表表长
//返回值: 除留余数法的除数
int get_divisor(int length){
    int i;
    for(i=2; i<=sqrt(length); ++i){
        if(length%i==0) return get_divisor(--length);
    }
    return length;
}

//打印哈希表
void PrintHash(HashTable H){
    int i;
    cout << endl << "哈希表的关键字序列如下: " << endl;
    for(i=0; i<H.hashsize; ++i) cout << i << "\t";
    cout << endl;
    for(i=0; i<H.hashsize; ++i) cout << H.elem[i] << "\t";
    cout << endl;
}

int main(){
    HashTable H;
    //变量解释: 关键字, 关键字序列, 序列长, 除数, 哈希地址, 冲突次数
    int key, arr[100], length=0, divisor, p, c;
    cout << endl << "请输入一个整型序列, 以0为结束标志(不得多于100个关键字): " << endl;
    while(true){
        cin >> key;
        if(key && length<=100) arr[length++] = key;
        else break;
    }
    CreatHash(H, arr, length, divisor);
    PrintHash(H);

    //循环查找/插入关键字, 输入0结束
    while(true){
        cout << endl << "请输入要查找或插入的关键字: ";
        cin >> key;
        if(!key) break;
        if(SearchHash(H, key, p, c, divisor))
            cout << endl << "查找成功, 该关键字的哈希地址为:" << p << ", 查找次数为:" << c+1 << endl;
        else{
            InsertHash(H, key, divisor);
            cout << endl << "插入成功, 插入的哈希地址为:" << p << endl;
            PrintHash(H);
        }
    }
}
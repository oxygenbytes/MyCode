#include <bits/stdc++.h>
using namespace std;

vector<int> root,size;
/*
    1 vector的初始化方式见createUF函数
    2 并查集最核心的函数就是findRoot,其他的函数都要依赖这个函数，查找根是其他操作的基础
      并查集本质上是森林上树根之间的操作
*/
void createUF(int n){
    root = vector<int> (n+1);
    size = vector<int> (n+1,1); // 初始化的时候，第一个是容量，第二个是默认值
    for(int i = 0;i <= n;i++)
        root[i] = i;
}

int findRoot(int x){
    if(root[x] == x)
        return x;
    return root[x] = findRoot(root[x]); // 查找x的根并将查找到的根赋值给root[x]
}

bool isSameRoot(int x, int y){
    return findRoot(x) == findRoot(y);
}

void Union(int x, int y){
    int a = findRoot(x);
    int b = findRoot(y);
    if(a == b) return ;
    if(size[a] > size[b])
        root[b] = a;
    else if(size[a] < size[b])
        root[a] = b;
    else{
        root[a] = b;
        ++size[b];
    }
}

int main(){
    int n = 100;
    createUF(n);
    for(int i= 0;i < n;i++){
        if(root[n] != n){
            cerr<<"error"<<endl;
            break;
        }
    }

    Union(3,2);
    Union(2,14);
    
    cout<<findRoot(14)<<endl;
    cout<<"whether 3 and 14 are connected:(1 for true)"<<isSameRoot(3,14)<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct recode{
    string opt;
    double price;
    int amount; 
    bool isvaild; // 是否有效
}rec[5004];

int main(){
    int i = 0;

/*
对于标准输入（也就是一般的键盘输入），需要人为的产生一个EOF，告诉系统输入结束了。
Unix/Linux下一般使用Ctrl+d，Dos/Windows下是Ctrl+z
注意: 还要加一个回车
此时cin流已经处于无效状态了，如果下文要继续使用cin需要加语句cin.clear()，使流处于有效状态。 
 */
    while(cin>>rec[i].opt){
        if(rec[i].opt == "cancel"){
            rec[i].isvaild = false;
            int x;
            cin>>x;
            rec[x-1].isvaild=false;
            ++i;
            continue;
        }
        cin>>rec[i].price>>rec[i].amount;
        rec[i].isvaild=true;
        ++i;
    }
    int n = i;
    set<double> pst;
    for(int i = 0;i < n;i++){
        if(rec[i].isvaild){
            pst.insert(rec[i].price);
        }
    }
    double ansp=0.0;
    long long maxsum = 0;

    for(set<double>::iterator it = pst.begin();it!=pst.end();++it){
        double p = *it;
        long long sumbuy=0,sumsell=0;
        for(i =0;i<n;i++){
            if(rec[i].isvaild == false) continue;
            if(rec[i].opt == "buy" && rec[i].price>=p){
                sumbuy+=rec[i].amount;
            }
            else if(rec[i].opt == "sell" && rec[i].price<=p){
                sumsell+=rec[i].amount;
            }
        }
        long long sum = min(sumsell,sumbuy);
        if(sum>=maxsum){
            maxsum = sum;
            ansp = p;
        }
    }
    printf("%.2lf %lld\n",ansp,maxsum);
    return 0;
}
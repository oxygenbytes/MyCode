#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    vector<string> Permutation(string str){
        vector<string> result;
        int len = str.length();
        if(len == 0) return result;
        BubbleSort(str);
        Permutations(result,str,0,len);
        return result;
    }

    void Permutations(vector<string> & result,string str,int index,int len){
        if(index == len)
            result.push_back(str);
            return ;
        for(int i = index;i < len;i++){
            if(i != index && str[i] == str[index]) continue;
            swap(str[i],str[index]);
            Permutations(result,str,index+1,len);// 递归解决问题，如何用递归解决问题？
            // 首先先确定第一个元素，然后对后面的进行全排列
        }
    }
    void BubbleSort(string &A){
        int i,p;
        bool flag;
        int n = A.length();
        for(i = n-1;i>=0;i--){
            flag = false;
            for(p=0;p<i;p++){
                if(A[p]>A[p+1]){
                    swap(A[p],A[p+1]);
                    flag = true;
                }
            }
            if(flag == false) break;
        }
    }
};
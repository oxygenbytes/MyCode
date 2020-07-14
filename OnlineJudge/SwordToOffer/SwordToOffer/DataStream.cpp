#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> f1;
    int count = 0;
    void Insert(int num)
    {   
        auto it = f1.begin();
        while(it != f1.end()){
            if(num < *it) break;
            ++it;
        }
        f1.insert(it,num);
        ++count;
    }

    double GetMedian()
    { 
        if(count % 2 == 1)
            return f1[count/2];
        else
            return (f1[count/2-1]+f1[count/2]) / 2.0;
    }

};
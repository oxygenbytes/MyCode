// GetMedian

#include <bits/stdc++.h>
using namespace std;

class Solution {
    priority_queue<int,vector<int>, less<int> > p; // 大顶堆，存小的数，从大到小
    priority_queue<int,vector<int>, greater<int> > q; // 小顶堆，存大的数，从小到大
public:
    void Insert(int num)
    {
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2) q.push(p.top()),p.pop();
        if(p.size() + 1 == q.size()) p.push(q.top()),q.pop();
    }

    double GetMedian()
    { 
        return p.size() == q.size() ? (q.top() + p.top()) / 2.0 : p.top();
    }
};
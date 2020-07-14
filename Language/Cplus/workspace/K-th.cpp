#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define limit 10000
#define RANGE  100

int Search(int R[],int low,int high,int k)    //low表示当前查找的范围下界、high表示当前查找范围的上界，k为所要查找的内容
{
    int mid;
    if (low<=high)      //查找区间存在一个及以上元素
    {
        mid=(low+high)/2;  //求中间位置
        if (R[mid]==k) //查找成功返回其逻辑序号mid+1
            return mid+1;
        if (R[mid]>k)  //在R[low..mid-1]中递归查找
            Search(R,low,mid-1,k);
        else              //在R[mid+1..high]中递归查找
            Search(R,mid+1,high,k);
    }
    else
        return 0;
}

int main()
{
	ifstream fin;
	int x;
	int i;
	int a[limit];
	int result;

	fin.open("random_number.txt");
	if(!fin)
    {
		cerr<<"Can not open file 'random_number.txt' "<<endl;
		return -1;
	}

	time_t start, last;


	for(i=0; i<limit; i++)
    {
		fin>>a[i];
	}
    sort(a,a+limit);
    cout<<"请输入所要查找的数字：";
    cin>>x;
    start = clock();
    result = Search(a,0,limit-1,x);
    if(result>0)
        cout<<"序列中第 "<<result<<"个是" <<x<<endl;
    else
        cout<<"没有找到"<<endl;

	cout<<endl;
	last=clock();

	cout<<"Time : "<<last-start<<endl;

	return 0;
}

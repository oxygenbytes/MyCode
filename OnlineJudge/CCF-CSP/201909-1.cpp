// INFO BEGIN
//
// User = 201910013552(张学庆) 
// Group = C/C++ 
// Problem = 小明种苹果 
// Language = CPP11 
// SubmitTime = 2019-09-15 16:11:56 
//
// INFO END

#include <bits/stdc++.h>
using namespace std;

int apple[1024] = {0};
int abandon[1024] = {0};
int main(){
	int n,m;
	cin>>n>>m;
	int temp;
	for(int i = 1;i <= n;i++){
		cin>>apple[i];
			for(int j = 1;j <= m;j++){
					cin>>temp;
					abandon[i] += abs(temp);
			}
	}
	int depart = 0;
	long long int total = 0;
	int num = 1;
	for(int i = 1;i <= n;i++){
		if(depart < abandon[i]){
		
			depart = abandon[i];
			num = i ;
	}
		apple[i] -= abandon[i];
	}
	
	for(int i = 1;i <= n;i++){
		total += apple[i];
	}
	
	cout<<total<<" "<<num<<" "<<depart<<endl;
	return 0;
}
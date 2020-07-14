#include <bits/stdc++.h>
using namespace std;

bool isleapyear(int year){
    if(year%4==0 && year%100)
        return true;
    if(year%400==0){
        return true;
    }
    return false;
}

int month[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int year;
    int days;
    cin>>year;
    cin>>days;
    if(isleapyear(year)) month[2] += 1;
    int m=1,sumday=0;
    while(m <= 12 && sumday < days){
        sumday += month[m++];
    }
    m--;
    cout<<m<<endl<<days-sumday+month[m];
    return 0;

}
#include <iostream>

using namespace std;

void GreedySelect(int n, int s[], int f[], bool ch[]) {
    int i, j;
    ch[1] = true;
    j = 1;
    for (i = 2; i <= n; ++i) {
        if (s[i] >= f[j]) {
            ch[i] = true;
            j = i;
        } else
            ch[i] = false;

    }
}

int main() {
    
    int n = 11;// 活动数
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};// 活动开始时间集合
    int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};// 活动结束时间集合
    bool ch[11];
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << s[i] << "~" << f[i] << endl;
    }
    cout<<"**********"<<endl;
    GreedySelect(n, s, f, ch);
    /*输出活动安排*/
    for (int j = 1; j <= n; ++j) {
        if (ch[j])
            cout << j << ": " << s[j] << "~" << f[j] << endl;
    }
}
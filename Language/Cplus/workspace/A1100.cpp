
#include <iostream>
#include <string>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", 
                "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", 
                "hei", "elo", "syy", "lok", "mer", "jou"};
string s;
int len;
void dtos(int n) {
    if (n / 13) cout << b[n / 13];
    if ((n / 13) && (n % 13)) cout << " ";
    if (n % 13 || n == 0) cout << a[n % 13];
}
void stod() {
    int i = 0;
    int j = 0;
    string s1 = s.substr(0, 3), s2;
    if (len > 4) s2 = s.substr(4, 3);
    for (int k = 1; k <= 12; k++) {
        if (s1 == a[k] || s2 == a[k]) j = k;
        if (s1 == b[k]) i = k;
    }
    cout<<i*13+j<<endl;
}
int main() {
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            dtos(stoi(s));
        else
            stod();
        cout << endl;
    }
    return 0;
}
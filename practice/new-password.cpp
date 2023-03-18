#include <bits/stdc++.h>
using namespace std;

int itr = 1;

void execute() {
    bool isProperUpper = false;
    bool isProperLower = false;
    bool isProperDigit = false;
    bool isProperSpecial = false;
    
    unordered_set<char> specials {'#', '@', '*', '&'};
    int len;
    cin>>len;
    string s;
    cin>>s;
    for(auto c: s) {
        if (c >= 65 && c <= 90) isProperUpper = true;
        else if (c >= 97 && c <= 122) isProperLower = true;
        else if (c >= 48 && c <= 57) isProperDigit = true;
        else if (specials.count(c)) isProperSpecial = true;
    }
    
    if (!isProperUpper) s += 'A';
    if (!isProperLower) s += 'a';
    if (!isProperDigit) s += '1';
    if (!isProperSpecial) s += '#';
    while(s.length() < 7) s += 'a';
    cout<<"Case #"<<itr<<": "<<s<<endl;
    itr++;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}
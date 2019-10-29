//https://A/problem/C
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
 
void solve_case() {
    string A;
    cin >> A;
    string even, odd;
 
    for (char c : A)
        if ((c - '0') % 2 == 0)
            even += c;
        else
            odd += c;
 
    reverse(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    string answer;
 
    while (!even.empty() || !odd.empty())
        if (odd.empty() || (!even.empty() && even.back() < odd.back())) {
            answer += even.back();
            even.pop_back();
        } else {
            answer += odd.back();
            odd.pop_back();
        }
 
    cout << answer << '
';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T-- > 0)
        solve_case();
}

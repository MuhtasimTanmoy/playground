//https://A/problem/D

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
 
const int INF = 1e9 + 5;
 
struct salary {
    int L, R;
 
    bool operator<(const salary &other) const {
        return L < other.L;
    }
};
 
int N, H;
long long S;
vector<salary> salaries;
 
bool possible(int median) {
    long long sum = 0;
 
    for (salary &s : salaries)
        sum += s.L;
 
    int count = 0;
 
    for (int i = N - 1; i >= 0 && count < H; i--)
        if (salaries[i].R >= median) {
            sum += max(median - salaries[i].L, 0);
            count++;
        }
 
    return count == H && sum <= S;
}
 
void solve_case() {
    cin >> N >> S;
    H = (N + 1) / 2;
    salaries.resize(N);
 
    for (salary &s : salaries)
        cin >> s.L >> s.R;
 
    sort(salaries.begin(), salaries.end());
    int low = 0, high = INF;
 
    while (low < high) {
        int mid = (low + high + 1) / 2;
 
        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }
 
    cout << low << '
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

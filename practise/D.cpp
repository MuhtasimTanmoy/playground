//https://practise/problem/D
// https://codeforces.com/contest/965/problem/D
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005;
#define ll long long

const int mxn = 1e5 + 9;

ll a[mxn], sum[mxn];
int main()
{
    freopen("input.txt", "r", stdin);

    ll i, j, k, n, m, ans = 1e18, l;
    cin >> n >> l;
    for (i = 1; i < n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (i = l; i < n; i++)
    {
        ans = min(ans, sum[i] - sum[i - l]);
    }
    cout << ans << endl;
    return 0;
}

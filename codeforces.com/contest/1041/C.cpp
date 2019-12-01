//https://codeforces.com/contest/1041//problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;

set<pair<int, int> > q;

int ans[N], n, a[N], m, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        q.insert({a[i], i});
    }
    int cnt = 0;
    while(!q.empty()){
        ++cnt;
        int pos = q.begin()->second;
        ans[pos] = cnt;
        q.erase(q.begin());
        while(true){
            auto it = q.lower_bound({a[pos]+1+k, 0});
            if (it == q.end())
                break;
            pos = it->second;
            q.erase(it);
            ans[pos] = cnt;
        }
    }
    cout << cnt << "
";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}

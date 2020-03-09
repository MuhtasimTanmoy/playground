//https://1295/problem/B
#include<bits/stdc++.h>

using namespace std;

typedef long long li;

int n, x;
string s;

inline bool read() {
	if(!(cin >> n >> x >> s))
		return false;
	return true;
}

inline void solve() {
	int ans = 0;
	bool infAns = false;
	
	int cntZeros = (int)count(s.begin(), s.end(), '0');
	int total = cntZeros - (n - cntZeros);
	
	int bal = 0;
	for(int i = 0; i < n; i++) {
		if(total == 0) {
			if(bal == x)
				infAns = true;
		}
		else if(abs(x - bal) % abs(total) == 0) {
			if((x - bal) / total >= 0)
				ans++;
		}
		
		if(s[i] == '0')
			bal++;
		else
			bal--;
	}
	
	if(infAns) ans = -1;
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		read();
		solve();
	}
	
	return 0;
}

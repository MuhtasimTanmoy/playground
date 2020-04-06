//https://1332/problem/C
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string S; cin >> S;
		int ans = N;
		for (int i = 0; i <= K-1-i; i++) {
			vector<int> cnt(26, 0);
			for (int j = i; j < N; j += K) {
				cnt[S[j] - 'a']++;
			}
			if (i < K-1-i) {
				for (int j = K-1-i; j < N; j += K) {
					cnt[S[j] - 'a']++;
				}
			}
			ans -= *max_element(cnt.begin(), cnt.end());
		}
		cout << ans << '
';
	}
 
	return 0;
}

/* cerberus97 - Hanit Banga */
 #include <bits/stdc++.h>

 
using namespace std;
 
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int N = 1e5 + 10;
 
int main() {
    freopen("input.txt", "r", stdin);

	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

    //
	vector< vector<int> > mval(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		mval[i][i] = a[i];
	}

    //
	for (int len = 2; len <= n; ++len) {
		for (int i = 0, j = len - 1; j < n; ++i, ++j) {
			for (int k = i; k < j; ++k) {
				if (mval[i][k] != -1 and mval[i][k] == mval[k + 1][j]) {
					mval[i][j] = mval[i][k] + 1;
				}
			}
		}
	}

    //
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++){
            cout<<mval[i][j]<<" ";
        }
        cout<<endl;
    }

    // 
	vector<int> dp(n + 1, n);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (mval[i][j] != -1) {
				dp[j + 1] = min(dp[j + 1], dp[i] + 1);
			}
		}
	}
	cout << dp[n] << endl;
}
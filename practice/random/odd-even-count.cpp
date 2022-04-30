#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve() {
	int n, x;
	cin >> n >> x;

	int odd_count = 0;
	int even_count = 0;

	for (int i = 0; i < n; i++) {
		int holder;
		cin >> holder;
		if (holder & 1) odd_count++;
		else even_count++;
	}

	if(odd_count%2==0 && (even_count==0|| x==n)) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
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
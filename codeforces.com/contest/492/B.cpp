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
	int n, len;
	cin >> n >> len;

	vector<double> li;
	double holder;

	for (int i = 0; i < n; i++){
		cin>>holder;
		li.push_back(holder);
	}

	sort( li.begin(), li.end() );

 	double max_dis = 0;
	for (int i = 0; i < li.size()-1; i++) 
		max_dis = max( max_dis, abs(li[i] -li[i+1]));

	max_dis = max_dis/2;
	max_dis = max(max_dis,max(abs(li[0]-0),abs(li[n-1]-len)));
	printf("%.8f\n",max_dis);
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}

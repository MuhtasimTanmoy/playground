//https://1324/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int _count = 0;
int sec = 0;
int _max = 0;

void check(int num){
	if(_max == num) _count++;
	else sec = num;
}

void solve() {
	int x,y,z;
	cin >> x >> y >> z;

	int a, b, c;
	// x -> max(a,b)
	// y -> max(a,c)
	// z -> max(b,c)

	_max = max(max(x,y),z);
	sec = _max;
	_count = 0;
	check(x);
	check(y);
	check(z);

	if (_count >= 2) {
		cout<<"YES"<<endl;
		cout<< _max <<" "<< sec<<" "<<sec<<endl;
	} else
		cout<<"NO"<<endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}

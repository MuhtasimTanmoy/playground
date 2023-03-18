#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;

void solve() {
	int n;
	cin>>n;

	if( n >= 0 ) {
		cout<<n<<endl;
		return;
	}

	n = abs(n);

	if( n <= 10 ) {
		cout<<0<<endl;
		return;
	}

	int one = n % 10;
	int two = ( n / 10 ) % 10;

	if( one > two ) n = n/10;
	else {
		n = n/100;
		n*=10;
		n+=one;
	}

	cout<<-n<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define log(x) cout << #x << " = " << x << endl;

long long power(long long n, long long a) {
	long long res = 1;
	while(a > 0) {
		if ( a & 1 ) res = n * res;
		n = n * n;
		a = a >> 1;
	}
	return res;
}

void execute() {
	int n;
	cin >> n;
	long long result = 4 * 3 * 2 * power(4, n-3) + 4  * 9 * (n-3) * power(4, n-4);
	cout<<result;
	return;
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
#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
	int n;
	cin>>n;

	long long result = 1;
	n--;
	while(n--) {
		result *= 3;
	}
	result*=2;
	cout<<result;
	return 0;
}
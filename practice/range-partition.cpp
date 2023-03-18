#include <bits/stdc++.h>
using namespace std;

// sum % ( X + Y ) will determine if impossible

vector<int> permuation(vector<int> elems, int currentSum, int current, int n, int minX, int minY) {
	if ( current > n ) return {};

	int sum = ( n * ( n + 1 ) ) >> 1;
	if ( minY * currentSum == minX * (sum - currentSum) 
		|| minX * currentSum == minY * (sum - currentSum) ) return elems;

	elems.push_back(current + 1);
	auto alanSet1 = permuation(elems, currentSum + current + 1, current + 1, n, minX, minY);
	if (alanSet1.size()) return alanSet1;

	elems.pop_back();
	return permuation(elems, currentSum, current + 1, n, minX, minY);
}

int counter = 1;

void execute() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> v = {};
	auto alanSet = permuation(v, 0, 0, n, x, y);

	if (alanSet.empty()) cout<< "Case #"<<counter<<": IMPOSSIBLE"<< endl;
	else {
		cout<< "Case #"<<counter<<": POSSIBLE"<< endl;
		cout<< alanSet.size() << endl;
		for(auto elem: alanSet) cout<<elem<<" ";
		cout<<endl;
	}
	counter++;
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
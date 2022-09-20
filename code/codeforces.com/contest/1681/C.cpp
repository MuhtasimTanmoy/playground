//https://codeforces.com/1681/problem/C
#include <bits/stdc++.h>
using namespace std;
 
#define log(x) cout << #x << " = " << x << endl;
void execute() {
	int n;
	cin>>n;
 
	vector<int> a(n);
	vector<int> b(n);
 
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n; i++) cin>>b[i];
 
	int tryCount = 10000;
 
	vector<pair<int,int>> li;

	for(int i = 1; i < n; i++) {
		int key = a[i];
		int keyB = b[i];
		int j = i - 1;
		while(j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			b[j+1] = b[j];
			li.push_back(make_pair(j + 1 + 1, j + 1));
			j--;
		}
		a[j+1] = key;
		b[j+1] = keyB;
	}

	for(int i = 1; i < n; i++) {
		int key = a[i];
		int keyB = b[i];
		int j = i - 1;
		while(j >= 0 && b[j] > keyB) {
			a[j+1] = a[j];
			b[j+1] = b[j];
			li.push_back(make_pair(j + 1 + 1, j + 1));
			j--;
		}
		a[j+1] = key;
		b[j+1] = keyB;
	}

	bool isSorted = true;
	for(int i = 1; i < n; i++) {
		int key = a[i];
		int keyB = b[i];
		int j = i - 1;
		while(j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			b[j+1] = b[j];
			li.push_back(make_pair(j + 1 + 1, j + 1));
			j--;
			isSorted = false;
		}
		a[j+1] = key;
		b[j+1] = keyB;
	}
 
	if (!isSorted) cout << -1 <<endl;
	else {
		cout<<li.size()<<endl;
		for(auto elem: li) cout<<elem.first<< " " << elem.second<<endl;
	}
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
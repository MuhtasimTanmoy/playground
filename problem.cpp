#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;
void execute() {
	cout << "Enter a string: ";
    getline(cin, str1);

    cout << "Enter another string: ";
    cin.get(str, 100, '\n');
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	// freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "Line : " << __LINE__ <<" [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void execute() {}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) {
		execute(); 
	} 
	return 0;
}
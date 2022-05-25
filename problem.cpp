#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;
void execute() {
    int n;
    cin>>n;
    vector<int> li(n);
    for(int i = 0; i < n; i++ )
        cin>>li[i];
    sort(li.begin(), li.end());

    int mid = n >> 1;
    cout<<mid<<endl;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if ( i == mid ) continue;
        sum += li[i];
    }

    if (sum % (n - 1) == 0 && li[mid] == ( sum / (n-1))) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
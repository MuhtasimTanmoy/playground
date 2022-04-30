//https://practise/problem/D
// https://codeforces.com/contest/965/problem/D
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i, a, b) for (int i = (a); (i <= (b)); ++i)
#define x first
#define y second
using namespace std;

///REF PII

typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const int M = 2 * 1000 * 1000;
const int N = 300 * 1000 + 100;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;

template <typename T>
T gcd(T x, T y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}


void solve() {

	int n, step;
	cin >> n >> step;

	int li[n];

	REPI(i, 1, n) 
		cin >> li[i];

	int lo, hi;

	lo = 0;
	hi = step;

	int result = 0;

	while (hi > lo) {

		if (hi >= n + 1) {
			result++;
			lo = 0;
			hi = step;
		} else if (li[hi]) {
			li[hi]--;
			lo = hi;
			hi += step;
		} else 
			hi--;
	}

	cout << result << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--) 
		solve();

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define MAX 100005
// int a[MAX];
// int reach[MAX];

// int main(){
//     int w,l;
//     scanf("%d %d",&w,&l);
//     for(int i=1;i<w;i++) scanf("%d",&a[i]);
//     for(int i=1;i<=l;i++) reach[i]=a[i];

//     int lo=1,hi=l+1;
//     while(hi<=w){
//         while(hi>lo){
//             int now=min(a[hi],reach[lo]);
//             a[hi]-=now;
//             reach[lo]-=now;
//             reach[hi]+=now;
//             if(a[hi]==0) break;
//             lo++;
//         }
//         hi++;
//     }

//     int Ans=0;
//     for(int i=w-l;i<w;i++) Ans+=reach[i];
//     cout<<Ans<<endl;
// }

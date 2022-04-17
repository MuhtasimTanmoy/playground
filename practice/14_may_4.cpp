#include <bits/stdc++.h>
using namespace std;
 
#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()
 
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
 
const int inft = 2*1000000009;
const int MAXN = 1000006;//10^6
 
void solve() {
	int n,X[MAXN];
	scanf("%d",&n);
	fru(i,n)scanf("%d",&X[i]);
	fru(i,n){
		int a=inft,b=0;
		if(i)a=min(a,X[i]-X[i-1]);
		if(i<n-1)a=min(a,X[i+1]-X[i]);
		b=max(X[i]-X[0],X[n-1]-X[i]);
		printf("%d %d\n",a,b);
		
	}
}
 
int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t=1;//scanf("%d",&t);
	fru(i,t) solve();
}
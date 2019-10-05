// https://codeforces.com/contest/455/problem/A
// DP good one
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;
#define MAX 100005
typedef long long int ll;

ll dp[MAX];
ll count1[MAX];
int main(){
	int n,x;
	cin>>n;
	REP(i,n){
		cin>>x;
		count1[x]++;
	}
	dp[0]=0;
	dp[1]=count1[1];
	for(int i=2;i<MAX;i++){
		dp[i]=max(dp[i-1],dp[i-2]+i*count1[i]);
	}
	cout<<dp[MAX-1];
}
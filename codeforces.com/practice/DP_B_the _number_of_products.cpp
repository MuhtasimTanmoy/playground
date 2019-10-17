// https://codeforces.com/problemset/problem/1215/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll li[N];

void solve()
{
	int n;
	cin >> n;

	ll positive_count = 0;
	ll negative_count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
		li[i] > 0 ? positive_count++ : negative_count++;
	}

	bool positive = true;

	for (int i = 0; i < n; i++)
	{
		positive = li[i] > 0 ? true : false;
		for (int j = i; j < n; j++)
		{
			if (i == j)
				continue;

			if (li[j] > 0)
			{
				if (positive)
				{
					positive_count++;
					positive = true;
				}
				else
				{
					negative_count++;
					positive = false;
				}
			}
			else
			{
				if (!positive)
				{
					positive_count++;
					positive = true;
				}
				else
				{
					negative_count++;
					positive = false;
				}
			}
		}
	}
	cout << negative_count << " " << positive_count << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}


// using namespace std;
// int n,S[1000005];
// int main(){
// 	/*scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
// 	int low=a1*(k1-1)+a2*(k2-1);
// 	printf("%d ",max(n-low,0));
// 	if (k1>k2) swap(k1,k2),swap(a1,a2);
// 	int T1=min(n/k1,a1); a1-=k1; n-=T1*k1;
// 	printf("%d",T1+n/k2);*/
// 	scanf("%d",&n);
// 	S[0]=1;
// 	For(i,1,n){
// 		int x;
// 		scanf("%d",&x);
// 		if (x<0) S[i]=S[i-1]^1;
// 		else S[i]=S[i-1];
// 	}
// 	int s0=0,s1=0;
// 	For(i,0,n)
// 		if (S[i]==0) ++s0;
// 		else ++s1;
// 	printf("%lld %lld\n",1ll*s0*s1,1ll*n*(n+1)/2-1ll*s0*s1);
// }
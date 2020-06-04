#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);   cin.tie();

    int n,m;    cin>>n>>m;
    if(n>m) {cout<<"YES";   return 0;}

    int p[1001],q[1001];
    memset(p,0,sizeof p);
	
    for(int i=1;i<=n;i++)
    {
        memset(q,0,sizeof q);
        int val;    cin>>val;   val%=m; q[val]++;
        for(int j=0;j<m;j++)    if(p[j])    {   q[(j+val)%m]++; }
        for(int j=0;j<m;j++)    p[j]+=q[j];
    }
    p[0]?cout<<"YES":cout<<"NO";
}
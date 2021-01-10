#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

// Made mistake.

void printNegFirst(vector<int> li){
	for (int i = 0; i < li.size(); i++){
		if(li[i]<0){
			cout<<li[i]<<" ";
		}
	}
	for (int i = 0; i < li.size(); i++){
		if(li[i]>=0){
			cout<<li[i]<<" ";
		}
	}
}


void printPosFirst(vector<int> li){

	int zeroCount = 0;
	for (int i = 0; i < li.size(); i++){
		if(li[i]==0){
			zeroCount++;
			continue;
		}
		if(li[i]>=0){ cout<<li[i]<<" ";}
	}

	while(zeroCount--){
		cout<<0<<" ";
	}
	
	for (int i = 0; i < li.size(); i++){
		if(li[i]<0){ cout<<li[i]<<" ";}
	}
}

void solve()
{
	int n;
	cin>>n;

	vector<int> li(n);
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin>>li[i];
		sum+=li[i];
	}

	if(sum == 0){
		cout<<"NO"<<endl;
		return;
	}

	cout<<"YES"<<endl;
	int sumPos=0;
	int sumNeg = 0;
	for (int i = 0; i < n; i++){
		if(li[i]>=0){
			sumPos+=li[i];
		}else{
			sumNeg+=li[i];
		}
	}

	sumNeg = abs(sumNeg);
	if(sumNeg>sumPos){
		printNegFirst(li);
	}else{
		printPosFirst(li);
	}

	cout<<endl;

}



int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}

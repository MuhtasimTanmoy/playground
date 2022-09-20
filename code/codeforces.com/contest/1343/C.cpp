#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
// Your task is to choose maximum by size (length) alternating subsequence of the given sequence (i.e. the sign of each next element is the opposite from the sign of the current element, like positive-negative-positive and so on or negative-positive-negative and so on). Among all such subsequences, you have to choose one which has the maximum sum of elements.
const int N = 2e5 + 11;
int _max = INT64_MIN;
int sum = 0;
vector<int> result;


bool checkIfAlternating(vector<int> li)
{
	if(li.size()==0)return false;

	bool lessThan = li[0]<0;

	for (int i=1;i<li.size();i++)
	{
		if(lessThan){
			if(li[i]<0)return false;
			lessThan = false;
		}
		else{
			if(li[i]>0)return false;
			lessThan = true;
		}
	}

	return true;
}

void generateAllSubsequence(vector<int> current, vector<int> li, int index, int total)
{
	if (index > total)
	{
		return;
	}

	if (index == total)
	{
		if(!checkIfAlternating(current))return;

		sum = 0;
		for (auto x : current)
		{
			sum += x;
		}

		if(current.size()>result.size() || (sum>_max && current.size()==result.size())){
			_max = sum;

			result.clear();
			for (auto x : current)
			{
				result.push_back(x);
			}
		}
	}

	current.push_back(li[index]);
	generateAllSubsequence(current, li, index + 1, total);

	current.pop_back();
	generateAllSubsequence(current, li, index + 1, total);
}

void solve()
{
	int n;
	cin >> n;

	int holder;
	vector<int> li;

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		li.push_back(holder);
	}

	vector<int> current;
	generateAllSubsequence(current, li, 0, n);

	for (auto x:result){
		cout<<x<<" "; 
	}
	cout<<endl;
}

vector< vector<int> > segments;
vector<int> temp;

int sgn(int x){
	if(x<0){
		return -1;
	}
	else {
		return 1;
	}
}

void printVec(vector<int> v){
	for (auto x:v){
		cout<<x<<" ";
	}
	cout<<endl;
}

int maxVec(vector<int> v){
	int _max = v[0];
	for (auto x:v){
		_max = max(_max,x);
	}
	return _max;
}

void solveAlternative(){
	int n;
	cin>>n;
	int holder;

	vector<int> li;
	for (int i = 0; i < n; i++){
		cin>>holder;
		li.push_back(holder);
	}

	segments.clear();
	temp.clear();

	for (int i = 0; i < n; i++){
		if(i>0 && sgn(li[i]) != sgn(li[i-1])){
			segments.push_back(temp);
			temp.clear();
		}
		temp.push_back(li[i]);
	}
	segments.push_back(temp);

	long long ans =0;
	for (int i = 0; i < segments.size(); i++){
		// printVec(segments[i]);
		ans+=maxVec(segments[i]);
	}

	cout<<ans<<endl;
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
		solveAlternative();
	}

	return 0;
}

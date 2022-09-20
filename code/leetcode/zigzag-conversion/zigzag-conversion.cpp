class Solution {
public:
  string convert(string s, int numRows) {
        
        vector<vector<int>> list(numRows);
        
        vector<int> index;
        int currentIndex = 0;
        
        // Update index
        // in case 3
        // 0 1 2 1
        auto updateIndex = [&]() {
            for( int i = 0; i < numRows; i++) {
                index.push_back(i);
            }

            for( int i = numRows - 2; i > 0; i--) {
                index.push_back(i);
            }
        };
        updateIndex();
        
        auto getIndex = [&](int i) -> int {
			int returnIndex = i % index.size();
            return index[returnIndex];
        };
       
        for( int i = 0; i< s.size(); i++) {
            char current = s[i];
            list[getIndex(i)].push_back(current);
        }
        
        string st = "";
        for( int i = 0; i < numRows; i++) {
            for (char a: list[i]) {
                st+=a;
            }
        }
        return st;
    }
};


// Second 

#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define pr(i) cout << endl \
				   << "...." << i << "...." << endl;
using namespace std;

void solve()
{
	string s;
	int numOfRows;
	cin>>numOfRows;
	cin>>s;

	vector<vector<char>> rows(numOfRows);
	bool flip=false;
	int index=0;

	numOfRows--;
	for(int i=0;s[i];i++){
		index=i%(numOfRows);
		index=flip?numOfRows-index:index;	
		// cout<<index<<endl;
		if(index==numOfRows-1){
			flip=!flip;
		}

		rows[index].push_back(s[i]);
	}

	for(int i=0;i<rows.size();i++){
		for(int j=0;rows[i][j];j++){
			cout<< rows[i][j] << " ";
		}
		cout<<"\n";
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases=1;

	while (no_of_test_cases--)
	{
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}


// Another

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        vector<string> rows(numRows);
        int cur=0,fac=1;
        string ans;

        for(int i=0;i<s.length();i++){
            rows[cur].push_back(s[i]);
            cur+=fac;
            if(cur==0 || cur==numRows-1) fac*=-1;
        }
        
        for(auto str: rows) ans+= str;
        return ans;
    }
};
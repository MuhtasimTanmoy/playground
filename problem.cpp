#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;

void execute() {
    int num_of_elem, multiplier;
    unordered_set<int> bag;
    cin>> num_of_elem >> multiplier;
    int element;

    // get multiplier elements that it is made of
    auto get_multipilers = [multiplier](int element) -> vector<int> {

        int multipler_power = 0;
        vector<int> list;
        int count = 0;

        if (element == 0) {
            list.emplace_back(1);
        }

        while (element) {

            if (element % multiplier > 1) {
                
            } else if (element % multiplier == 1) {
                list.emplace_back(count);
            }

            count++;
            element = element / multiplier;
        }

        return list;
    };

    while(num_of_elem--) {

        vector<int> multipilers = get_multipilers(element);

        for (auto multiplier :multipilers) {
            cout<<multiplier<<" "; 
        }
        cout<<endl;
        
        for (auto multiplier :multipilers) {
            if (bag.count(multiplier)) {
                cout<<"NO"<<endl;
                return;
            } else {
                bag.insert(multiplier);
            }
        }
    }

    cout<<"YES"<<endl;
}

int main() {

	ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	cin >> no_of_test_cases;
    while (no_of_test_cases--)
	{
		execute(); 
	}
	return 0;
    
}
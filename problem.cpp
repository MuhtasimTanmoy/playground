#include <bits/stdc++.h>
#include<memory>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;

class Entity {
    int x;
    int y;

    Entity() {
        cout<<"Init"<<endl;
    }

    ~Entity() {
        cout<<"Deallocate"<<endl;
    }
}

void execute() {

    // int col, row,
    // cin >> col >> row;
    // vector<vector<int>> matrix(col, vector<int>(row, 0));
    // for(int i = 0; i < col; i++ ) {
    //     for(int j = 0; j < row; j++ ) {
    //         cin>>matrix[col][row];
    //     }
    // }
    
    unique_ptr<Entity> ptr = make_unique<Entity>();
    

}

int main()
{
	ios_base::sync_with_stdio(false);
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
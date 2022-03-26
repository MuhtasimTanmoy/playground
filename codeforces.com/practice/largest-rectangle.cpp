#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;

void execute() {

    int col, row;
    cin>>col>>row;

    vector<vector<int>> matrix(col, vector<int>(row, 0));
    vector<vector<int>> convertedMatrix(col, vector<int>(row, 0));

    // input
    // 7
    // 1 0 1 0 0 0 0
    // 0 0 0 0 0 0 1
    // 1 0 0 0 0 0 0
    // 0 0 0 0 1 0 1

    for(int i = 0; i < col; i++ ) {
        for(int j = 0; j < row; j++ ) {
            cin>>matrix[i][j];
        }
    }
    
    auto process = [&](int i, int j) -> int {
        if ( matrix[i][j] ) {  return 0; }
        if ( i - 1 < 0 ) { return 1; }
        else { return convertedMatrix[i-1][j] + 1; }
    };

    // intermediate conversions
    // 0 1 0 1 1 1 1 
    // 1 2 1 2 2 2 0 
    // 0 3 2 3 3 3 1 
    // 1 4 3 4 0 4 0 

    for(int i = 0; i < col; i++ ) {
        for(int j = 0; j < row; j++ ) {
            convertedMatrix[i][j] = process(i, j);
        }
    }

    vector<vector<int>> left(col, vector<int>(row, 0));
    vector<vector<int>> right(col, vector<int>(row, 0));

    struct ValIndex {
        int index;
        int value;

        ValIndex(i: int, v: int) {
            index = i;
            value = v;
        }
    }
    stack<ValIndex> maintainIncreasing;

    auto processIncreasingLeft = [&](int i, int j) {

        if ( j - 1 ) { return 1; }
        
        while ( maintainIncreasing.top().value < left[i][j] ) {
            maintainIncreasing.pop();
        }

        int distance = 1;
        if ( maintainIncreasing.empty() == false ) {
            distance = j - maintainIncreasing.top().value;
        }

        auto toBeInserted = ValIndex(.index: j, .value: convertedMatrix[i][j]);
        maintainIncreasing.push(toBeInserted);

        return distance;
    };

    for(int i = 0; i < col; i++ ) {
        for(int j = 0; j < row; j++ ) {
            left[i][j] = processIncreasingLeft(i, j);
        }
    }

     auto processIncreasingRight = [&](int i, int j) {

        if ( j - 1 ) { return 1; }
        
        while ( maintainIncreasing.top().value < left[i][j] ) {
            maintainIncreasing.pop();
        }

        int distance = 1;
        if ( maintainIncreasing.empty() == false ) {
            distance = j - maintainIncreasing.top().value;
        }

        auto toBeInserted = ValIndex(.index: j, .value: convertedMatrix[i][j]);
        maintainIncreasing.push(toBeInserted);

        return distance;
    };

    for(int i = 0; i < col; i++ ) {
        for(int j = 0; j < row; j++ ) {
            left[i][j] = processIncreasingRight(i, j);
        }
    }

    for(int i = 0; i < col; i++ ) {
        for(int j = 0; j < row; j++ ) {
            cout<< left[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) {
		execute(); 
	}
	return 0;
}
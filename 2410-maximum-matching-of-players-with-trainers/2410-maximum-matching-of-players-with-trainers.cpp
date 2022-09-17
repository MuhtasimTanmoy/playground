class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int playerIndex = players.size() - 1, trainserIndex = trainers.size() - 1;
        int res = 0;
        while (playerIndex >= 0 && trainserIndex >= 0) 
            if (trainers[trainserIndex] >= players[playerIndex]) {
                trainserIndex--; playerIndex--; res++;
            } else playerIndex--;
        return res;
    }
};
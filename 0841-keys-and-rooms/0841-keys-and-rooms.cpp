class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        
        stack<int> currentlyIn;
        auto zero = rooms[0]; visited[0] = true;
        for (auto room: zero) currentlyIn.push(room);
        
        while (currentlyIn.size()) {
            auto curr = currentlyIn.top(); currentlyIn.pop();
            if (visited[curr]) continue;
            
            visited[curr] = true;
            auto keys = rooms[curr];
            for (auto key: keys) if (!visited[key]) currentlyIn.push(key);
        }
        
        for (auto isVisited: visited) if (!isVisited) return false;
        return true;
    }
};
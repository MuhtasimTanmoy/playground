// class FoodRatings {
//     unordered_map<string, vector<string>> c_to_f;
//     unordered_map<string, int> f_to_r;
// public:
//     FoodRatings(vector<string>& foods, 
//                 vector<string>& cuisines, 
//                 vector<int>& ratings) {
//         for (int i = 0; i < foods.size(); i++) 
//             c_to_f[cuisines[i]].push_back(foods[i]),
//             f_to_r[foods[i]] = ratings[i];
//     }
    
//     void changeRating(string food, int newRating) {
//         f_to_r[food] = newRating;
//     }
    
//     string highestRated(string cuisine) {
//         int most = 0;
//         string res = "z";
//         for (auto food: c_to_f[cuisine]) 
//             if (f_to_r[food] >= most) {
//                 most = f_to_r[food];
//                 if (f_to_r[food] > most || food < res) res = food;
//             }
//         return res;
//     }
// };

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_ratings;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    
    FoodRatings(vector<string>& foods, 
                vector<string>& cuisines, 
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            cuisine_ratings[cuisines[i]].insert({ -ratings[i], foods[i] });
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    void changeRating(string food, int newRating) {
        auto &cuisine = food_cuisine.find(food)->second;
        cuisine_ratings[cuisine].erase({ -food_rating[food], food });
        cuisine_ratings[cuisine].insert({ -newRating, food });
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings[cuisine])->second;
    }
};
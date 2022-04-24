class UndergroundSystem {
public:
     //hash-map to store the checkin details
	//map<startstation,time>
    map<int,pair<string,int>> in;

	//hashmap to store the total sum and count of travel between two stations
	//map<<endstation,startstation><totaltime(sum),count>>
    map<pair<string,string>,pair<int,int>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
	//update the checkin
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
	//update the total time(sum) and count of travel
        avg[{stationName,
             in[id].first}]={avg[{stationName,
                                  in[id].first}].first + t- in[id].second,
                             avg[{stationName,
                                  in[id].first}].second + 1};
    }
    
    double getAverageTime(string startStation, string endStation) {
	//return the average
        return double(double(avg[{endStation,startStation}].first)/double(avg[{endStation,startStation}].second));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
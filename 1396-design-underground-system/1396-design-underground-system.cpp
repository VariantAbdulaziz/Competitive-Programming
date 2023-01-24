class UndergroundSystem {
    map<int, pair<int, string>> check_in;
    map<pair<string, string>, pair<double, int>> journey_times;
    
    double sum(vector<int>& journeys){
        double result = 0.0;
        for(auto journey: journeys) result += journey;
        return result;
    }
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in[id] = make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [start, startStation] = check_in[id];
        int journey = t - start;
        auto& stat_loc = journey_times[make_pair(startStation, stationName)];
        
        stat_loc.first += journey;
        stat_loc.second++;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& stat_loc = journey_times[make_pair(startStation, endStation)];
        
        return stat_loc.first / stat_loc.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
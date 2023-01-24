class UndergroundSystem {
    map<int, pair<int, string>> check_in;
    map<pair<string, string>, vector<int>> journey_times;
    
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
        journey_times[make_pair(startStation, stationName)].push_back(journey);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return sum(journey_times[make_pair(startStation, endStation)]) / journey_times[make_pair(startStation, endStation)].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
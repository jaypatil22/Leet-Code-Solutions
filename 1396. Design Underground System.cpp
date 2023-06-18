class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkin = {};
    unordered_map<string,pair<int,int>> avg = {};
    UndergroundSystem() {
        checkin = unordered_map<int,pair<string,int>>();
        avg = unordered_map<string,pair<int,int>>();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = checkin[id].second;
        string stst = checkin[id].first;
        string p =stst+"_" +stationName;
        avg[p].first += (t-time);
        avg[p].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string p = startStation + "_" + endStation;
        double res = (double)avg[p].first/avg[p].second;
        return res;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
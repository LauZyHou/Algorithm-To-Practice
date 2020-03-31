class UndergroundSystem {
private:
    map<int,string> id_staIn;
    map<int,int> id_timeIn;
    map<string,double> stasta_avgCost;
    map<string,int> stasta_personNum;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        id_staIn[id] = stationName;
        id_timeIn[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string& from = id_staIn[id];
        string from_to = from + "-" + stationName;
        stasta_personNum[from_to]++;
        stasta_avgCost[from_to] = (t-id_timeIn[id] + stasta_avgCost[from_to]*(stasta_personNum[from_to]-1))/stasta_personNum[from_to];
        // 不需清理id_staIn和id_timeId
    }
    
    double getAverageTime(string startStation, string endStation) {
        return stasta_avgCost[startStation + "-" + endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
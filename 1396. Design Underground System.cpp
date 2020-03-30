class UndergroundSystem {
private:
	//             id  pair station,t
	unordered_map<int, pair<string,int> > under;
	//            start                  end         sum count
	unordered_map<string, unordered_map<string, pair<int,int> > > m;
	
public:
	UndergroundSystem() {

	}
	
	void checkIn(int id, string stationName, int t) {
		under[id] = make_pair( stationName,t );
	}
	
	void checkOut(int id, string stationName, int t) {
		string startStation = under[id].first;
		int startTime = under[id].second;
		
		(m[startStation])[stationName].first += (t - startTime);
		( (m[startStation])[stationName].second )++;
	}
	
	double getAverageTime(string startStation, string endStation) {
		auto [sum,count] = (m[startStation])[endStation];
		return ((double) sum) / ((double) count);
	}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
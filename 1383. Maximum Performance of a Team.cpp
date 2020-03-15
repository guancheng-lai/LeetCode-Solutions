class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		constexpr int MOD = 1e9 + 7;
		
		vector< pair<long long,long long> > engineers;
		for (int i = 0; i < n; ++i) engineers.push_back( {efficiency[i],speed[i]} );
		sort(engineers.rbegin(), engineers.rend());
		
		priority_queue<long long, vector<long long>, std::greater<long long>> pq;
		long long best(0);
		long long speedSum(0);
		
		for (auto [e,s] : engineers) {
			pq.push(s);
			speedSum += s % MOD;
			
			if (pq.size() > k) {
				speedSum -= pq.top(); 
				pq.pop();
			}

			best = std::max( best,speedSum*e );
			// cout << best << "  " << speedSum << endl;
		}
		
		return int(best % MOD);
	}
};
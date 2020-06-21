class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		unordered_map<int,int> mp;
		for (int i : arr) mp[i]++;
	
		
		//              pair<cnt,num>
		priority_queue< pair<int,int>, vector< pair<int,int> >, std::greater< pair<int,int> > > pq;
		for (auto &[k,v] : mp) pq.push({v,k});
		
		while (k > 0) {
			auto[cnt,num] = pq.top(); pq.pop();    
			
			if (cnt == k) break;
			if (cnt < k) {
				k -= cnt;    
			}
			else {
				cnt -= k;
				pq.push( {cnt,num} );
				break;
			}
		}
		
	   
		return pq.size();
	}
};
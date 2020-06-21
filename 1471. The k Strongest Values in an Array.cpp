class Solution {
public:
	vector<int> getStrongest(vector<int>& A, int k) {
		int N = A.size();
		if (k == N) return A;
		
		sort(A.begin(), A.end());
		int median = A[ (N-1) / 2];
		
		priority_queue< pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>> > pq;
		
		for (int i = 0; i < N; ++i) {
			int diff = abs(A[i] - median);
			if (pq.size() < k) {
				pq.push({diff,A[i]});
				continue;
			}
			
			if (diff == pq.top().first && A[i] > pq.top().second)  {
				pq.pop();
				pq.push( {diff,A[i]} );
			}
			
			if (diff > pq.top().first) {
				pq.pop();
				pq.push( {diff,A[i]} );
			}
		}
		
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		
		return res;
	}
};
class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<int> result;
		unordered_set<int> dontcheck;
		for (int c = 0; c < mat[0].size(); ++c) {
			for (int r = 0; r < mat.size(); ++r) {
				if (dontcheck.count(r) != 0) continue;
				
				if (mat[r][c] == 0) {
					dontcheck.insert(r);    
					result.push_back(r);
					if (result.size() == k) return result;
				}
			}
		}
		if (result.size() < k) {
			for (int i = 0; i < mat.size(); i++) {
				if (dontcheck.count(i) != 0) continue;
				
				result.push_back(i);
				if (result.size() == k) return result;
			}
		}
		return result;
		
//         auto myComp = [](pair<int,int> p1, pair<int,int> p2) {
//             if (p1.second == p2.second) {
//                 return p1.first <= p2.first;
//             }
//             return p1.second < p2.second ;
//         };
//         priority_queue< pair<int,int>, vector< pair<int,int> >, decltype(myComp)> pq(myComp);
//         for (int r = 0; r < mat.size(); ++r) {
//             int numSoldier(0);
//             for (int c = 0; c < mat[0].size(); ++c) {
//                 if (mat[r][c] == 1) {
//                     numSoldier++;
//                 }
//                 else {
//                     break;
//                 }
//             }

//             if (pq.size() < k) {
//                 pq.push( {r,numSoldier} );
//             }
//             else if (pq.size() == k && pq.top().second > numSoldier) {
//                 pq.pop();
//                 pq.push( {r,numSoldier} );
//             }
//             else {

//             }
//         }

//         vector<int> result;
//         while (!pq.empty()) {
//             result.push_back(pq.top().first);
//             pq.pop();
//         }
//         std::reverse(result.begin(), result.end());
//         return result;
	}
};
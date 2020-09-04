class Solution {
public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& v, vector<vector<int>>& f, int ID, int level) {
		int N = v.size();
		vector<int> visited(N, 0); visited[ID] = 1;
		queue<int> q; q.push(ID);
		map<string, int> m;
		
		while (!q.empty() && level--) {
			for (int i = q.size(); i != 0; i--, q.pop()) {
				for (int fid : f[q.front()]) {
					if (visited[fid] == 0) {
						visited[fid] = 1;
						q.push(fid);
					}
				}
			}
		}
		
		while (!q.empty()) {
			int fid = q.front(); q.pop();
		
			for (auto& video : v[fid]) {
				m[video]++;
			}
		}
		
		vector< pair<int,string> > pairs;
		for (auto&& [video,cnt] : m) pairs.push_back( {cnt,video} );        
		sort(pairs.begin(), pairs.end());
		
		vector<string> res(pairs.size());
		for (int i = 0; i < pairs.size(); ++i) {
			res[i] = pairs[i].second;
		}
		
		return res;
	}
};
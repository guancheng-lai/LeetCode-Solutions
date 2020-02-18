class UF {
private:
	// vector<int> id;
	unordered_map<int, int> id;
	int count;
	
public:
	UF(int len) : count(len) {
		// id.resize(len);
		// for (int i = 0; i < len; ++i) id[i] = i;
	}
	
	int find(int p) {
		if (id.count(p) == 0) {
			id[p] = p;
			return p;   
		}
		
		while (id[p] != p) p = id[p];
		int rp = p;
		
		return p;
	}
	
	bool isConnected(int p, int q) {
		return p == q || find(p) == find(q);
	}
	
	void unite(int p, int q) {
		int rp = find(p), rq = find(q);
		if (rp == rq) return;
		
		id[rq] = rp;
		count--;
	}
	
	int getCount() const {
		return this->count;
	}
};

class Solution {
private:
	int island = 0;
	unordered_map<int, int> hm;
	
	int getRoot(int p) {
		if (hm.count(p) == 0) hm[p] = p, island++;
		if (p != hm[p]) hm[p] = getRoot(hm[p]);
		return hm[p];
	}
	
	void unite(int p, int q) {
		int rp = getRoot(p);
		int rq = getRoot(q);
		if (rp != rq) {
			hm[rp] = rq;
			--island;   
		}
	}
	
public:
	int removeStones(vector<vector<int>>& stones) {
		for (auto &v : stones) {
			unite(v[0], ~v[1]);
			// cout << v[0] << " " << ~v[1] << endl;
		}
		
		return stones.size() - island;
			
		// UF uf(20000);
		// for (auto &v : stones) uf.unite(v[0], v[1] + 10000);
		// unordered_set<int> s;
		// for (auto &v : stones) s.insert( uf.find(v[0]) );
		// return stones.size() - s.size();
	}
};
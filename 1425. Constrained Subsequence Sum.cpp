class UF {
public:
	int count, len;
    vector<int> info, sz;
    
public:
    UF(int L) : count(0), len(L), info(len, -1), sz(len, 0) {}
    
	UF(int L, int setAll) : len(L), count(L), sz(len, 1) {
        iota(info.begin(), info.end(), 0);
	}
    
    UF(const UF& uf) : len(uf.len), count(uf.count), info(uf.info), sz(uf.sz) {}

	int numberOfUnion() const {
		return count;
	}

	int getSizeAt(int i) const {
		return sz[root(i)];
	}

	void setSizeAt(int i, int newSize) {
		sz[root(i)] = newSize;
	}

	int root(int p) const {
		if (p >= len || p < 0) return -1;

		return info[p] != p ? root(info[p]) : info[p];
	}

	bool connected(int p, int q) const {
		int rp = root(p), rq = root(q);
		return rp != -1 && rq != -1 && rp == rq;
	}

    void uniteOne(int i) {
		info[i] = i;
		setSizeAt(i, 1);
		count++;
	}
    
	void unite(int p, int q) {
		int rp = root(p);
		int rq = root(q);
		if (rp == rq && rp != -1) {
            uniteOne(p);
            uniteOne(q);
            rp = root(p);
            rq = root(q);
        }

        if (rp == rq && rp == -1) {
			info[q] = p;
			info[p] = p;
			sz[p] = 2;
            count++;
		}
		else if (rp == -1) {
			info[p] = rq;
			sz[rq]++;
		}
		else if (rq == -1) {
			info[q] = rp;
			sz[rp]++;
		}
		else {
			int pSize = getSizeAt(rp);
			int qSize = getSizeAt(rq);
			if (pSize > qSize) {
				setSizeAt(rq, 0);
				info[rq] = rp;
				setSizeAt(rp, pSize + qSize);
			} else {
				setSizeAt(rp, 0);
				info[rp] = rq;
				setSizeAt(rq, pSize + qSize);
			}
			
			count--;
		}
	}
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {
        UF uf(n+1); //alice type 1 + 3
        vector< vector<int> > v3, v2, v1;
        // sort(edges.rbegin(), edges.rend());
        for (auto &&edge : edges) {
            if (edge[0] == 1) v1.push_back(edge);
            if (edge[0] == 2) v2.push_back(edge);
            if (edge[0] == 3) v3.push_back(edge);
        }
        
        int res = 0, i;
        for (i = 0; i < v3.size(); ++i) {
            int a = v3[i][1], b = v3[i][2];
            if (uf.connected(a, b)) {
                res++;
            } else {
                uf.unite(a, b);   
            }
        }
        
        UF uf2(uf); // bob type 2 + 3
        for (i = 0; i < v2.size(); ++i) {
            int a = v2[i][1], b = v2[i][2];
            if (uf2.connected(a, b)) {
                res++;
            } else {
                uf2.unite(a, b);   
            }
        }
        
        for (i = 0; i < v1.size(); ++i) {
            int a = v1[i][1], b = v1[i][2];
            if (uf.connected(a, b)) {
                res++;
            } else {
                uf.unite(a, b);   
            }
        }
        
        if (uf.getSizeAt(1) != n || uf2.getSizeAt(1) != n) return -1;
        
        return res;
    }
};
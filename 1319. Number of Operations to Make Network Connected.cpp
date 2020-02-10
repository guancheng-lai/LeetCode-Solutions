struct Edge
{
	int start;
	int end;
	Edge() {}
	Edge(int s, int e) : start(s), end(e) {}
	pair<int, int> getVertex() {
		return make_pair(start, end);
	}
};

class UF
{
private:
	int count;
	vector<int> info;
	vector<int> sz;

public:
	UF(int len)
	{
		count = 0;
		info = vector<int>(len);
		sz = vector<int>(len);

		for (int i = 0; i < len; ++i){
			info[i] = -1;
			sz[i] = 0;
		}
	}

	int number() const
	{
		return count;
	}

	int getSize(int i) const
	{
		return sz[root(i)];
	}

	void setSize(int i, int newSize)
	{
		sz[root(i)] = newSize;
	}

	int root(int p) const
	{
		if (p >= info.size() || p < 0) return -1;

		return info[p] != p ? root(info[p]) : info[p];
	}

	bool connected(int p, int q) const 
	{
		int rp = root(p), rq = root(q);
		return rp != -1 && rq != -1 && rp == rq;
	}

	void Union(int p, int q)
	{
		int rp = root(p);
		int rq = root(q);
		if (rp == rq && rp != -1) return;

        if (rp == rq && rp == -1)
		{
			info[q] = p;
			info[p] = p;
			sz[p] = 2;
            count++;
		}
		else if (rp == -1) 
		{
			info[p] = rq;
			sz[rq]++;
		}
		else if (rq == -1)
		{
			info[q] = rp;
			sz[rp]++;
		}
		else 
		{
			int pSize = getSize(rp);
			int qSize = getSize(rq);
			if (pSize > qSize) 
			{
				setSize(rq, 0);
				info[rq] = rp;
				setSize(rp, pSize + qSize);
			}
			else 
			{
				setSize(rp, 0);
				info[rp] = rq;
				setSize(rq, pSize + qSize);
			}
			
			count--;
		}
	}

	void UnionSingleNode(int i)
	{
		info[i] = i;
		setSize(i, 1);
		count++;
	}
    
    void printUFInfo() {
        cout << endl;
        for (auto i : info) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    void printUFSize() {
        cout << endl;
        for (auto i : sz) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    vector<int> getUFInfo() {
        return info;
    }
    
    vector<int> getUFSize() {
        return sz;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UF uf(n);
        vector<vector<int>> spare;
        unordered_set<int> unconnected;
        for (int i = 0; i < n; ++i) {
            unconnected.insert(i);
        }
        
        for (auto &&edge : connections) {
            if (uf.connected(edge[0], edge[1])) {
                spare.push_back(edge);
            }
            else {
                uf.Union(edge[0], edge[1]);
                unconnected.erase(edge[0]);
                unconnected.erase(edge[1]);
            }
        }
        
        int need = unconnected.size() + uf.number() - 1;
        
        if (need == 0) return 0;
        if (need > spare.size()) return -1;
        
        return need;
    }
};
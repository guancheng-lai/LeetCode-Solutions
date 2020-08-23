class UF
{
public:
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

	int numberOfUnion() const
	{
		return count;
	}

	int getSizeAt(int i) const
	{
		return sz[root(i)];
	}

	void setSizeAt(int i, int newSize)
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

	void unite(int p, int q)
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
			int pSize = getSizeAt(rp);
			int qSize = getSizeAt(rq);
			if (pSize > qSize) 
			{
				setSizeAt(rq, 0);
				info[rq] = rp;
				setSizeAt(rp, pSize + qSize);
			}
			else 
			{
				setSizeAt(rp, 0);
				info[rp] = rq;
				setSizeAt(rq, pSize + qSize);
			}
			
			count--;
		}
	}

	void uniteOne(int i)
	{
		info[i] = i;
		setSizeAt(i, 1);
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
    
    vector<int> getUFInfo() const 
	{
        return info;
    }
    
    vector<int> getUFSize() const 
	{
        return sz;
    }
};


class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int N = arr.size();
        UF uf(N + 1);
        int res = -1;
        set<int> sizeOfM;
        for (int i = 0; i < N; ++i) {
            int a = arr[i];
            uf.uniteOne(a);
            if (a != N && uf.root(a+1) != -1) uf.unite(a, a+1);
            if (a != 1 && uf.root(a-1) != -1) uf.unite(a, a-1);

            for (int g : sizeOfM) {
				if (uf.getSizeAt(g) != m) {
					sizeOfM.erase(g);
				}
            }
            
            if (uf.getSizeAt(a) == m) sizeOfM.insert(uf.root(a));
            if (sizeOfM.size() != 0) res = i+1;
        }
        
        return res;
    }
};
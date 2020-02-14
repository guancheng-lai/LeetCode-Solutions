class UF {
private:  
	vector<int> info;
	int count;
	
public:
	UF (int size) {
		this->info.resize(size);
		this->count = size;
		for (int i = 0; i < size; ++i) this->info[i] = i;
	}
	
	int root(int p) {
		while (info[p] != p) p = info[p];
		return p;
	}
	
	void unite(int p, int q) {
		int rp = root(p);
		int rq = root(q);
		if (rp == rq) return;
		
		info[rq] = rp;
		count--;
	}
	
	bool isConnected(int p, int q) {
		return this->root(p) == this->root(q);
	}
	
	int getCount() const {
		return this->count;
	}
};

class Solution {
public:
	// Union Find
	int minSwapsCouples(vector<int>& row) {
		size_t len = row.size();
		int numCouples = len/2;
		int count = numCouples;
		UF uf(len);
		
		for (int i = 0; i < len; i += 2) {
			int p = row[i]/2;
			int q = row[i+1]/2;
			if (!uf.isConnected( p,q )) {
				uf.unite(p,q);
				count--;
			}
		}
		
		return numCouples - count;
	}
	
	// Hash Map
	int minSwapsCouples(vector<int>& row) {
		size_t len = row.size();
		unordered_map<int, int> hashMap;
		for (int i = 0; i < len; ++i) hashMap[ row[i] ] = i;
		
		int result(0);
		// cout << "ROW: "; for (auto i : row) cout << i << " ";
		// cout << endl;
		// cout << "MAP: "; for (auto i : row) cout << hashMap[i] << " ";
		// cout << endl << "-----------------------" << endl;
		for (int i = 0; i < len-1; i += 2) {
			int curr = row[i];
			if ( curr % 2 == 0 && curr + 1 == row[i+1] ) continue;
			if ( curr % 2 != 0 && curr - 1 == row[i+1] ) continue;
			
			if ( curr % 2 == 0 ) {
				hashMap[ row[i+1] ] = hashMap[curr+1];
				swap( row[i+1], row[ hashMap[ curr+1 ] ] );
				hashMap[ curr+1 ] = i+1;
			}
			else {
				hashMap[ row[i+1] ] = hashMap[curr-1];
				swap( row[i+1], row[ hashMap[ curr-1 ] ] );             
				hashMap[ curr-1 ] = i+1;
			}
				
			// cout << "ROW: "; for (auto i : row) cout << i << " ";
			// cout << endl;
			// cout << "MAP: "; for (auto i : row) cout << hashMap[i] << " ";
			// cout << endl << "-----------------------" << endl;
			
			result++;
		}
			
		return result;      
	}
};
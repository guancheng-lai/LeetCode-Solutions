class UF {
private:
    vector<int> info;
    int count;

public:
    UF (int size) : count(size) {
        info.resize(size);
        for (int i = 0; i < info.size(); ++i) { info[i] = i; }
    }
    
    int root (int p) {
        while (info[p] != p) { p = info[p]; }
        return p;
    }
    
    void unite (int p, int q) {
        int rp = root(p);
        int rq = root(q);
        if (rp == rq) return;
        
        info[rq] = rp;
        count--;
    }
    
    int getCount() const {
        return this->count;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), n3 = n * 3;
        
        vector< vector<int> > realGrid(n3, vector<int>(n3, 0));
        int countOne(0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    realGrid[i*3][j*3] = 1;
                    realGrid[i*3 + 1][j*3 + 1] = 1;
                    realGrid[i*3 + 2][j*3 + 2] = 1;
                    countOne++;
                }
                else if (grid[i][j] == '/') {
                    realGrid[i*3][j*3 + 2] = 1;
                    realGrid[i*3 + 1][j*3 + 1] = 1;
                    realGrid[i*3 + 2][j*3] = 1;
                    countOne++;
                }
            }
        }
        
        UF uf(n3 * n3);
        for (int r = 0; r < n3; ++r) {
            for (int c = 0; c < n3; ++c) {
                if (realGrid[r][c] == 1) continue;
                
                int currId = r*n3 + c;
                if (c < n3 - 1 && realGrid[r][c+1] == 0) {
                    uf.unite(currId, currId + 1);
                }

                if (r < n3 - 1 && realGrid[r+1][c] == 0) {
                    uf.unite(currId, currId + n3);
                }
            }
        }

        return uf.getCount() - countOne * 3;
    }
};
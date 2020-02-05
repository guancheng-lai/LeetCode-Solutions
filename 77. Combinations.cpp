class Solution {
private:
	int n;
	vector< vector<int> > result;
	
	void dfs(vector<int> &inprogress, int k) {
		if (k == 0) {
			result.push_back(inprogress);
			return;
		}
		
		for (int i = inprogress.back() + 1; i <= n; ++i) {
			inprogress.push_back(i);     
			dfs(inprogress, k - 1);
			inprogress.pop_back();
		}         
	}
	
public:
	vector<vector<int>> combine(int n, int k) {
		if (n <= 0 || k <= 0) return vector<vector<int>>();
		this->n = n;
		
		vector<int> tmp;

		for (int i = 1; i <= n - k + 1; ++i) { 
			tmp.push_back(i);
			dfs(tmp, k - 1); 
			tmp.pop_back();
		}
		return result;
	}
};
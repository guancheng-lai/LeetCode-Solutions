class Solution {
private:
	int k;
	vector< vector<int> > result;
	
	void dfs(vector<int> &inprogress, int target) {
		if (target < 0) return;
		if (target == 0) {
			if (inprogress.size() == k) {
				result.push_back(inprogress);
			}
			
			return;
		}
		
		for (int i = inprogress.back() + 1; i <= 9; ++i) {
			inprogress.push_back(i);
			dfs(inprogress, target - i);
			inprogress.pop_back();
		}
	}
	
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k <= 0 || n <= 0) return vector<vector<int>>();
		this->k = k;
		
		vector<int> inprogress;
		for (int i = 1; i <= 9; ++i) {
			inprogress.push_back(i);
			dfs(inprogress, n - i);
			inprogress.pop_back();
		}
		
		return result;
	}
};
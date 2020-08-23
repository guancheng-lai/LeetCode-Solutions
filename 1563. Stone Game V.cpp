class Solution {
public:
	vector< vector<int> > dp;
	
	int dfs(vector<int>& S, int left, int right, int totalPoints) {
		if (left == right) return 0;
		if (left+1 == right) return std::min(S[left], S[right]);
		
		if (dp[left][right] != -1) return dp[left][right];
		
		int leftPoints = 0, rightPoints = totalPoints, maxPoints = 0;
		for (int pivot = left; pivot < right; ++pivot) {
			leftPoints += S[pivot], rightPoints -= S[pivot];
			int currPoints;
			if (leftPoints == rightPoints) {
				int leftRes = dfs(S, left, pivot, leftPoints);    
				int rightRes = dfs(S, pivot+1, right, rightPoints);
				currPoints = std::max(leftRes, rightRes) + leftPoints;
			}
			else if (leftPoints < rightPoints) {
				currPoints = dfs(S, left, pivot, leftPoints) + leftPoints;
			} else {
				currPoints = dfs(S, pivot+1, right, rightPoints) + rightPoints;
			}
			
			maxPoints = std::max(maxPoints, currPoints);
		}
		
		dp[left][right] = maxPoints;
		return maxPoints;
	}
	
	int stoneGameV(vector<int>& S) {
		dp = vector< vector<int> >(S.size(), vector<int>(S.size(), -1));
		return dfs(S, 0, S.size()-1, std::accumulate(S.begin(), S.end(), 0.0));
	}
};
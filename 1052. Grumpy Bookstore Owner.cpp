class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int N = customers.size();
		int res = 0;
		for (int i = 0; i < N; ++i) {
			res += (grumpy[i] == 0 ? customers[i] : 0);
		}
		
		for (int x = 0; x < X; ++x) {
			res += grumpy[x] == 1 ? customers[x] : 0;
		}
	
		int curr = res;
		for (int i = X; i < N; ++i) {
			if (grumpy[i] == 1) {
				curr += customers[i];
			}
			if (grumpy[i-X] == 1) {
				curr -= customers[i-X];
			}
			res = max(res, curr);
		}
		return res;
	}
};
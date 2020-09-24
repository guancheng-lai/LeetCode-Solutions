class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN, tmp = 1;
		for (int i = 0; i < nums.size(); ++i) {
			tmp *= nums[i];
			if (tmp > res) res = tmp;
			if (tmp == 0) tmp = 1;
		}
		tmp = 1;
		for (int i = nums.size()-1; i >= 0; --i) {
			tmp *= nums[i];
			if (tmp > res) res = tmp;
			if (tmp == 0) tmp = 1;
		}
		
		return res;
	} 
};
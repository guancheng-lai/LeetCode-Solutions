class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k <= 1) return 0;
		
		int result = 0, product = 1;
		for (int start = 0, end = 0; end < nums.size(); ++end) {
			product *= nums[end];
			while (product >= k && start <= end) {
				product /= nums[start];
				++start;
			}
		
			result += (end - start + 1);
		}
		
		return result;
	}
};
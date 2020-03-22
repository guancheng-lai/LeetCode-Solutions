class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		size_t len = nums.size();
		vector<int> target;
		for (int i = 0; i < len; ++i) {
			target.insert(target.begin()+index[i], nums[i]);
		}
		
		return target;
	}
};
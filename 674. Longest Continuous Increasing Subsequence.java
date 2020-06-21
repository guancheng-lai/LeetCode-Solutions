class Solution {
	public int findLengthOfLCIS(int[] nums) {
		int N = nums.length;
		if (N <= 1) return N;
		
		int start = 0;
		int maxLength = 0;
		for (int i = 0; i < N-1; ++i) {
			if (nums[i] >= nums[i+1]) {
				maxLength = Math.max(maxLength, i-start+1);
				start = i+1;
			}
			else {
				maxLength = Math.max(maxLength, i-start+2);
			}
		}
		
		return maxLength;
	}
}
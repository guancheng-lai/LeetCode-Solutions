class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		int N = arr.size();
		sort(arr.begin(), arr.end());
		
		int i = 0;
		while (i < N && target > arr[i] * (N-i)) {
			target -= arr[i++];
		}
		
		if (i == N) return arr[N-1];
		int res = target / (N-i);
		if (target - res*(N-i) > (res+1)*(N-i) - target) {
			res++;
		}
		
		return res;
	}
};
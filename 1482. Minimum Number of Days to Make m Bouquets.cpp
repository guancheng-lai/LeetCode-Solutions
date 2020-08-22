class Solution {
public:    
	int countFlowers(vector<int>& bloomDay, int k, int today) {
		int numOfBouquets = 0, contiguous = 0;
		for (int i : bloomDay) {
			if (i > today) {
				contiguous = 0;    
			} else {
				contiguous++;
				if (contiguous >= k) {
					contiguous = 0;
					numOfBouquets++;
				}    
			}
		}
		return numOfBouquets;
	}
	
	int minDays(vector<int>& bloomDay, int m, int k) {
		int N = bloomDay.size();
		if (m * k > N) return -1;
		int left = 0, right = *std::max_element(bloomDay.begin(), bloomDay.end());
		int mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (countFlowers(bloomDay, k, mid) < m) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		
		return left;
	}
};










using ll = long long;
class Solution {
public:
	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		int res = 0, N1 = nums1.size(), N2 = nums2.size();
		unordered_map<ll, int> p1, p2;
		for (int i = 0; i < N1; ++i) {
			for (int j = i+1; j < N1; ++j) {
				p1[ll(nums1[i]) * ll(nums1[j])]++;
			}
		}
		
		for (int i = 0; i < N2; ++i) {
			for (int j = i+1; j < N2; ++j) {
				p2[ll(nums2[i]) * ll(nums2[j])]++;
			}
		}
		
		for (int i = std::max(N1, N2) - 1; i >= 0; --i) {
			if (i < N1) {
				res += p2[ll(nums1[i]) * ll(nums1[i])];
			}   
			
			if (i < N2) {
				res += p1[ll(nums2[i]) * ll(nums2[i])];
			}
		}
		
		return res;
	}
};
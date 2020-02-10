class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() <= 1) return false;
		
		for (int i = 1, end = s.size(); i <= end/2; ++i) {
			if (end % i != 0) continue;
			
			bool found = true;
			for (int j = i; j < end && found; ++j) {
				if (s.at( j % i ) != s.at(j)) {
					found = false;
				}
			}
			
			if (found) return true;
		}
		
		return false;
	}
};
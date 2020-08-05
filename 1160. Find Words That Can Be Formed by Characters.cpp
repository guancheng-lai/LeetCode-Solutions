class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> charMap(26, 0);
		for (char c : chars) charMap[c - 'a']++;
		
		int res = 0;
		
		vector<int> wordMap(26, 0);
		for (string word : words) {
			for (char c : word) {
				wordMap[c - 'a']++;
			}
			
			bool canForm = true;
			for (int i = 0; i < 26 && canForm; ++i) {
				if (wordMap[i] > charMap[i]) {
					canForm = false;
				}
			}
			
			if (canForm) {
				res += word.size();
			}
			
			wordMap = vector<int>(26, 0);
		}
		
		return res;
	}
};
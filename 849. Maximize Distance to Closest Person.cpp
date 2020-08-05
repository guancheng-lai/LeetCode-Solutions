class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		vector<int> occupied;
		for (int i = 0; i < seats.size(); ++i) {
			if (seats[i] == 1) {
				occupied.push_back(i);
			}
		}
		
		int first = occupied[0] - 0;
		int last = seats.size()-1 - occupied.back();
		if (occupied.size() == 1) {
			return std::max(first, last);
		}
		
		int curr = first;
		for (int i = 1; i < occupied.size(); ++i) {
			int gap = (occupied[i] - occupied[i-1]) / 2;
			if (gap > curr) {
				curr = gap;
			}
		}
		
		return std::max(curr, last);
	}
};
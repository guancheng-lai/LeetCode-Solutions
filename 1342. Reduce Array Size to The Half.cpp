class Solution {
public:
	int minSetSize(vector<int>& arr) {
	map<int, int> m;

	for (auto &i : arr) {    m[i]++; }


	priority_queue<int> pq;
	for (auto &it : m) {
		pq.push(it.second);
	}

	int count(0);
	int rest = arr.size();
	while (!pq.empty() && rest > arr.size() / 2) {
		count++;
		rest -= pq.top();
		pq.pop();
	}

	return count;
	}
};
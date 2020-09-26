class Solution {
public:
	string reverseParentheses(string s) {
		int N = s.size();
		if (N < 1) return "";
		
		vector< pair<int,int> > q;
		stack<int> stk;
		for (int i = 0; i < N; ++i) {
			if (s[i] == '(') {
				stk.push(i);
			} else if (s[i] == ')') {
				int left = stk.top(); stk.pop();
				q.emplace_back( make_pair(left,i) );
			}
		}
		
		for (auto&& [l,r] : q) {
			std::reverse(s.begin() + l, s.begin() + r);
		}

		for (auto it = s.begin(); it != s.end(); ++it) {
			if (*it == '(' || *it == ')') {
				s.erase(it--);
			}
		}
		
		return s;
	}
};
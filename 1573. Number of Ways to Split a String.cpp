class Solution {
public:
	using ll = long long;
	const int MOD = 1e9 + 7;
	
	int numWays(string s) {
		int N = s.size();
		vector<int> cnt(N+1, 0);
		for (int i = 0; i < N; ++i) {
			cnt[i+1] = cnt[i] + (s[i] == '1');
		}
		
		if (cnt[N] % 3 != 0) return 0;
		if (cnt[N] == 0) return ll(N-1) * ll(N-2) / 2 % MOD;
		
		int a = 0, b = 0;
		for (int i = 0; i < N; ++i) {
			if (cnt[i] == cnt[N] / 3) a++;
			if (cnt[i] == cnt[N] / 3 * 2) b++;
		}

		return ll(a) * ll(b) % MOD;
	}
};
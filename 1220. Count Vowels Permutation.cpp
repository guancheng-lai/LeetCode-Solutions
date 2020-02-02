class Solution {
public:
	int countVowelPermutation(int n) {
		int mod = (1.0e+9) + 7;
		long a = 1, e = 1, i = 1, o = 1, u = 1;
		for (int idx = 1; idx < n; ++idx) {
			long nextA = (e + i + u) % mod;
			long nextE = (a + i) % mod;
			long nextI = (e + o) % mod;
			long nextO = (i) % mod;
			long nextU = (i + o) % mod;
			a = nextA; 
			e = nextE;
			i = nextI;
			o = nextO;
			u = nextU;
		}
		return (a + e + i + o + u) % mod;
	}
};
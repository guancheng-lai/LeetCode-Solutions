import java.util.*;

class Solution {
	public List<Integer> findAnagrams(String s, String p) {
		List<Integer> res = new ArrayList<Integer>();
		if (s.length() == 0 || p.length() > s.length()) return res;
		
		int[] a1 = new int[26];
		for (char c : p.toCharArray()) a1[ c-'a' ]++;

		int[] a2 = new int[26];
		for (int i = 0; i < p.length(); ++i) a2[ s.charAt(i)-'a' ]++;
		
		for (int i = 0; i < s.length() - p.length(); ++i) {
			if (Arrays.equals(a1, a2)) res.add(i);
			
			int l = i, r = i + p.length();
			a2[ s.charAt(l)-'a' ]--;
			a2[ s.charAt(r)-'a' ]++;
		}
		
		if (Arrays.equals(a1, a2)) res.add(s.length() - p.length());
			
		return res;
	}
	
	public static void main(String[] args) {
		Solution s = new Solution();
		List<Integer> res = s.findAnagrams("abab", "ab");
		for (int i : res) {
			System.out.println(i);
		}
	}
}
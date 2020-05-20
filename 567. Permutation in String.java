class Solution {
	public boolean checkInclusion(String s1, String s2) {
		if (s1.length() > s2.length()) return false;
		int[] a1 = new int[26];
		for (char c : s1.toCharArray()) {
			a1[ c-'a' ]++;
		}
		
		int[] a2 = new int[26];
		for (int i = 0; i < s1.length(); ++i) {
			a2[ s2.charAt(i)-'a' ]++;
		}
		
		for (int i = s1.length(); i < s2.length(); ++i) {

			if (Arrays.equals(a1,a2)) return true;
			a2[ s2.charAt(i-s1.length())-'a' ]--;
			a2[ s2.charAt(i)-'a' ]++;
		}
		
		return Arrays.equals(a1,a2);
	}
}
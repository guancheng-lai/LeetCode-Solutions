import java.util.*;

class Pair<L,R> {

	public L left;
	public R right;

	public Pair(L left, R right) {
		assert left != null;
		assert right != null;

		this.left = left;
		this.right = right;
	}

	@Override
	public int hashCode() { return left.hashCode() ^ right.hashCode(); }

	@Override
	public boolean equals(Object o) {
		if (!(o instanceof Pair)) return false;
		
		Pair pairo = (Pair) o;
		return this.left.equals(pairo.left) && this.right.equals(pairo.right);
	}
}

class Solution {
	public String removeDuplicates(String s, int k) {
		Stack<Pair<Character,Integer>> stk = new Stack< Pair<Character,Integer> >();
		for (char c : s.toCharArray()) {
			if (stk.isEmpty()) {
				stk.push( new Pair<Character,Integer>(c,1) );
				continue;
			}
			
			if (stk.peek().left != c) {
				stk.push( new Pair<Character,Integer>(c,1) );
				continue;
			}
			
			Pair<Character,Integer> p = stk.pop();
			p.right++;
			if (p.right != k) {
				stk.push(p);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		while (!stk.isEmpty()) {
			Pair<Character,Integer> p = stk.pop();
			for (int i = 0; i < p.right; ++i) sb.append( p.left );
		}
		
		return sb.reverse().toString();
	}
	
	public static void main(String[] args) {
		Solution s = new Solution();
//		System.out.println( s.removeDuplicates("deeedbbcccbdaa", 3) );
//		System.out.println( s.removeDuplicates("pbbcggttciiippooaais", 2) );
		System.out.println( s.removeDuplicates("abcd", 2) );
	}
}













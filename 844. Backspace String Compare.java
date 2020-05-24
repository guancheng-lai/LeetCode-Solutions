class Solution {
	public boolean backspaceCompare(String S, String T) {
		return solve(S).equals( solve(T) );
	}
	
	private String solve(String s) {
		Stack<Character> stk = new Stack<>();
		for (char c : s.toCharArray()) {
			if (c == '#' && !stk.isEmpty()) {
				stk.pop();
			}
			else if (c != '#') {
				stk.push(c);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		while (!stk.isEmpty()) {
			sb.append(stk.pop());
		}
		
		return sb.reverse().toString();
	}
}
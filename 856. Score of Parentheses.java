class Solution {
	public int scoreOfParentheses(String S) {
		Stack<Integer> stk = new Stack<>();
		stk.push(0);
		
		for (char c : S.toCharArray()) {
			if (c == '(') {
				stk.push(0);
			}
			else {
				int inner = stk.pop();
				int outer = stk.pop();
				stk.push(outer + Math.max(inner*2,1));
			}
		}
		
		return stk.pop();
	}
}
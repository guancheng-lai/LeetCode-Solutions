class Solution {
	public int calculate(String s) {
		s = s.replace(" ", "");
		Stack<Integer> stk = new Stack<>();
		
		int n = 0;
		char op = '+';
		for (int i = 0; i < s.length(); ++i) { 
			char c = s.charAt(i);
			if (Character.isDigit(c)) {
				n = n * 10 + c - '0';
			}
			
			if (!Character.isDigit(c) || i == s.length()-1) {
				if (op == '-') {
					stk.push(-n);
				}
				else if (op == '+') {
					stk.push(n);
				}
				else if (op == '*') {
					stk.push(stk.pop() * n);
				}
				else if (op == '/') {
					stk.push(stk.pop() / n);
				}
				
				n = 0;
				op = c;
			}
			
		}
		
		int res = 0;
		while (!stk.empty()) {
			res += stk.pop();
		}
		return res;
	}
}
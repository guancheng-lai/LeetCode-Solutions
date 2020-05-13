class Solution {
	public String removeKdigits(String num, int k) {
		if (num.length() == k) return "0";
		if (k == 0) return num;
		
		Stack<Integer> stk = new Stack<Integer>();
		for (char c : num.toCharArray())
		{
			int i = c - '0';
			while (k > 0 && !stk.empty() && stk.peek() > i)
			{
				k--;
				stk.pop();
			}
			
			if (!stk.empty() || i != 0)
			{
				stk.add(i);    
			}
		}
		
		while (k > 0 && !stk.empty())
		{
			k--;
			stk.pop();
		}
		
		StringBuilder sb = new StringBuilder();
		while (stk.size() > 0)
		{
			sb.append(stk.peek());
			stk.pop();
		}
		
		if (sb.length() == 0) return "0";
		
		return sb.reverse().toString();
	}
}
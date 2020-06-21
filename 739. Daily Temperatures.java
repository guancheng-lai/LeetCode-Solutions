class Solution {
	public int[] dailyTemperatures(int[] T) {
		int[] result = new int[T.length];
		
		Stack<Integer[]> stk = new Stack<>();
		
		for (int i = 0; i < T.length; ++i) {
			if (stk.isEmpty()) {
				stk.push(new Integer[]{T[i], i});
				continue;
			}
			
			
			while (!stk.isEmpty() && stk.peek()[0] < T[i]) {
				int idx = stk.pop()[1];
				
				result[idx] = i - idx;
			}
			
			stk.push(new Integer[]{T[i], i});
		}
		
		return result;
	}
}
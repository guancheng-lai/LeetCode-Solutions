class StockSpanner {

	Stack< int[] > stk;
	
	public StockSpanner() {
		stk = new Stack< int[] >();
	}
	
	public int next(int price) {
		int res = 1;
		
		while (!stk.isEmpty() && stk.peek()[0] <= price) {
			int[] p = stk.pop();
			res += p[1];
		}
		stk.push(new int[]{price,res});
		return res;
	}
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
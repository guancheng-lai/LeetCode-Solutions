import java.util.*;

class MinStack {

	public Stack<Integer> minStk;
	public Stack<Integer> stk;
	
	/** initialize your data structure here. */
	public MinStack() {
		minStk = new Stack<Integer>();
		stk = new Stack<Integer>();
	}
	
	public void push(int x) {
		stk.push(x);
		if (minStk.empty() || minStk.peek() >= x) {
			minStk.push(x);
		}
	}
	
	public void pop() {
		if (minStk.peek().equals(stk.peek())){
			minStk.pop();
		}
		
		stk.pop();
	}
	
	public int top() {
		return stk.peek();
	}
	
	public int getMin() {
		return minStk.peek();
	}
}

class a {
	public static void main(String[] args) {
		MinStack obj = new MinStack();
		obj.push(512);
		obj.push(-1024);
		obj.push(-1024);
		obj.push(512);
		
		System.out.println(Arrays.toString(obj.minStk.toArray()));
		System.out.println(Arrays.toString(obj.stk.toArray()));
		
		obj.pop();
		System.out.println(Arrays.toString(obj.minStk.toArray()));
		System.out.println(Arrays.toString(obj.stk.toArray()));
		System.out.println( obj.getMin() );
		
		obj.pop();
		System.out.println(Arrays.toString(obj.minStk.toArray()));
		System.out.println(Arrays.toString(obj.stk.toArray()));
		System.out.println( obj.getMin() );
		
		
		obj.pop();
		System.out.println(Arrays.toString(obj.minStk.toArray()));
		System.out.println(Arrays.toString(obj.stk.toArray()));
		System.out.println( obj.getMin() );
	}
}
class Solution {
	public int maxSubarraySumCircular(int[] A) {
		int n = A.length, sum = 0, maxElement = A[0], minElement = A[0];
		int maxSoFar = 0, maxTotal = A[0], minSoFar = 0, minTotal = A[0];
		
		for (int a : A) {
			sum += a;
			maxElement = Math.max( maxElement,a );
			minElement = Math.min( minElement,a );
			
			maxSoFar = Math.max( a,maxSoFar+a );
			maxTotal = Math.max( maxTotal,maxSoFar );
			
			minSoFar = Math.min( a,minSoFar+a );
			minTotal = Math.min( minTotal,minSoFar );
		}
		
		System.out.println("maxSoFar = " + maxSoFar);
		System.out.println("maxTotal = " + maxTotal);
		System.out.println("minSoFar = " + minSoFar);
		System.out.println("minTotal = " + minTotal);
		System.out.println("sum = " + sum);
		
		if (sum == minSoFar) { 
			return maxTotal;
		}
		
		return Math.max( maxTotal, sum - minTotal );
	}
	
	public static void main(String[] args) {
		Solution s = new Solution();
//		int[] A = { -10,-7,9,-7,6,9,-9,-4,-8,-5 };
		int[] A = {-2,-3,-1};
		System.out.println("RES: " + s.maxSubarraySumCircular(A));
	}
}
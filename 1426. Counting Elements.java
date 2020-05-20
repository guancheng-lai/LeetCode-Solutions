class Solution {
	public int countElements(int[] arr) {
		int res = 0;
		HashMap<Integer, Integer> mp = new HashMap<>();
  
		for (int i : arr) {
			mp.put( i,mp.getOrDefault(i,0)+1 );
		}
		
		for (Integer k : mp.keySet()) {
			res += mp.getOrDefault(k+1,0);
		}
		
		return res;
	}
}
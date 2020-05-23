/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
	public int[] nextLargerNodes(ListNode head) {
		ArrayList<Integer> list = new ArrayList<>();
		if (head == null) return new int[0];
		int idx = 0;
		Stack<int[]> stk = new Stack<int[]>();
		while (head != null) {
			list.add(0);
			
			while (!stk.isEmpty() && stk.peek()[0] < head.val) {
				int[] curr = stk.pop();
				list.set(curr[1], head.val);
			}
			
			stk.push( new int[]{head.val,idx} );
			
			head = head.next;
			idx++;
		}

		int[] res = new int[list.size()];
		for (int i = 0; i < list.size(); i++) {
			res[i] = list.get(i);
		}
		return res;
	}
}
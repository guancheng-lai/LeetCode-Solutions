/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
	private int maxSum = Integer.MIN_VALUE;
	
	public int maxPathSum(TreeNode root) {
		int res = helper(root);
		return Math.max(maxSum, res);
	}
	
	private int helper(TreeNode root) {
		if (root == null) return 0;
		
		int left = Math.max(0, helper(root.left));
		int right = Math.max(0, helper(root.right));
		
		maxSum = Math.max(maxSum, root.val + left + right);
		
		return Math.max(left, right) + root.val;
	}
}
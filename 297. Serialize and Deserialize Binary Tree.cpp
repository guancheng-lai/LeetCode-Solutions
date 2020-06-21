/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

	private StringBuilder sb;
	int idx = 0;
	
	// Encodes a tree to a single string.
	public String serialize(TreeNode root) {
		sb = new StringBuilder();
		serializeHelper(root);
		return this.sb.toString();
	}

	// Decodes your encoded data to tree.
	public TreeNode deserialize(String data) {
		TreeNode root = new TreeNode(-1);
		return deserializeHelper(data.split(" "), root);
	}
	
	private void serializeHelper(TreeNode root) {
		if (root == null) {
			sb.append("# ");
			return;
		}
		
		sb.append(root.val);
		sb.append(" ");
		serializeHelper(root.left);
		serializeHelper(root.right);
	}
	
	private TreeNode deserializeHelper(String[] data, TreeNode root) {
		if (data[idx].equals("#")) {
			this.idx++;
			return null;
		}
		
		root = new TreeNode( Integer.parseInt(data[idx]) );
		this.idx++;
		root.left = deserializeHelper(data, root.left);
		root.right = deserializeHelper(data, root.right);
		
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
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
    public int maxPathSum(TreeNode root) {

        int maxSum[] = new int[1];
        maxSum[0] = Integer.MIN_VALUE;
        recursePath(root, maxSum);

        return maxSum[0];
    }

    public int recursePath(TreeNode root, int maxSum[])
    {
        if(root == null) return 0;

        //to check for left node of the root
        int left = Math.max(0, recursePath(root.left, maxSum));
        //to check for the right node of the root
        int right = Math.max(0, recursePath(root.right, maxSum));

        //calculate the maximum sum so far for a given node
        maxSum[0] = Math.max(maxSum[0], left+right+root.val);

        //return the maximum path sum in a path
        return Math.max(left, right) + root.val;
    }
}

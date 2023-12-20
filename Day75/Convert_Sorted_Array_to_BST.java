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

    public TreeNode sortedArrayToBST(int[] nums) {

        return createNodes(0, nums.length-1, nums);
    }

    private TreeNode createNodes(int left, int right, int[] nums)
    {
        //if you have reached the middle of the tree, means until root is filled
        if(left > right) 
        {
            return null;
        }

        int mid = (left+right)/2;

        //create a root node, in bst array root is in the middle
        TreeNode root = new TreeNode(nums[mid]);

        //recursively create nodes of left subtree
        root.left = createNodes(left, mid-1, nums);

        //recursively create nodes of right subtree
        root.right = createNodes(mid+1, right, nums);

        return root;
    }
}

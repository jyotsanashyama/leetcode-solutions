
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;  ///initialize max sum to be the smallest possible int
        find_sum(root,sum);
        return sum;
    }

    int find_sum(TreeNode* root, int &sum){
        // base case
        if(root==NULL) return 0;

        int left_sum = max(0,find_sum(root->left,sum));  ///find max sum from left
        int right_sum = max(0,find_sum(root->right,sum));  ///find max sum from right

        int current=root->val;  ///store the current node

        ///update the sum value if current path includidng the current node is greater
        sum = max(sum, (left_sum + right_sum + current));

        ///return max sum path
        return max(left_sum, right_sum) + current;
    }
};

class Solution {
    public:
        class Node {
            public:
                Node * left;
                Node * right;
        };
    vector < int > a;
    void insert(Node * & head, int n) {
        Node * curr = head;
        for (int i = 31; i >= 0; i--) {
            int x = (n >> i) & 1;
            if (x == 0) {
                if (!curr -> left)
                    curr -> left = new Node();
                curr = curr -> left;
            } else {
                if (!curr -> right)
                    curr -> right = new Node();
                curr = curr -> right;
            }
        }
    }
    int calculate(Node * & head) {

        int max_xor = INT_MIN;

        for (int i = 0; i < a.size(); i++) {
            Node * curr = head;
            int curr_xor = 0;
            for (int j = 31; j >= 0; j--) {
                int x = a[i] >> j & 1;
                if (x == 0) {
                    if (curr -> right) {
                        curr_xor += pow(2, j);
                        curr = curr -> right;
                    } else {
                        curr = curr -> left;
                    }
                } else {
                    if (curr -> left) {
                        curr_xor += pow(2, j);
                        curr = curr -> left;
                    } else {
                        curr = curr -> right;
                    }
                 }
            }
            max_xor = max(curr_xor, max_xor);
        }
        return max_xor;
    }
    int findMaximumXOR(vector < int > & nums) {
        a = nums;
        Node * head = new Node();
        for (int i = 0; i < nums.size(); i++) {
            insert(head, nums[i]);
        }
        return calculate(head);
    }
};

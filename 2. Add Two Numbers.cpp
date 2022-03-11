/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        {
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1 == nullptr && l2==nullptr){
            return nullptr;
        }
        ListNode *root = nullptr;
        ListNode *cmp = nullptr;
        int carry = 0;
        int x;
        int sum = 0;
        while(l1!=nullptr && l2!=nullptr){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            x = sum%10;
            if(root==nullptr){
                root = new ListNode(x);
                cmp = root;
            }else{
                cmp->next = new ListNode(x);
                cmp = cmp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr){
            sum = l1->val + carry;
            carry = sum/10;
            x = sum%10;
            cmp->next = new ListNode(x);
            cmp = cmp->next;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            sum = l2->val + carry;
            carry = sum/10;
            x = sum%10;
            cmp->next = new ListNode(x);
            cmp = cmp->next;
            l2 = l2->next;
        }
        while(carry!=0){
            x = carry%10;
            cmp->next = new ListNode(x);
            carry = carry/10;
            cmp = cmp->next;
        }
        return root;
    }
};
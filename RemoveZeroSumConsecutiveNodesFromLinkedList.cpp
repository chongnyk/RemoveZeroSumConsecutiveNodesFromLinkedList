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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum = 0;
        ListNode header = ListNode(0, head);
        ListNode* iter = &header;
        unordered_map<int, ListNode*> sumsByNode;
        int i = -1;
        while(iter != nullptr){
            sum += iter->val;
            cout << ++i << ' ' << iter->val << ' ' << sum << '\n';
            if(sumsByNode.find(sum) == sumsByNode.end()){
                sumsByNode[sum] = iter;
            }
            else {
                int sumTracer = sum;
                for(ListNode* eraser = sumsByNode[sum]->next; eraser != iter; eraser = eraser->next){
                    sumTracer += eraser->val;
                    sumsByNode.erase(sumTracer);
                }
                sumsByNode[sum]->next = iter->next;
            }
            iter = iter->next;
        }
        return header.next;
    }
};

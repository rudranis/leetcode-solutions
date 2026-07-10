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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prevgroup=&dummy;
        ListNode* groupstart=head;
        int groupsize=1;
        while(groupstart){
            int actualsize=0;
            ListNode* groupend=groupstart;
            while(groupend && actualsize<groupsize){
                actualsize++;
                if(actualsize==groupsize || !groupend->next){
                    break;
                }
                groupend=groupend->next;
            }
            ListNode* nextgroup=groupend->next;
            if(actualsize%2==0){
                ListNode* prev=nextgroup;
                ListNode* curr=groupstart;
                while(actualsize--){
                    ListNode* getnext=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=getnext;
                }
                prevgroup->next=prev;
                prevgroup=groupstart;
            }
            else{
                prevgroup=groupend;
            }
            groupstart=nextgroup;
            groupsize++;
        }
        return dummy.next;
    }
};
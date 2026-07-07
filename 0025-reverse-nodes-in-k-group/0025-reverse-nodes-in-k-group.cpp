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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prevgroup=&dummy;
        while(true){   //find kth node 
            ListNode* kth =prevgroup;
            for(int i=0;i<k && kth;i++){
                kth=kth->next;
            }
            if(kth==nullptr) break;
            ListNode* groupnext=kth->next;
            ListNode* prev=groupnext;   // reverse group 
            ListNode* curr=prevgroup->next;
            while(curr!=groupnext){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=prevgroup->next; //connect
            prevgroup->next=kth;
            prevgroup=temp;

        }
        return dummy.next;
    }
};
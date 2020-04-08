/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr) { return head; }
		if (head->next == nullptr) {return head;}
		
		ListNode *fast = head, *slow = head;
		while (fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
			
			if (fast == nullptr) break;
		}
		
		return slow;
	}
};
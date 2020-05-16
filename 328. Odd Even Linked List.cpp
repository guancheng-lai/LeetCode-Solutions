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
	ListNode* oddEvenList(ListNode* head) {
		ListNode * cur = head;
		ListNode * evenHead = new ListNode(0);
		ListNode * oddHead = new ListNode(0);
		ListNode * even = evenHead;
		ListNode * odd = oddHead;
		
		if (head == NULL)
		{
			return NULL;
		}
		
		int count(0);
		while (cur != NULL)
		{
			if (count % 2 == 0)
			{
				even->next = cur;
				cur = cur->next;
				even = even->next;
				even->next = NULL;
			}
			else
			{
				odd->next = cur;
				cur = cur->next;
				odd = odd->next;
				odd->next = NULL;
			}
			count++;
		}
		
		even->next = oddHead->next;
		
		return evenHead->next;
	}
};
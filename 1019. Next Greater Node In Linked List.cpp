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
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> res;
		if (head == nullptr) return res;
		
		int idx(0), count(0);
		stack<pair<int,int>> monoStk;
		while (head) 
		{
			res.emplace_back(0);
			if (monoStk.empty()) 
			{
				monoStk.push( {head->val,idx} );
				// res.emplace_back(0);
			}
			else 
			{
				while (!monoStk.empty() && monoStk.top().first < head->val) 
				{
					auto [val,idx] = monoStk.top();
					res[idx] = head->val;
					monoStk.pop();
				}
			
				monoStk.push( {head->val,idx } );
			}
			
			head = head->next;
			idx++;
		}
		
		return res;
	}
};
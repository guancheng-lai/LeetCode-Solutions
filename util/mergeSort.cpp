#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
		
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		

		ListNode * prev = nullptr;
		ListNode * fast = head;
		ListNode * slow = head;
		
		while (fast != nullptr && fast->next != nullptr) {
//			cout << fast->val << " " << slow->val << endl;
			
			prev = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		
		prev->next = nullptr;
		
		ListNode * firstHalf = sortList(head);
		ListNode * secondHalf = sortList(slow);
		
		return merge(firstHalf, secondHalf);
	}
	
	ListNode* merge(ListNode * a, ListNode * b) {
		ListNode start(0);
		ListNode * result = &start;
		while (a != nullptr && b != nullptr) {
			if (a->val < b->val) {
				result->next = new ListNode(a->val);
				a = a->next;
			}
			else {
				result->next = new ListNode(b->val);
				b = b->next;
			}
			
			result = result->next;
		}
			
		result->next = (a == nullptr) ? b : a;
			
		return (&start)->next;
	}
};

int main(int argc, char *argv[]) {
	ListNode * a = new ListNode(4);
	a->next = new ListNode(2);
	a->next->next = new ListNode(1);
	a->next->next->next = new ListNode(3);
	Solution s1;

	ListNode * p = s1.sortList(a);
	while (p != nullptr) {
		cout << p->val << " ";
		p = p->next;
	}
}
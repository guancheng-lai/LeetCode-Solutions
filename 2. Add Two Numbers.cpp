#include <iostream>
using namespace std;

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * l1_copy = l1;
		ListNode * l2_copy = l2;
		
		string number1 = "";
		string number2 = "";
		
		while (l1_copy != NULL) {
			number1 += to_string(l1_copy->val);
			l1_copy = l1_copy->next;
		}

		while (l2_copy != NULL) {
			number2 += to_string(l2_copy->val);
			l2_copy = l2_copy->next;
		}

		if (number1.size() > number2.size())
		{
			string addUp = "";
			int distance = number1.size() - number2.size();
			for (int i = 0; i < distance; ++i)
			{
				addUp += "0";
			}
			
			number2 = addUp + number2;
		}
		else if(number1.size() < number2.size())
		{
			string addUp = "";
			int distance = number2.size() - number1.size();
			for (int i = 0; i < distance; ++i)
			{
				addUp += "0";
			}
			
			number1 = addUp + number1;
		}
		
		string result;
		int length = number1.size();
		int nextDigit = 0;
		for (int i = 0; i < number1.size(); ++i)
		{
			int sum = stoi(number1.substr(i, 1)) + stoi(number2.substr(i, 1));
			cout << sum << " ";
			
			if (nextDigit != 0)
			{
				sum++;
				nextDigit = 0;
			}

			if (sum > 9)
			{
				cout << "ADD " ;
				nextDigit = 1;
				sum -= 10;
			}
			
			result += to_string(sum);
			
		}
		
		//cout << endl << result << endl;
		
		if (nextDigit)
		{
			result += to_string(1);
		}
		
		ListNode * resultPtr = new ListNode(0);
		ListNode * cur = resultPtr;
		for (int i = result.size() -1; i > 0; i--)
		{
			cur->val = stoi(result.substr(i, 1));
			cur->next = new ListNode(0);
			cur = cur->next;   
		}
		cur->val = stoi(result.substr(0, 1));
		return resultPtr;
	}


int main()
{
	ListNode * l1 = new ListNode(2);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(1);
	
	ListNode * l2 = new ListNode(5);
	l2->next = new ListNode(0);
	l2->next->next = new ListNode(9);	
	
	ListNode * ptr = addTwoNumbers(l1, l2);
	while (ptr != NULL)
	{
		cout << ptr->val << "-";
		ptr = ptr->next;
	}
}
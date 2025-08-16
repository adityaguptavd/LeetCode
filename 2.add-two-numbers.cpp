#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Leet code solution class
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        int carry = 0;
        int sum = 0;
        ListNode* l1_temp = l1;
        ListNode* l2_temp = l2;
        ListNode* result_temp = result;
        do{
            sum = l1_temp->val + l2_temp->val + carry;
            carry = sum / 10;
            if(result_temp == nullptr) {
                result = new ListNode(sum % 10);
                result_temp = result;
            }
            else{
                result_temp->next = new ListNode(sum % 10);
                result_temp = result_temp->next;
            }
            l1_temp = l1_temp->next;
            l2_temp = l2_temp->next;
        }while(l1_temp != nullptr && l2_temp != nullptr);
        
        while(l1_temp != nullptr) {
            sum = l1_temp->val + carry;
            carry = sum / 10;
            result_temp->next = new ListNode(sum % 10);
            result_temp = result_temp->next;
            l1_temp = l1_temp->next;
        }

        while(l2_temp != nullptr) {
            sum = l2_temp->val + carry;
            carry = sum / 10;
            result_temp->next = new ListNode(sum % 10);
            result_temp = result_temp->next;
            l2_temp = l2_temp->next;
        }

        if(carry) {
            result_temp->next = new ListNode(carry);
        }

        return result;
    }
};

// Driver code
int main() {
    Solution sln;
    ListNode* l1 = new ListNode(6);
    ListNode* l1_temp = l1;
    l1_temp->next = new ListNode(2);
    l1_temp = l1_temp->next;
    l1_temp->next = new ListNode(4);
    l1_temp = l1_temp->next;
    l1_temp->next = new ListNode(8);
    l1_temp = l1_temp->next;
    l1_temp->next = new ListNode(3);

    ListNode* l2 = new ListNode(3);
    ListNode* l2_temp = l2;
    l2_temp->next = new ListNode(9);
    l2_temp = l2_temp->next;
    l2_temp->next = new ListNode(5);

    l1_temp = l1;
    cout << "Num1: ";
    while(l1_temp != nullptr) {
        cout << l1_temp->val;
        l1_temp = l1_temp->next;
    }

    cout << endl << "Num2: ";
    l2_temp = l2;
    while(l2_temp != nullptr) {
        cout << l2_temp->val;
        l2_temp = l2_temp->next;
    }

    cout << endl;

    ListNode* result = sln.addTwoNumbers(l1, l2);

    cout << "Result:" << endl;

    l1_temp = l1;
    while(l1_temp != nullptr) {
        cout << l1_temp->val;
        l1_temp = l1_temp->next;
    }

    cout << " + ";

    l2_temp = l2;
    while(l2_temp != nullptr) {
        cout << l2_temp->val;
        l2_temp = l2_temp->next;
    }

    cout << " = ";

    while(result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    return 0;
}
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead=new ListNode();
        ListNode *curr=dummyHead;
        int carry=0;
        while(l1!=NULL||l2!=NULL||carry!=0)
        {
            int x=l1?l1->val:0;
            int y=l2?l2->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
        }
        ListNode *result=dummyHead->next;
        delete dummyHead;
        return result;
    }
};

// 根据数组创建链表
ListNode* createList(const vector<int>& values) {
    ListNode dummyHead;
    ListNode* curr = &dummyHead;
    for (int value : values) {
        curr->next = new ListNode(value);
        curr = curr->next;
    }
    return dummyHead.next;
}

// 按照 LeetCode 格式输出链表
void printList(const ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]";
}

// 释放链表
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

// 执行一个测试用例
void runTest(
    int testNumber,
    const vector<int>& values1,
    const vector<int>& values2
) {
    ListNode* l1 = createList(values1);
    ListNode* l2 = createList(values2);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Example " << testNumber << ":\n";

    cout << "Input: l1 = ";
    printList(l1);

    cout << ", l2 = ";
    printList(l2);

    cout << "\nOutput: ";
    printList(result);

    cout << "\n\n";

    deleteList(l1);
    deleteList(l2);
    deleteList(result);
}

int main() {
    // Example 1
    runTest(
        1,
        {2, 4, 3},
        {5, 6, 4}
    );

    // Example 2
    runTest(
        2,
        {0},
        {0}
    );

    // Example 3
    runTest(
        3,
        {9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9}
    );

    return 0;
}
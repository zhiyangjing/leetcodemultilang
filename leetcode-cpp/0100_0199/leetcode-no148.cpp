#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* sortList(ListNode *head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head,ListNode* tail){
        if (head == nullptr){
            return head;
        }
        if (head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail){
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head,mid), sortList(mid,tail));
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1,*temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp2 != nullptr){
            temp->next = temp2;
        } else if (temp1 != nullptr) {
            temp->next = temp1;
        }
        return dummyHead->next;
    }
};

int main(){
    ListNode s3(3);
    ListNode s2(1,&s3);
    ListNode s1(2,&s2);
    ListNode s0(4,&s1);
    Solution test;
    ListNode* res = test.sortList(&s0);
    while (res) {
        cout << res->val;
        res = res->next;
    }
}

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         return sortList(head, nullptr);
//     }
//     ListNode* sortList(ListNode* head,ListNode* tail) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while (fast->next and fast->next != tail and fast->next->next) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         if (slow->next)
//         sortList(slow->next);
//     }
// };
//

// Created by ASUS on 2023/6/14.
//

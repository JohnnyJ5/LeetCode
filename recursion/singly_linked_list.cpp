#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <algorithm>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseList(ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode * newHead = reverseList(head->next);  //always the same value throughout the recursion stack.  KEY!
    std::cout << "Newhead: " << newHead->val << std::endl;
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void printList(ListNode* head)
{
    while (head != NULL)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

//1->2->3->4->5->NULL
int main(int argc, char * argv[])
{
    ListNode one(1);
    ListNode two(2);
    ListNode three(3);
    ListNode four(4);
    ListNode five(5);

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;

    ListNode * reversed = reverseList(&one);
    printList(reversed);
}
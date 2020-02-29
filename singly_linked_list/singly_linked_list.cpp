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

ListNode* reverseListRecursion(ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode * newHead = reverseListRecursion(head->next);  //always the same value throughout the recursion stack.  KEY!
    // std::cout << "Newhead: " << newHead->val << std::endl;
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
//Iteration  prev  curr  next
//   0        N     1      N
//   1        1     2      2      
ListNode * reverseListIteration(ListNode * head)
{
    ListNode * curr = head;
    ListNode * prev = NULL;
    ListNode * next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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

    ListNode * head = reverseListRecursion(&one);
    std::cout << "Reverse list recursion" << std::endl;
    printList(head);
    head = reverseListRecursion(head);

    std::cout << "Reverse list iteration" << std::endl;
    head = reverseListIteration(head);
    printList(head);
}
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
} *head = NULL, *tail = NULL, *tail2 = NULL, *head2 = NULL;

void createLL()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter val for ListNode" << endl;
        cin >> d;
        ListNode *p = new ListNode();
        p->val = d;
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        cout << "Do you want to enter more ListNode (0/1)" << endl;
        cin >> t;
    }
}

void createLL2()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter val " << endl;
        ListNode *p = new ListNode();
        cin >> d;
        p->val = d;
        p->next = NULL;
        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
        }
        else
        {
            tail2->next = p;
            tail2 = tail2->next;
        }
        cout << "Do you want to add more node" << endl;
        cin >> t;
    }
}

// class Solution
// {
// public:
//     ListNode *addTwoLists(ListNode *first, ListNode *second)
//     {
//         ListNode *a = first;
//         ListNode *b = second;
//         int n1 = 0, n2 = 0;
//         while (a != NULL)
//         {
//             n1 = 10 * n1 + a->val;
//             a = a->next;
//         }
//         while (b != NULL)
//         {
//             n2 = 10 * n2 + b->val;
//             b = b->next;
//         }
//         int n3 = n1 + n2;
        // while (n3 != 0)
        // {
        //     ListNode *p = new ListNode();
        //     p->val = n3 % 10;
        //     p->next = NULL;
        //     if (third == NULL)
        //     {
        //         third = tail3 = p;
        //     }
        //     else
        //     {
        //         tail3->next = p;
        //         tail3 = tail3->next;
        //     }
        //     n3 = n3 / 10;
        // }
//         reverseLL(third);
//         return third;
//     }
    // ListNode *reverseLL(ListNode *p)
    // {
    //     ListNode *a = NULL;
    //     ListNode *b = p;
    //     ListNode *c = NULL;
    //     while (b != NULL)
    //     {
    //         c = b->next;
    //         b->next = a;
    //         a = b;
    //         b = c;
    //     }
    //     third = a;
    // }
// };

class Solution
{
    private:
    ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(struct ListNode* &head, struct ListNode* &tail, int val) {
        
        ListNode* temp = new ListNode();

        temp->val = val;
        temp->next = NULL;


        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct ListNode* add(struct ListNode* first, struct ListNode* second) {
        int carry = 0;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> val;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> val;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct ListNode* addTwoLists(struct ListNode* first, struct ListNode* second)
    {
        //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        ListNode* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
    }
};

void printLL(ListNode *p)
{
    cout << "Linked list are" << endl;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}

int main()
{
    createLL();
    createLL2();
    Solution obj;
    printLL(obj.addTwoLists(head, head2));
}
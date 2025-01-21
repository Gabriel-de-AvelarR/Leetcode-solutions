//List definition
/*struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = new ListNode(0); //more efficient than managing the head pointer 
    ListNode* tail = dummy; //pointer to the last node

    int second_digit = 0;

    while(l1 != nullptr || l2 != nullptr || second_digit != 0){
        //we shall consider the case in which the arrays have different sizes
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l2 != nullptr) ? l2->val : 0;

        //when variable are initialized inside loop, compiler can optimize
        //since they don't need to be preserved
        //it also reduces memory access time
        int sum =  val1 + val2 + second_digit; //receives carry from previous addition
        int first_digit = sum%10; 
        second_digit = sum/10; 
        
        tail->next = new ListNode(first_digit); //updates the pointer
        tail = tail->next; //updates the pointer current position

        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;
    }
    ListNode* result = dummy->next;
    delete dummy; //the dummy is discarded in the end   
    return result; 
    }
};
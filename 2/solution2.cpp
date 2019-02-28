//
//  solution2.cpp
//  
//
//  Created by kevinlin on 2018/10/17.
//

#include "solution2.hpp"
#include <iostream>



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* node = NULL;
    ListNode* cur_l1 = l1;
    ListNode* cur_l2 = l2;
    int padding = 0;
    while(cur_l1 || cur_l2){
        int val = (cur_l1 ? cur_l1->val : 0) + (cur_l2 ? cur_l2->val : 0) + padding;
        padding = val / 10;
        if(node){
            node->next = new ListNode(val % 10);
        } else{
            node = new ListNode(val % 10);
        }
        
        if(cur_l1){
            cur_l1 = cur_l1->next;
        }
        
        if(cur_l2){
            cur_l2 = cur_l2->next;
        }
        
    }
    return node;
}

int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(5);
    l2->next = new ListNode(4);
    
    ListNode res = addTwoNumbers(l1, l2);
    while(res){
        std::cout<<res->val<<",";
        res = res->next;
    }
    
    return 0;
        
}

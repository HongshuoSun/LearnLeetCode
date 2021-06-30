#include <iostream>
#include <stdlib.h>
#include "23.h"
#include "Common.h"
int main() {
    Solution s;
    ListNode* head1 = new ListNode(2);
    ListNode* head2 = new ListNode(3);
    vector<ListNode*> v1;
    v1.push_back(head1);
    v1.push_back(head2);
    s.mergeKLists(v1);
    return 0;
}
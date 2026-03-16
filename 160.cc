/* 
 * 160. 相交链表
 *
 * 思路：
 * 1. 双指针
 * 如果两个链表相交，则这两个向量分别依次添加到彼此的链表尾部，
 * +可以得到相同的末尾节点，否则，两者的节点都是空。
 *
 * 这两个链表合并（A+B或者B+A）的长度是相同的，而如果存在相同的共同的节点，
 * +则这个节点在双指针遍历的过程中会使得两个指针指向的值相同，如果不存在相同的节点，
 * +则两个指针最后都会是NULL。
 * 
 *  - TC: O(m+n)
 *  - SC: O(1)
 *
 * 2. Hash集合
 *  - 首先遍历第一个链表，然后将链表节点添加到Hash集合中；然后遍历第二个链表，对于每个链表和Hash集合进行比较。
 *  - TC：O(m+n)
 *  - SC: O(m)：第一个链表大小，存储hash集合
 */
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        while(ptr1 != ptr2) {
            ptr1 = ptr1 == NULL ? headB : ptr1->next;
            ptr2 = ptr2 == NULL ? headA : ptr2->next;
        }

        return ptr1;
    }
};

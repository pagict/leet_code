# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        lenA = 0
        lenB = 0
        p = headA
        while p is not None:
            lenA = lenA + 1
            p = p.next
        p = headB
        while p is not None:
            lenB = lenB + 1
            p = p.next
        if lenA > lenB:
            less = headB
            more = headA
            long = lenA
            short = lenB
        else:
            less = headA
            more = headB
            long = lenB
            short = lenA
        p = more
        for i in range(long - short):
            p = p.next
        p1 = less
        while p is not None:
            if p1 is p:
                return p
            p = p.next
            p1 = p1.next
        return None
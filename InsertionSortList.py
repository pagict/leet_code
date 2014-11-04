# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        if not head or head.next is None:
            return head
            
        fd = ListNode(0)
        fd.next = head
        pre_ptr = fd.next
        ptr = pre_ptr.next
        while ptr is not None:
            if ptr.val < pre_ptr.val:
                q = fd
                while q.next.val < ptr.val:
                    q = q.next
                pre_ptr.next = ptr.next
                ptr.next = q.next
                q.next = ptr
                ptr = pre_ptr.next
            else:
                pre_ptr = ptr
                ptr = ptr.next
                    
        return fd.next
                
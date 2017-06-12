# https://leetcode.com/problems/add-two-numbers/#/description

# Definition for singly-linked list.
# class ListNode(object):
#      def __init__(self, x):
#          self.val = x
#          self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = l3Cur = None
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            if l3Cur == None:
                l3Cur = ListNode(0)
                l3 = l3Cur
            else:
                l3Cur.next = ListNode(0)
                l3Cur = l3Cur.next

            v1 = l1.val if l1 != None else 0
            v2 = l2.val if l2 != None else 0
            sum = v1 + v2 + carry
            if sum >= 10:
                l3Cur.val = sum - 10
                carry = 1
            else:
                l3Cur.val = sum
                carry = 0

            if l1 != None:
                l1 = l1.next
            if l2 != None:
                l2 = l2.next
        return l3

if __name__ == '__main__':
    pass

    # l1 = ListNode(2)
    # l1.next = ListNode(4)
    # l1.next.next = ListNode(3)


    # l2 = ListNode(5)
    # l2.next = ListNode(6)
    # l2.next.next = ListNode(4)

    # s = Solution()
    # r = s.addTwoNumbers(l1, l2)
    # while True:
    #     print r.val
    #     if r.next == None:
    #         break;
    #     r = r.next
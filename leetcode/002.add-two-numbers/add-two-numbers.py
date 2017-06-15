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
        dummyHead = ListNode(0)
        cur = dummyHead
        carry = 0
        while l1 != None or l2 != None or carry > 0:
            sum = 0
            if l1 != None:
                sum += l1.val
                l1 = l1.next
            if l2 != None:
                sum += l2.val
                l2 = l2.next
            sum += carry
            carry = sum / 10
            cur.next = ListNode(sum % 10)
            cur = cur.next

        return dummyHead.next

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
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        y = x

        sign = 1 if y >= 0 else -1
        if sign < 0:
            return False

        r = 0
        while (y != 0):
            r = r * 10 + y % 10
            y /= 10
        return x == r

if __name__ == '__main__':
    pass

    # s = Solution()
    # print 1, s.isPalindrome(1)
    # print 12, s.isPalindrome(12)
    # print 123, s.isPalindrome(123)
    # print 121, s.isPalindrome(121)
    # print -2147483648, s.isPalindrome(-2147483648)
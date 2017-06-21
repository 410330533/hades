class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        maxInt = pow(2, 31)

        sign = 1 if x >= 0 else -1
        x = abs(x)

        r = 0
        while (x != 0):
            r = r * 10 + x % 10
            x /= 10
            if r > maxInt:
                return 0

        return r * sign

if __name__ == '__main__':
    pass

    # s = Solution()
    # print s.reverse(0)
    # print s.reverse(1534236469)
    # print s.reverse(123)
    # print s.reverse(-123)
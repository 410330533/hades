class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        sum = 0
        for i in xrange(len(s) -1):
            x, y = s[i], s[i+1]
            # if d[x] >= d[y]:
            #     sum += d[x]
            # else:
            #     sum -= d[x]
            if d[x] < d[y]:
                sum -= d[x]
            else:
                sum += d[x]
        sum += d[s[-1]]
        return sum

if __name__ == '__main__':
    pass

    # 1=Ⅰ 2=Ⅱ 3=Ⅲ 4=Ⅳ 5=Ⅴ 6=Ⅵ 7=Ⅶ 8=Ⅷ 9=Ⅸ 10=Ⅹ 11=Ⅺ 12=Ⅻ
    # s = Solution()
    # print s.romanToInt('DCXXI')
    # print s.romanToInt('DCIX')
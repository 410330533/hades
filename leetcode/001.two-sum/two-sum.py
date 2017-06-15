class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {};
        for i, n in enumerate(nums):
            if n not in d:
                d[target - n] = i
            else:
                return (d[n], i)
        return (0, 0)

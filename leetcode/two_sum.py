#! /usr/bin/env python
# -*- coding:utf-8 -*-

class Solution:
	def twoSum(self, nums, target):
		"""
		:type nums List[int]
		:type target: int
		:rtype: List[int]
		"""
		d = {};
		for i in nums:
			if i in d:
				return [i, d.get(i)]
			else:
				d[i] = target - i
		return [0,0]
import unittest

#from Animal import *
import animal
#from Dog import *
import dog
import cat
#from Calc import *
import calc

class AnimalTestCase(unittest.TestCase):
	def setUp(self):
		pass
	
	def tearDown(self):
		pass
	
	@classmethod
	def setUpClass(cls):
		print('setUpClass')
	
	@classmethod
	def tearDownClass(cls):
		print('tearDownClass')
	
	def testDogShout(self):
		self._animal = dog.Dog()
		x = 'Dog shout'
		y = self._animal.shout()
		self.assertEqual(x, y)
	
	def testCatShout(self):
		self._animal = cat.Cat()
		x = 'Cat shout'
		y = self._animal.shout()
		self.assertEqual(x, y)
	
	def testCalcAdd(self):
		self._calc = calc.Calc()
		self.assertEqual(3, self._calc.add(1, 2))
	
	def testClacSub(self):
		self._calc = calc.Calc()
		self.assertEqual(-1, self._calc.sub(1, 2))
	
	def testCalcMul(self):
		self._calc = calc.Calc()
		self.assertEqual(2, self._calc.mul(1, 2))
	
	def testCalcTrueDiv(self):
		self._calc = calc.Calc()
		self.assertEqual(0.5, self._calc.trueDiv(1, 2))
		self.assertEqual(0, self._calc.trueDiv(1, 0))
	
	def testFloorDiv(self):
		self._calc = calc.Calc()
		self.assertEqual(0, self._calc.floorDiv(1, 2))
		self.assertEqual(0, self._calc.floorDiv(1, 0))

if __name__ == "__main__":
	unittest.main()
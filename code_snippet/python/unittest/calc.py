class Calc:
	def __init__(self):
		pass
	
	def add(self, x, y):
		return x + y
	
	def sub(self, x, y):
		return x - y
	
	def mul(self, x, y):
		return x * y
	
	def trueDiv(self, x, y):
		if y == 0:
			return 0
		
		return x / y
	
	def floorDiv(self, x, y):
		if y == 0:
			return 0
		
		return x // y
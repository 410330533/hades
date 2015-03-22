import animal
#from animal import *

class Dog(animal.Animal):
	def __init__(self):
		animal.Animal.__init__(self)
		# print("Dog __init__")
		pass
	
	def shout(self):
		return "Dog shout"
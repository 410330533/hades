import animal

class Cat(animal.Animal):
    def __init__(self):
        animal.Animal.__init__(self)
        # print("Cat __init__")
        pass
    
    def shout(self):
        return "Cat shout"
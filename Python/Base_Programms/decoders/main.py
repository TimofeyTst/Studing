
class decoder:
    def __set_name__(self, owner, name):
        self.name="_" + name
    
    def __get__(self,instance, owner):
        return instance.__dict__[self.name]
    
    def __set__(self,instance,value):
        instance.__dict__[self.name] = value

class point:
    x = decoder()


    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
my = point(1,2,3)


print("------------------------------------------------------------------------")
print(my.__dict__)
print(my.x)
print("------------------------------------------------------------------------")
import random


class car:
    __test = 2
    def __new__(cls, *args, **kwargs):
        cls.country = 'Russia'
        return super().__new__(cls)

    def __init__(self, model=None, *, years=0):
        self.model = model
        self.years = years
        self.win = random.randint(1000, 10000)
        self.__like = 90

    def __getattribute__(self, item):
        if item == "country":
            return 'AccessError'
        return object.__getattribute__(self, item)

    def __del__(self):
        print("MERCEDES DEL:", self,  id(self))

    def see(self):
        print('Win:', self.win, '\nCar model:', self.model, '\tYears:', self.years, '\nCountry:', self.country)


class onlyOne:
    pt = None

    def __new__(cls, *args, **kwargs):
        if cls.pt is None:
            cls.pt = super(cls, onlyOne).__new__(cls)
        return cls.pt

    def __init__(self, data):
        self.data = data

    def __del__(self):
        print("CAR DEL:", self, id(self))
        self.pt = None

    def get_data(self):
        return "Data was successfully get" + self.data


Mercedes = car('S class')
print(dir(Mercedes))
print(Mercedes._car__test)
print("------------------------------------------------------------------------------------------")
print(id(Mercedes), Mercedes)
Mercedes2 = car("D class")
print(id(Mercedes), Mercedes, "\t", id(Mercedes2), Mercedes2)
print("------------------------------------------------------------------------------------------")
Mercedes = "stroka"
Mercedes2 = "stroka"
test1 = onlyOne("some")
print(id(test1), test1)
test2 = onlyOne("some2")
print(id(test1), test1, "\t", id(test2), test2)
print("------------------------------------------------------------------------------------------")
print(Mercedes.__dict__)
Mercedes.__like = 23
print(Mercedes.__dict__)
Mercedes.__like = 100
print(Mercedes.__like, Mercedes.__dict__)
print("------------------------------------------------------------------------------------------")

class Unit:
    def __init__(self):
        self.xp = 100

    def attack(self):
        raise NotImplemented("Метод attack(self) обязан быть переопределен")
    # Протестить переопределение по числу параметров


class Archer(Unit):

    def __init__(self):
        super().__init__()

    def attack(self):
        print("Archer is attacking you")


class Warrior(Unit):

    def __init__(self):
        super().__init__()

    def attack(self):
        print("Warrior is attacking you")


class SuperUnit(Warrior, Archer):
    def attack(self):
        print("SUPER_UNIT is attacking fucking YOU!")


u = Unit()
print("-------------------------------------")
a = Archer()
print("-------------------------------------")
w = Warrior()
print("======================================")
su = SuperUnit()
# print(su.__dict__, SuperUnit.__mro__, sep="$\t$")
# l = [Archer(), Warrior(), SuperUnit()]
# print("-------------------------------------")
# for i in range(0, 3, 1):
#     print(l[i].__dict__)
#     # print(l[i].__dir__())
#     l[i].attack()
#     print(l[i].__sizeof__(), l[i].__dict__.__sizeof__())
print(type(u), type(a), type(w), type(su))
print(type(Unit), type(Archer), type(Warrior), type(SuperUnit))
Point1D = type('Point',(),{'Max': 100, 'Min':0})
print(type(Point1D))
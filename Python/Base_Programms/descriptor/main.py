class wirn:
    def __set_name__(self, owner, name):
        self.name = "_" + name

    def __set__(self, instance, value):
        instance.__setattr__(self.name, value)

    def __get__(self, instance, owner):
        return instance.__getattribute__(self.name)


class Point:
    x = wirn()
    y = wirn()

    def __init__(self, x, y):
        self.x = x
        self.y = y


class Counter:

    def __init__(self, start=0, stop=0, step=1):
        self.start = start
        self.stop = stop
        self.step = step

    def __iter__(self):
        self.counter = self.start - self.step
        return self

    def __next__(self):
        if self.counter + self.step < self.stop:
            self.counter += self.step
            return self.counter
        else:
            raise StopIteration


class Counter2D:

    def __init__(self, start=0, stop=0, step=1, rows=1):
        self.counter1D = Counter(start, stop, step)
        self.rows = rows

    def __iter__(self):
        self.counter = 0
        return self

    def __next__(self):
        if self.counter < self.rows:
            self.counter += 1
            return self.counter1D
        else:
            raise StopIteration


class Geom:
    def __init__(self):
        print("---------------------------------------------------------------------------")
        print(super())
        print("---------------------------------------------------------------------------")


class Line(Geom):
    pass


class Square(Geom):
    pass


g = Geom()
l = Line()
s = Square()

print(issubclass(Geom, object))
print(Line.__mro__)

# c1 = Counter2D(1,6,1,5)
# for i in c1:
#    for x in i:
#        print(x, end=" ")
#    print()

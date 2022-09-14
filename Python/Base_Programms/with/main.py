class Save:
    def __init__(self, var):
        self.__var = var

    def __enter__(self):
        self.__temp = self.__var[:]
        return self.__temp

    def __exit__(self, exc_type, exc_val, exc_tb):
        if exc_type is None:
            self.__var[:] = self.__temp
        return False

v1 = [1,2,3]
v2 = [5,4,6]

print(v1)
try:
    with Save(v1) as tv1:
        for i in range(0,len(tv1)):
            tv1[i] = v2[i]
except:
    print("Error", v1)

print(v1)


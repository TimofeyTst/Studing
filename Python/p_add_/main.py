class clock:
    def __init__(self, seconds):
        self.seconds = seconds

    def __add__(self, sec):
        self.seconds += sec

    def get_time(self):
        s = self.seconds % 60
        m = (self.seconds // 60) % 60
        h = (self.seconds // 3600) % 24
        return f"{self.__get_formatted(h)}:{self.__get_formatted(m)}:{self.__get_formatted(s)}"

    def __get_formatted(self,var):
        return str(var).rjust(2,"0")

c = clock(1000)
print(c.get_time())
c + 100
print(c.get_time())
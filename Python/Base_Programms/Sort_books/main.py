
def read(name: str):
    with open(name, 'r', encoding='utf-8') as file:
        data = []
        for el in file:
            data.append(el.strip('\n'))
        return data

def write(name: str, datas: list):
    with open(name, 'w', encoding='utf-8') as file:
        for data in datas:
            file.write(data + '\n')

if __name__ == '__main__':
    data = read('file.txt')
    print('readed')

    data.sort()
    print('sorted')

    write('file.txt', data)
    print('writed')
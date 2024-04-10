class ToSave:
    def __init__(self, s: str, num: int, num_f: float, boolean: bool) -> None:
        self.s = s
        self.num = num
        self.num_f = num_f
        self.boolean = boolean

if __name__ == '__main__':
    s = input('stringa: ')
    num = int(input('numero intero: '))
    num_float = float(input('numero decimale: '))
    boolean = bool(input('booleano: '))
    with open('prova.txt', 'w+') as f:
        f.write(s + '\n' + str(num) + '\n' + 
                str(num_float) + '\n' + str(boolean))
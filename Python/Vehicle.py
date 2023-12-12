class Vehicle:
    
    speed: float
    acceleration: float

    def __init__(self, speed = 0.0, acceleration = 0.0) -> None:
        self.speed = speed
        self.acceleration = acceleration
    
    def set_speed (self, other):
        self.speed = float(other)

    def set_acceleration (self, other):
        self.acceleration = float(other)
    
    def print_speed (self):
        print("speed: " + str(self.speed))
    
    def print_acceleration (self):
        print("acceleration: " + str(self.acceleration))
    
    @staticmethod
    def compute_speed_increment (acceleration: float, seconds: int) -> float:
        return acceleration * seconds


class Car (Vehicle):
    
    plate: str
    running: bool

    def __init__(self, plate, running = False, speed = 0.0, acceleration = 0.0) -> None:
        self.plate = plate
        self.running = running
        if running == False:
                speed = 0.0
                acceleration = 0.0
        super().__init__(speed, acceleration)
    
    def start (self):
        self.running = True
    
    def stop (self):
        self.running = False
        self.set_speed(0.0)
        self.set_acceleration(0.0)
    
    def accelerate (self, acceleration: float, seconds: int):
        if self.running == True:
            self.speed += self.compute_speed_increment(acceleration, seconds)
    
    @staticmethod
    def print_n_wheels ():
        print("The car has 4 wheels")


class Bicycle (Vehicle):

    def __init__(self, speed = 0.0, acceleration = 0.0) -> None:
        super().__init__(speed, acceleration)
    
    def pedal (self, n_hits: int, seconds: int):
        acceleration = n_hits / (seconds ** 2)
        self.set_acceleration(float(self.acceleration) + float(acceleration))
        self.set_speed(float(self.speed) + float(self.compute_speed_increment(acceleration, seconds)))

    @staticmethod
    def print_n_wheels ():
        print("The bicycle has 2 wheels")


if __name__ == '__main__':
    c = Car('ABC', False, 10, 11)
    b = Bicycle('10.1', '0')

    Car.print_n_wheels()
    b.print_n_wheels()

    b.set_speed(5)
    c.set_acceleration(1)
    print("\n - Car c ----------")
    c.print_speed()
    c.print_acceleration()
    print("\n - Bicycle b ------")
    b.print_speed()
    b.print_acceleration()
    print("\n ------------------")

    c.start()
    c.accelerate(10.1, 2)
    b.pedal(2, 5)
    print("\n - Car c ----------")
    c.print_speed()
    c.print_acceleration()
    print("\n - Bicycle b ------")
    b.print_speed()
    b.print_acceleration()

    print("\n ------------------")
    c.stop()
    print("\n - Car c ----------")
    c.print_speed()
    c.print_acceleration()
    print("\n - Bicycle b ------")
    b.print_speed()
    b.print_acceleration()
    print("\n ------------------\n")
'''
Python modelling of a Car and a Motorbike with default values for each and an additional property for the motorbike
'''

class Vehicle():
    def __init__(self, number_plate, vehicle_length, num_wheels, total_passangers):
            self.number_plate = number_plate
            self.num_wheels = num_wheels
            self.vehicle_length = vehicle_length
            self.total_passangers = total_passangers
        
    def get_plate(self):
        return print(f'The number plate is {self.number_plate}')
    
    def get_wheels(self):
        return print(f'There are {self.num_wheels} wheels')
    
    def get_length(self):
        print(f'This vehicle is {self.vehicle_length}metres')
    
    def get_passangers(self):
        print(f' There are {self.total_passangers} passangers')
    
class Car(Vehicle):
    def __init__(self, number_plate, vehicle_length, num_wheels=4, total_passangers=5):
        super().__init__(number_plate, vehicle_length, num_wheels, total_passangers)

class Motorbike(Vehicle):
    def __init__(self, number_plate, vehicle_length, bike_type, num_wheels=2, total_passangers=2):
        super().__init__(number_plate, vehicle_length, num_wheels, total_passangers)
        self.bike_type = bike_type
        assert self.bike_type in ["cruiser", "moped", "sports bike"]  # Bike must be one of three types
    
    # set Motorbike to cruiser, moped or sports bike
    def change_type(self, instance_type):
        assert instance_type in ["cruiser", "moped", "sports bike"]
        self.bike_type = instance_type
    
    def get_type(self):
        print(f'This is a {self.bike_type}')
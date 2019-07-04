#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std; 

//Degine each spot

class ParkingSpots{
	Vehicle vehicle;
	VehicleSize spotsize; 
	int row; 
	int spotNum;
	Level level; 
	ParkingSpots();
	bool isAvailable()
	bool CanFit(Vehicle vehicle);
	bool park(Vehicle vehicle);
	void RemoveVehicle(Vehicle vehicle);
};

// Design each level 

class Level{
	int floor; 
	ParkingSpots spot[];
	int available = 0;
	int SPOTS_PER_ROW =10; 
	Level(int flr, int numOfSpots){....};
	int availableSpot(){
		return available;
	}
	bool parkVehicle(Vehicle vehicle){...}
	int findSpot(Vehicle vehicle);
	void freeSpot(Vehicle vehicle);
};

//Design the whole parking lot

class ParkingLot{
	Level levels[];
	int NUM_LEVELS = 5; 
public:
	bool parkVehicle(Vehicle vehicle); // find a spot for car
};

//Design a vehicle
enum vehcileSize
{
	Motorcycle, Sedan, Bus;
};
class Vehicle{
	vector<ParkingSpots> spot;
	string license; 
	int spotsNeeded; 
	VehicleSize size; 
	int spotsNeeded(){
		return spotsNeeded;
	}
	vehcileSize getsize(){
		return size;
	}
	void park(ParkingSpots p){
		spot.push_back(p);
	}
	void clearSpot();
	virtual bool canFit(ParkingSpots p);
};

class Bus: public vehicle{
	Bus(){
		spotsNeeded = 4;
		size =vehcileSize.Bus;
	}
	bool CanFit(ParkingSpots p){....}
}

class sedan: public vehicle{
	Bus(){
		spotsNeeded = 1;
		size =vehcileSize.Sedan;
	}
	bool CanFit(ParkingSpots p){....}
}

class Motorcycle: public vehicle{
	Bus(){
		spotsNeeded = 4;
		size =vehcileSize.Motorcycle;
	}
	bool CanFit(ParkingSpots p){....}
}

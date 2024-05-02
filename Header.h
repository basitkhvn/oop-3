#pragma once

/*
Name: Abdul Basit 
Roll No : 23I-0820
Section : F
Instructor : Marium Hida
TA name : Ariyan Choudhary
*/

#include <iostream>
using namespace std;

class ALU {
private:
	int NoOfAdders;
	int NoOfSubtractor;
	int NoOfRegisters;
	int sizeOfRegisters;

public:

	ALU() {
		NoOfAdders = 0;
		NoOfRegisters = 0;
		NoOfSubtractor = 0;
		sizeOfRegisters = 0;
	
	}
	
	ALU(int add , int sub , int reg , int sizeofreg) {
	
		NoOfAdders = add;
		NoOfSubtractor = sub;
		NoOfRegisters = reg;
		sizeOfRegisters = sizeofreg;

	
	}

	// Getters 
	int getNoOfAdders() const { return NoOfAdders; }
	int getNoOfSubtractors() const { return NoOfSubtractor; }
	int getNoOfRegisters() const { return NoOfRegisters; }
	int getSizeOfRegisters() const { return sizeOfRegisters; }

	// Setters 
	void setNoOfAdders(int adders) { NoOfAdders = adders; }
	void setNoOfSubtractors(int subtractors) { NoOfSubtractor = subtractors; }
	void setNoOfRegisters(int registers) { NoOfRegisters = registers; }
	void setSizeOfRegisters(int regSize) { sizeOfRegisters = regSize; }

};

class ControlUnit {
private:
	float clock;

public:

	ControlUnit() {
		clock = 0;
	}

	ControlUnit(float cl) {
		clock = cl;
	}

	//getter

	float getclock() const { return clock; }
	//setter

	void setclock(float c) { clock = c; }
};

class CPU {
private:
	ALU alu;
	ControlUnit cu;

public:

	CPU() : alu(), cu() {};

	CPU(int add, int sub, int reg, int regsize, float cl) : alu(add, sub, reg, regsize), cu(cl) {};

//getters

	ALU getalu() {
		return alu;
	}

	ControlUnit getcu() {
		return cu;
	}

//setters
	void setalu(ALU& temp) {
		alu = temp;
	}

	void setcu(ControlUnit& temp) {
		cu = temp;
	}


};

class MainMemory {
private:
	int capacity;
	string technologyType;

public:

	MainMemory() {
		capacity = 0;
		technologyType = "\0";

	}
	
	MainMemory(int cap, string tech) {
		capacity = cap;
		technologyType = tech;
	}
	
	//getter 

	int getcap() {
		return capacity;
	}
	string getstr() {
		return technologyType;
	}

	//setter
	void setcap(int cap) {
		capacity = cap;
	}
	void setstr(string temp) {
		technologyType = temp;
	}

};

class Port {
private:
	string type;
	int baud_rate;

public:
	// Constructor initializing the attributes with default parameters
	Port() : type("\0"), baud_rate(0) {}

	// Overloaded constructor initializing the attributes with provided values
	Port(const string& portType, int rate) : type(portType), baud_rate(rate) {}

	// Getter for port type
	string getType() const {
		return type;
	}

	// Setter for port type
	void setType(const string& portType) {
		type = portType;
	}

	// Getter for baud rate
	int getBaudRate() const {
		return baud_rate;
	}

	// Setter for baud rate
	void setBaudRate(int rate) {
		baud_rate = rate;
	}
};

class MotherBoard {

private:
	MainMemory mm;
	Port* arr;

public:

	MotherBoard() {
		mm.setcap(0);
		mm.setstr("\0");
		arr = new Port[5];

		for (int i = 0; i < 5; i++) {
			arr[i].setBaudRate(0);
			arr[i].setType("\0");
		}
	}

	MotherBoard(int cap, string str, int size, Port* arr2) {
		mm.setcap(cap);
		mm.setstr(str);
		arr = new Port[size];

		for (int i = 0; i < size; i++) {
			arr[i].setBaudRate(arr2[i].getBaudRate());
			arr[i].setType(arr2[i].getType());
		}
	}
	//getter 

	MainMemory getmm() {
		return mm;
	}

	Port* getPort() {
		return arr;

	}

	//setter 
	void setmm(MainMemory& m) {
		mm = m;
	}
	void setPort(Port* a)
	{
		arr = a;

	}

};
	

class PhysicalMemory {
private:
	int capacity;
public:

	PhysicalMemory() {
		capacity = 0;
	}
	PhysicalMemory(int c) {
		capacity = c;
	}

	//getter

	int getcap(){
		return capacity;
	}

	//setter

	void setcap(int c) {
		capacity = c;

	}
};

class Computer {
private:
	PhysicalMemory * pm;
	MotherBoard *mb;
	CPU *cpu;

public:

	Computer() {
		pm = NULL;
		mb = NULL;
		cpu = NULL;

	}
	Computer(PhysicalMemory* p, MotherBoard* m, CPU* c) {
		pm = p;
		mb = m;
		cpu = c;
	
	}
	//getter 
	PhysicalMemory* getpm() {
		return pm;
	}
	MotherBoard* getmb() {
		return mb;
	}
	CPU* getcpu() {
		return cpu;
	}
	//setter

	void setpm(PhysicalMemory* p) {
		pm = p;
	}

	void setmb(MotherBoard * m) {
		mb = m;
	}
	void setcpu(CPU* c) {
		cpu = c;
	}
};

class GraphicsCard {
private:
	string brand;
	int memorySize;
	double price;

public:
	
	GraphicsCard() : brand(""), memorySize(0), price(0.0) {}

	
	GraphicsCard(const string& b, int memSize, double p) : brand(b), memorySize(memSize), price(p) {}

	
	string getBrand() const { return brand; }
	int getMemorySize() const { return memorySize; }
	double getPrice() const { return price; }

	
	void setBrand(const string& b) { brand = b; }
	void setMemorySize(int memSize) { memorySize = memSize; }
	void setPrice(double p) { price = p; }
};

class StorageDevice {
private:
	string type;
	int capacity;
	double price;

public:
	// Constructor initializing the attributes with default parameters
	StorageDevice() : type(""), capacity(0), price(0.0) {}

	// Constructor initializing the attributes with Overloaded Constructors
	StorageDevice(const string& t, int cap, double p) : type(t), capacity(cap), price(p) {}

	// Getters
	string getType() const { return type; }
	int getCapacity() const { return capacity; }
	double getPrice() const { return price; }

	// Setters
	void setType(const string& t) { type = t; }
	void setCapacity(int cap) { capacity = cap; }
	void setPrice(double p) { price = p; }
};

class NetworkCard {
private:
	string type;
	int speed;
	double price;

public:
	
	NetworkCard() : type(""), speed(0), price(0.0) {}

	
	NetworkCard(const string& t, int s, double p) : type(t), speed(s), price(p) {}

	// Getters
	string getType() const { return type; }
	int getSpeed() const { return speed; }
	double getPrice() const { return price; }

	// Setters
	void setType(const string& t) { type = t; }
	void setSpeed(int s) { speed = s; }
	void setPrice(double p) { price = p; }
};

class PowerSupply {
private:
	int wattage;
	string efficiencyRating;
	double price;

public:
	
	PowerSupply() : wattage(0), efficiencyRating(""), price(0.0) {}

	
	PowerSupply(int w, const string& rating, double p) : wattage(w), efficiencyRating(rating), price(p) {}

	// Getters
	int getWattage() const { return wattage; }
	string getEfficiencyRating() const { return efficiencyRating; }
	double getPrice() const { return price; }

	// Setters
	void setWattage(int w) { wattage = w; }
	void setEfficiencyRating(const string& rating) { efficiencyRating = rating; }
	void setPrice(double p) { price = p; }
};

class Battery {
private:
	int capacity;

public:
	
	Battery() : capacity(0) {}


	Battery(int cap) : capacity(cap) {}

	// Getter 
	int getCapacity() const { return capacity; }

	// Setter 
	void setCapacity(int cap) { capacity = cap; }
};



class Case {
private:
	string formFactor;
	string color;
	double price;

public:
	
	Case() : formFactor(""), color(""), price(0.0) {}

	
	Case(const string& form, const string& col, double p) : formFactor(form), color(col), price(p) {}

	// Getters
	string getFormFactor() const { return formFactor; }
	string getColor() const { return color; }
	double getPrice() const { return price; }

	// Setters
	void setFormFactor(const string& form) { formFactor = form; }
	void setColor(const string& col) { color = col; }
	void setPrice(double p) { price = p; }
};

class ComputerAssembly : public Computer {
protected:
	double totalPrice;


public:
	ComputerAssembly() {
		totalPrice = 0.0;
	}

	ComputerAssembly(double t) {
		totalPrice = t;

	}
	//getter 
	double	getCA() {
		return totalPrice;
	}

	void setCA(double tt) {
		totalPrice = tt;
	}



	
};

class PC : public ComputerAssembly {
private :
	Case* c;
	Battery* b;
	PowerSupply* p;
	NetworkCard* n;
	GraphicsCard* g;
	StorageDevice* s;
	PhysicalMemory* pm;
	MainMemory* mm;
	CPU* cpu;
	Port* ports;
public:

	PC() {
		c = new Case();
		b = new Battery();
		p = new PowerSupply();
		n = new NetworkCard();
		g = new GraphicsCard();
		s = new StorageDevice();
		pm = nullptr; // Allocate memory when getting specs
		mm = new MainMemory(); // Allocate memory when getting specs
		cpu = nullptr; // Allocate memory when getting specs
		ports = new Port[5];
	}


	void getComputerSpecs() {
		// Get specifications for Physical Memory
		int pmCapacity;
		cout << "Enter Physical Memory Capacity (in GB): ";
		cin >> pmCapacity;
		pm = new PhysicalMemory(pmCapacity);

		// Get specifications for MotherBoard
		int mb;
		string mbTech;
		cout << "Enter Main Memory Capacity (in GB): ";
		cin >> mb;
		cout << "Enter Main Memory Technology (e.g., DDR3, DDR4): ";
		cin >> mbTech;
		mm->setcap(mb);
		mm->setstr(mbTech);

		// Get specifications for Ports
		ports = new Port[5]; // Assuming 5 ports
		for (int i = 0; i < 5; ++i) {
			string portType;
			int baudRate;
			cout << "Enter Type of Port " << i + 1 << ": ";
			cin >> portType;
			cout << "Enter Baud Rate for Port " << i + 1 << ": ";
			cin >> baudRate;
			ports[i].setType(portType);
			ports[i].setBaudRate(baudRate);
		}



		// Get specifications for CPU
		int adders, subtractors, registers, regSize;
		float clock;
		cout << "Enter Number of Adders: ";
		cin >> adders;
		cout << "Enter Number of Subtractors: ";
		cin >> subtractors;
		cout << "Enter Number of Registers: ";
		cin >> registers;
		cout << "Enter Size of Registers: ";
		cin >> regSize;
		cout << "Enter Clock Speed (in GHz): ";
		cin >> clock;
		cpu = new CPU(adders, subtractors, registers, regSize, clock);

		// Get specifications for ControlUnit
		float cuClock;
		cout << "Enter Control Unit Clock Speed (in GHz): ";
		cin >> cuClock;
		ControlUnit cu(cuClock);





		// Get specifications for GraphicsCard
		string brand;
		int memorySize;
		double price;
		cout << "Enter Graphics Card Brand: ";
		cin >> brand;
		cout << "Enter Graphics Card Memory Size (in GB): ";
		cin >> memorySize;
		cout << "Enter Graphics Card Price: ";
		cin >> price;
		totalPrice += price;
		g->setBrand(brand);
		g->setMemorySize(memorySize),
			g->setPrice(price);

		// Get specifications for StorageDevice
		string type;
		int capacity;
		double storagePrice;
		cout << "Enter Storage Device Type: ";
		cin >> type;
		cout << "Enter Storage Device Capacity (in GB): ";
		cin >> capacity;
		cout << "Enter Storage Device Price: ";
		cin >> storagePrice;
		totalPrice += storagePrice;
		s->setCapacity(capacity);
		s->setPrice(storagePrice);
		s->setType(type);
		// Get specifications for NetworkCard
		string netType;
		int speed;
		double netPrice;
		cout << "Enter Network Card Type: ";
		cin >> netType;
		cout << "Enter Network Card Speed (in Mbps): ";
		cin >> speed;
		cout << "Enter Network Card Price: ";
		cin >> netPrice;
		totalPrice += netPrice;
		n->setPrice(netPrice);
		n->setType(netType);
		n->setSpeed(speed);

		// Get specifications for PowerSupply
		int watt;
		string rating;
		double pricepsu;
		cout << "Enter Power Supply Wattage: ";
		cin >> watt;
		cout << "Enter Power Supply Efficiency Rating: ";
		cin >> rating;
		cout << "Enter Power Supply Price: ";
		cin >> pricepsu;
		totalPrice += pricepsu;
		p->setEfficiencyRating(rating);
		p->setPrice(pricepsu);
		p->setWattage(watt);

		// Get specifications for Battery
		int cap;
		cout << "Enter Battery Capacity (in mAh): ";
		cin >> cap;
		b->setCapacity(cap);

		// Get specifications for Case
		string form, color;
		double casep;
		cout << "Enter Case Form Factor: ";
		cin >> form;
		cout << "Enter Case Color: ";
		cin >> color;
		cout << "Enter Case Price: ";
		cin >> casep;

		totalPrice += casep;
		c->setColor(color);
		c->setFormFactor(form);
		c->setPrice(casep);

		// Construct the Computer object
		setpm(pm);
		MotherBoard* mbPtr = new MotherBoard(mb, mbTech, 5, ports);
		setmb(mbPtr);
		CPU* cpuPtr = new CPU(adders, subtractors, registers, regSize, clock);
		cpuPtr->setcu(cu);
		setcpu(cpuPtr);
	}

	// Function to display computer specifications and price
	void displayComputerSpecsAndPrice() {
		cout << "Computer Specifications:\n";
		cout << "Physical Memory Capacity: " << getpm()->getcap() << " GB" << endl;
		cout << "Main Memory Capacity: " << getmb()->getmm().getcap() << " GB" << endl;
		cout << "Main Memory Technology: " << getmb()->getmm().getstr() << endl;
		cout << "CPU Details:\n";
		cout << "Number of Adders: " << getcpu()->getalu().getNoOfAdders() << endl;
		cout << "Number of Subtractors: " << getcpu()->getalu().getNoOfSubtractors() << endl;
		cout << "Number of Registers: " << getcpu()->getalu().getNoOfRegisters() << endl;
		cout << "Size of Registers: " << getcpu()->getalu().getSizeOfRegisters() << endl;
		cout << "Clock Speed: " << getcpu()->getcu().getclock() << " GHz" << endl;
		cout << "Ports:\n";
		Port* ports = getmb()->getPort();
		for (int i = 0; i < 5; ++i) {
			cout << "Port " << i + 1 << " Type: " << ports[i].getType() << endl;
			cout << "Port " << i + 1 << " Baud Rate: " << ports[i].getBaudRate() << endl;
		}
		cout << "Graphics Card Details:\n";
		cout << "Brand: " <<g->getBrand() << endl;
		cout << "Memory Size: " << g->getMemorySize() << " GB" << endl;
		cout << "Price: $" << g->getPrice() << endl;
		cout << "Storage Device Details:\n";
		cout << "Type: " << s->getType() << endl;
		cout << "Capacity: " << s->getCapacity() << " GB" << endl;
		cout << "Price: $" << s->getPrice() << endl;
		cout << "Network Card Details:\n";
		cout << "Type: " << n->getType() << endl;
		cout << "Speed: " << n->getSpeed() << " Mbps" << endl;
		cout << "Price: $" << n->getPrice() << endl;
		cout << "Power Supply Details:\n";
		cout << "Wattage: " << p->getWattage() << " W" << endl;
		cout << "Efficiency Rating: " << p->getEfficiencyRating() << endl;
		cout << "Price: $" << p->getPrice() << endl;
		cout << "Battery Details:\n";
		cout << "Capacity: " << b->getCapacity() << " mAh" << endl;
		cout << "Case Details:\n";
		cout << "Form Factor: " << c->getFormFactor() << endl;
		cout << "Color: " << c->getColor() << endl;
		cout << "Price: $" << c->getPrice() << endl;
		cout << "Total Price: $" << getCA() << endl;
	}
};






class MAC : public ComputerAssembly {
private:
	Case* c;
	Battery* b;
	PowerSupply* p;
	NetworkCard* n;
	GraphicsCard* g;
	StorageDevice* s;
	PhysicalMemory* pm;
	MainMemory* mm;
	CPU* cpu;
	Port* ports;
public:

	MAC() {
		
			c = new Case();
			b = new Battery();
			p = new PowerSupply();
			n = new NetworkCard();
			g = new GraphicsCard();
			s = new StorageDevice();
			pm = nullptr; // Allocate memory when getting specs
			mm = new MainMemory(); // Allocate memory when getting specs
			cpu = nullptr; // Allocate memory when getting specs
			ports = new Port[5];
		


	}

	void getComputerSpecs() {
		// Get specifications for Physical Memory
		int pmCapacity;
		cout << "Enter Physical Memory Capacity (in GB): ";
		cin >> pmCapacity;
	 pm = new PhysicalMemory(pmCapacity);

		// Get specifications for MotherBoard
		int mb;
		string mbTech;
		cout << "Enter Main Memory Capacity (in GB): ";
		cin >> mb;
		cout << "Enter Main Memory Technology (e.g., DDR3, DDR4): ";
		cin >> mbTech;
		mm->setcap(mb);
			 mm->setstr(mbTech);

			 // Get specifications for Ports
			 ports = new Port[5]; // Assuming 5 ports
			 for (int i = 0; i < 5; ++i) {
				 string portType;
				 int baudRate;
				 cout << "Enter Type of Port " << i + 1 << ": ";
				 cin >> portType;
				 cout << "Enter Baud Rate for Port " << i + 1 << ": ";
				 cin >> baudRate;
				 ports[i].setType(portType);
				 ports[i].setBaudRate(baudRate);
			 }

			 

		// Get specifications for CPU
		int adders, subtractors, registers, regSize;
		float clock;
		cout << "Enter Number of Adders: ";
		cin >> adders;
		cout << "Enter Number of Subtractors: ";
		cin >> subtractors;
		cout << "Enter Number of Registers: ";
		cin >> registers;
		cout << "Enter Size of Registers: ";
		cin >> regSize;
		cout << "Enter Clock Speed (in GHz): ";
		cin >> clock;
		 cpu = new CPU(adders, subtractors, registers, regSize, clock);

		// Get specifications for ControlUnit
		float cuClock;
		cout << "Enter Control Unit Clock Speed (in GHz): ";
		cin >> cuClock;
		ControlUnit cu(cuClock);

		

	

		// Get specifications for GraphicsCard
		string brand;
		int memorySize;
		double price;
		cout << "Enter Graphics Card Brand: ";
		cin >> brand;
		cout << "Enter Graphics Card Memory Size (in GB): ";
		cin >> memorySize;
		cout << "Enter Graphics Card Price: ";
		cin >> price;
		g->setBrand(brand);
		g->setMemorySize(memorySize), 
			g->setPrice(price);

		// Get specifications for StorageDevice
		string type;
		int capacity;
		double storagePrice;
		cout << "Enter Storage Device Type: ";
		cin >> type;
		cout << "Enter Storage Device Capacity (in GB): ";
		cin >> capacity;
		cout << "Enter Storage Device Price: ";
		cin >> storagePrice;
		s->setCapacity(capacity);
		s->setPrice(storagePrice);
		s->setType(type);
		// Get specifications for NetworkCard
		string netType;
		int speed;
		double netPrice;
		cout << "Enter Network Card Type: ";
		cin >> netType;
		cout << "Enter Network Card Speed (in Mbps): ";
		cin >> speed;
		cout << "Enter Network Card Price: ";
		cin >> netPrice;
		n->setPrice(netPrice);
		n->setType(netType);
		n->setSpeed(speed);

		// Get specifications for PowerSupply
		int watt;
		string rating;
		double pricepsu;
		cout << "Enter Power Supply Wattage: ";
		cin >> watt;
		cout << "Enter Power Supply Efficiency Rating: ";
		cin >> rating;
		cout << "Enter Power Supply Price: ";
		cin >> pricepsu;
		p->setEfficiencyRating(rating);
		p->setPrice(pricepsu);
		p->setWattage(watt);

		// Get specifications for Battery
		int cap;
		cout << "Enter Battery Capacity (in mAh): ";
		cin >> cap;
		b->setCapacity(cap);

		// Get specifications for Case
		string form, color;
		double casep;
		cout << "Enter Case Form Factor: ";
		cin >> form;
		cout << "Enter Case Color: ";
		cin >> color;
		cout << "Enter Case Price: ";
		cin >> casep;
		c->setColor(color);
		c->setFormFactor(form);
		c->setPrice(casep);

		// Construct the Computer object
		setpm(pm);
		MotherBoard* mbPtr = new MotherBoard(mb, mbTech, 5, ports);
		setmb(mbPtr);
		CPU* cpuPtr = new CPU(adders, subtractors, registers, regSize, clock);
		cpuPtr->setcu(cu);
		setcpu(cpuPtr);
	}

	// Function to display computer specifications and price
	void displayComputerSpecsAndPrice() {
		cout << "Computer Specifications:\n";
		cout << "Physical Memory Capacity: " << getpm()->getcap() << " GB" << endl;
		cout << "Main Memory Capacity: " << getmb()->getmm().getcap() << " GB" << endl;
		cout << "Main Memory Technology: " << getmb()->getmm().getstr() << endl;
		cout << "CPU Details:\n";
		cout << "Number of Adders: " << getcpu()->getalu().getNoOfAdders() << endl;
		cout << "Number of Subtractors: " << getcpu()->getalu().getNoOfSubtractors() << endl;
		cout << "Number of Registers: " << getcpu()->getalu().getNoOfRegisters() << endl;
		cout << "Size of Registers: " << getcpu()->getalu().getSizeOfRegisters() << endl;
		cout << "Clock Speed: " << getcpu()->getcu().getclock() << " GHz" << endl;
		cout << "Ports:\n";
		Port* ports = getmb()->getPort();
		for (int i = 0; i < 5; ++i) {
			cout << "Port " << i + 1 << " Type: " << ports[i].getType() << endl;
			cout << "Port " << i + 1 << " Baud Rate: " << ports[i].getBaudRate() << endl;
		}
		cout << "Graphics Card Details:\n";
		cout << "Brand: " << g->getBrand() << endl;
		cout << "Memory Size: " << g->getMemorySize() << " GB" << endl;
		cout << "Price: $" << g->getPrice() << endl;
		cout << "Storage Device Details:\n";
		cout << "Type: " << s->getType() << endl;
		cout << "Capacity: " << s->getCapacity() << " GB" << endl;
		cout << "Price: $" << s->getPrice() << endl;
		cout << "Network Card Details:\n";
		cout << "Type: " << n->getType() << endl;
		cout << "Speed: " << n->getSpeed() << " Mbps" << endl;
		cout << "Price: $" << n->getPrice() << endl;
		cout << "Power Supply Details:\n";
		cout << "Wattage: " << p->getWattage() << " W" << endl;
		cout << "Efficiency Rating: " << p->getEfficiencyRating() << endl;
		cout << "Price: $" << p->getPrice() << endl;
		cout << "Battery Details:\n";
		cout << "Capacity: " << b->getCapacity() << " mAh" << endl;
		cout << "Case Details:\n";
		cout << "Form Factor: " << c->getFormFactor() << endl;
		cout << "Color: " << c->getColor() << endl;
		cout << "Price: $" << c->getPrice() << endl;
		cout << "Total Price: $" << getCA() << endl;
	}
};




#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
struct Vehicle {
    string licensePlate;
    string vehicleType;
    time_t entryTime;
    int slotNumber;
};

priority_queue<int, vector<int>, greater<int>> minHeap;
map<int, bool> slotStatus;
map<int, Vehicle> parkedVehicles;
map<string, int> licenseToSlot;

void initializeSlots(int n) {
    for (int i = 1; i <= n; ++i) {
        minHeap.push(i);
        slotStatus[i] = false;
    }
}

int assignSlot() {
    if (minHeap.empty()) return -1;
    int slot = minHeap.top();
    minHeap.pop();
    slotStatus[slot] = true;
    return slot;
}

void releaseSlot(int slot) {
    if (slotStatus[slot]) {
        minHeap.push(slot);
        slotStatus[slot] = false;
        if (parkedVehicles.find(slot) != parkedVehicles.end()) {
            licenseToSlot.erase(parkedVehicles[slot].licensePlate);
            parkedVehicles.erase(slot);
        }
    }
}

void parkVehicle(string licensePlate, string vehicleType) {
    if (licenseToSlot.find(licensePlate) != licenseToSlot.end()) {
        cout << "Vehicle with license plate " << licensePlate << " is already parked!\n";
        return;
    }
    
    int slot = assignSlot();
    if (slot == -1) {
        cout << "No available slots!\n";
        return;
    }
    
    Vehicle vehicle;
    vehicle.licensePlate = licensePlate;
    vehicle.vehicleType = vehicleType;
    vehicle.entryTime = time(nullptr);
    vehicle.slotNumber = slot;
    
    parkedVehicles[slot] = vehicle;
    licenseToSlot[licensePlate] = slot;
    
    cout << "Vehicle parked at slot: " << slot << endl;
    cout << "Entry time: " << ctime(&vehicle.entryTime);
}

void releaseVehicle(string licensePlate) {
    if (licenseToSlot.find(licensePlate) == licenseToSlot.end()) {
        cout << "Vehicle with license plate " << licensePlate << " not found!\n";
        return;
    }
    
    int slot = licenseToSlot[licensePlate];
    Vehicle vehicle = parkedVehicles[slot];
    
    time_t currentTime = time(nullptr);
    double duration = difftime(currentTime, vehicle.entryTime);
    int hours = (int)(duration / 3600);
    int minutes = (int)((duration - hours * 3600) / 60);
    
    cout << "Vehicle " << licensePlate << " released from slot " << slot << endl;
    cout << "Parking duration: " << hours << " hours " << minutes << " minutes\n";
    
    releaseSlot(slot);
}

void displaySlots(int n) {
    cout << "\nCurrent Parking Slot Status:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Slot " << i << ": ";
        if (slotStatus[i]) {
            Vehicle vehicle = parkedVehicles[i];
            cout << "Occupied by " << vehicle.licensePlate << " (" << vehicle.vehicleType << ")";
            time_t currentTime = time(nullptr);
            double duration = difftime(currentTime, vehicle.entryTime);
            int hours = (int)(duration / 3600);
            int minutes = (int)((duration - hours * 3600) / 60);
            cout << " - Duration: " << hours << "h " << minutes << "m";
        } else {
            cout << "Available";
        }
        cout << endl;
    }
    cout << endl;
}

void saveData() {
    ofstream file("parking_data.txt");
    if (file.is_open()) {
        file << parkedVehicles.size() << endl;
        for (auto& pair : parkedVehicles) {
            Vehicle v = pair.second;
            file << v.slotNumber << " " << v.licensePlate << " " << v.vehicleType << " " << v.entryTime << endl;
        }
        file.close();
    }
}

void loadData() {
    ifstream file("parking_data.txt");
    if (file.is_open()) {
        int count;
        file >> count;
        for (int i = 0; i < count; i++) {
            Vehicle v;
            file >> v.slotNumber >> v.licensePlate >> v.vehicleType >> v.entryTime;
            parkedVehicles[v.slotNumber] = v;
            licenseToSlot[v.licensePlate] = v.slotNumber;
            slotStatus[v.slotNumber] = true;
        }
        file.close();
    }
}

int main() {
    int totalSlots = 20;  // Increased capacity
    initializeSlots(totalSlots);
    loadData(); // Load existing data

    int choice;
    string licensePlate, vehicleType;
    
    while (true) {
        cout << "\n=== PARKING MANAGEMENT SYSTEM ===" << endl;
        cout << "1. Park a Vehicle" << endl;
        cout << "2. Release a Vehicle" << endl;
        cout << "3. Display Slot Status" << endl;
        cout << "4. Find Vehicle by License Plate" << endl;
        cout << "5. Show Statistics" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter license plate: ";
                cin >> licensePlate;
                cout << "Enter vehicle type (Car/Motorcycle/Truck): ";
                cin >> vehicleType;
                parkVehicle(licensePlate, vehicleType);
                saveData();
                break;
            }
            case 2: {
                cout << "Enter license plate to release: ";
                cin >> licensePlate;
                releaseVehicle(licensePlate);
                saveData();
                break;
            }
            case 3: {
                displaySlots(totalSlots);
                break;
            }
            case 4: {
                cout << "Enter license plate to find: ";
                cin >> licensePlate;
                if (licenseToSlot.find(licensePlate) != licenseToSlot.end()) {
                    int slot = licenseToSlot[licensePlate];
                    Vehicle vehicle = parkedVehicles[slot];
                    cout << "Vehicle found at slot " << slot << endl;
                    cout << "Type: " << vehicle.vehicleType << endl;
                    cout << "Entry time: " << ctime(&vehicle.entryTime);
                } else {
                    cout << "Vehicle not found!" << endl;
                }
                break;
            }
            case 5: {
                int occupied = parkedVehicles.size();
                int available = totalSlots - occupied;
                cout << "\n=== PARKING STATISTICS ===" << endl;
                cout << "Total slots: " << totalSlots << endl;
                cout << "Occupied slots: " << occupied << endl;
                cout << "Available slots: " << available << endl;
                cout << "Occupancy rate: " << fixed << setprecision(1) 
                     << (double)occupied/totalSlots*100 << "%" << endl;
                break;
            }
            case 6: {
                saveData();
                cout << "Data saved. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    return 0;
}

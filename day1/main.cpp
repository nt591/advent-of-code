#include <fstream>
#include <iostream>
using namespace std;

int getFuelRequirements(int mass) {
  return (mass / 3) - 2;
}

int inputFuelRequirement() {
  int fuelSum = 0;
  string line;
  ifstream file("input.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      int fuel = getFuelRequirements(stoi(line));
      fuelSum += fuel;
    }
    file.close();
  }

  return fuelSum;
}

int addedFuelRequirement() {
  int fuelSum = 0;
  string line;
  ifstream file("input.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      int fuel = stoi(line);
      cout << "Fuel line is: " << fuel << endl;
      int toAdd = fuel;
      while (getFuelRequirements(toAdd) > 0) {
        toAdd = getFuelRequirements(toAdd);
        cout << "To add: " << toAdd << endl;
        fuelSum += toAdd;
      }
    }
    file.close();
  }

  return fuelSum;
}

int main() {
  int fuelReq = inputFuelRequirement();
  int totalReq = addedFuelRequirement();
  cout << "Part 1: Fuel sum is: " << fuelReq << endl;
  cout << "Part 2: Total sum is: " << totalReq << endl;

  return 0;
}
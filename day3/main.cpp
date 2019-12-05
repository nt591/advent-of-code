#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

class Point {
  public:
    Point (int x, int y) {
      x = x;
      y = y;
    }

    Point() {
      x = 0;
      y = 0;
    }
    int x;
    int y;

    int getDistance() {
      return x + y;
    }
};

vector<vector<string> > parseInput() {
  string line;
  ifstream file("input.txt");

  vector<vector<string> > array;
  array.clear();

  if (file.is_open()) {
    while (getline(file, line)) {
      stringstream buffer(line);
      vector<string> vect;
      while( buffer.good() ) {
          string substr;
          getline( buffer, substr, ',' );
          vect.push_back(substr);
      }

      array.push_back(vect);
    }
  }

  return array;
}

Point calculateNewPoint(Point oldPoint, char direction, int distance) {
  cout << distance << endl;
  cout << "X: " << oldPoint.x << endl;
  cout << "Y: " << oldPoint.y << endl;
  switch (direction) {
    case 'U':
      cout << "U" << endl;
      // cout << oldPoint.y + distance << endl;
      return Point(oldPoint.x, oldPoint.y + distance);
    case 'D':
      cout << "D" << endl;
      // cout << oldPoint.y - distance << endl;
      return Point(oldPoint.x, oldPoint.y - distance);
    case 'R':
      cout << "R" << endl;
      // cout << oldPoint.x + distance << endl;
      return Point(oldPoint.x + distance, oldPoint.y);
    case 'L':
      cout << "L" << endl;
      // cout << oldPoint.x - distance << endl;
      return Point(oldPoint.x - distance, oldPoint.y);
    default:
      cout << "ERROR ON CALCULATE NEW POINT" << endl;
      return oldPoint;
  }
}

vector<Point> generateLine(vector<vector<string> > input, int index) {
  vector<string> line = input.at(index);
  Point oldPoint = Point();
  vector<Point> coll;

  for (string inputString : line) {
    char direction = inputString[0];
    int distance = stoi(inputString.substr(1));
    Point newPoint = calculateNewPoint(oldPoint, direction, distance);
    coll.push_back(newPoint);
    oldPoint = newPoint;
  }

  return coll;
}

int main() {
  vector<vector<string> > input = parseInput();
  vector<Point> firstWirePath = generateLine(input, 0);
  vector<Point> secondWirePath = generateLine(input, 1);

  cout << "FIRST WIRE FIRST X : " << firstWirePath.at(0).x << endl;
  cout << "FIRST WIRE FIRST y : " << firstWirePath.at(0).y << endl;
  return 0;
}
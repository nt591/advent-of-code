#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

vector<int>* parseInput() {
  static vector<int> opcodes;
  opcodes.clear();
  ifstream t("input.txt");
  stringstream buffer;
  buffer << t.rdbuf();

  // the entire file is in the buffer string, now to loop over each element
  for (int i; buffer >> i;) {
    opcodes.push_back(i);
    if (buffer.peek() == ',') buffer.ignore();
  }
  return &opcodes;
}

int calculateOpcodes(int a, int b) {
  vector<int>* opcodes = parseInput();
  opcodes->at(1) = a;
  opcodes->at(2) = b;

  for (size_t i = 0; i < opcodes->size(); i += 4) {
    int code = opcodes->at(i);
    int op1pos = opcodes->at(i + 1);
    int op2pos = opcodes->at(i + 2);
    int resultPos = opcodes->at(i + 3);
    if (code == 1) {
      opcodes->at(resultPos) = opcodes->at(op1pos) + opcodes->at(op2pos);
    } else if (code == 2) {
      opcodes->at(resultPos) = opcodes->at(op1pos) * opcodes->at(op2pos);
    } else {
      break;
    }
  }

  int res = opcodes->at(0);
  return res;
}

int TARGET = 19690720;

int calculatePair() {
  vector<int>* opcodes = parseInput();

  int ans = 0;

  for (size_t noun = 0; noun < opcodes->size(); noun++) {
    for (int verb = 0; verb < noun; verb++) {
      int result = calculateOpcodes(noun, verb);

      if (result == TARGET) {
        ans = 100 * noun + verb;
        break;
      }
    }
  }
  return ans;
}

int main() {
  int part1 = calculateOpcodes(12, 2);
  int part2 = calculatePair();

  cout << "Part 1 result: " << part1 << endl;
  cout << "Part 2 result: " << part2 << endl;
  return 0;
}
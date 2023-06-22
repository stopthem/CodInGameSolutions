#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
  int n; // the number of temperatures to analyse
  cin >> n;
  cin.ignore();

  int closestToZero = 5526;
  
  bool foundTemp = false;

  for (int i = 0; i < n; i++) {
    int t; // a temperature expressed as an integer ranging from -273 to 5526
    cin >> t;
    cin.ignore();

    int absoluteT = std::abs(t);
    int absoluteClosestToZero = std::abs(closestToZero);
    if (absoluteT == absoluteClosestToZero) {
      closestToZero = std::max(t, closestToZero);
      foundTemp = true;
    } else if (absoluteT < absoluteClosestToZero) {
      closestToZero = t;
      foundTemp = true;
    }
  }

  // Write an answer using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  cout << (foundTemp ? closestToZero : 0) << endl;
}
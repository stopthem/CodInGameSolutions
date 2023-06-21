#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main() {
  int width; // the number of cells on the X axis
  cin >> width;
  cin.ignore();
  int height; // the number of cells on the Y axis
  cin >> height;
  cin.ignore();
  int x1, y1, x2, y2, x3, y3;

  // Vector index = column index
  // Bitset index = row index
  // If bitsets position at x is 1, there is a node there
  std::vector<std::bitset<8>> nodes;
  nodes.reserve(height);

  for (int y = 0; y < height; y++) {
    string line;
    getline(cin, line); // width characters, each either 0 or .

    for (int x = 0; x < width; ++x) {
      if (line[x] == '0') {
        nodes[y].set(x);
      }
    }
  }

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      // Is there a node there ?
      if (nodes[y].test(x)) {

        x2 = y2 = x3 = y3 = -1;

        x1 = x;
        y1 = y;

        // Start from the current node X and look through right
        for (int z = x + 1; z < width; ++z) {

          if (z >= width) {
            continue;
          }

          // Is there a node there ?
          if (!nodes[y].test(z)) {
            continue;
          }
          
          x2 = z;
          y2 = y;

          break;
        }

        // Start from the current node Y and look through down
        for (int z = y + 1; z < height; ++z) {

          if (z >= height) {
            continue;
          }

          // Is there a node there ?
          if (!nodes[z].test(x)) {
            continue;
          }

          x3 = x;
          y3 = z;

          break;
        }

        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " "
             << y3 << endl;
      }
    }
  }
}
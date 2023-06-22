#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int BinarySearch(int low, int high) {

  int mid = (high + low) / 2;

  return mid;
}

int main() {
  int w; // width of the building.
  int h; // height of the building.
  cin >> w >> h;
  cin.ignore();
  int n; // maximum number of turns before game over.
  cin >> n;
  cin.ignore();
  int x0;
  int y0;
  cin >> x0 >> y0;
  cin.ignore();

  int left = 0;
  int right = w;
  int top = 0;
  int bottom = h;
  // game loop
  while (1) {
    string bomb_dir; // the direction of the bombs from batman's current
                     // location (U, UR, R, DR, D, DL, L or UL)
    cin >> bomb_dir;
    cin.ignore();

    int bombDirX = 0, bombDirY = 0;

    if (bomb_dir.find("U") != -1) {

      bombDirY -= 1;
      bottom = y0 + bombDirY;

    } else if (bomb_dir.find("D") != -1) {

      bombDirY += 1;
      top = y0 + bombDirY;
    }

    if (bomb_dir.find("R") != -1) {

      bombDirX += 1;
      left = x0 + bombDirX;

    } else if (bomb_dir.find("L") != -1) {

      bombDirX -= 1;
      right = x0 + bombDirX;

    }

    x0 = BinarySearch(left, right);
    y0 = BinarySearch(top, bottom);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // the location of the next window Batman should jump to.
    cout << x0 << " " << y0 << endl;
  }
}
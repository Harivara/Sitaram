#include <bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {

    if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
    }

    // Horizontal
    for (int jump = 1; sc + jump <= dc; jump++) {
        printMazePaths(sr, sc + jump, dr, dc,
                       psf + "h" + to_string(jump));
    }

    // Vertical
    for (int jump = 1; sr + jump <= dr; jump++) {
        printMazePaths(sr + jump, sc, dr, dc,
                       psf + "v" + to_string(jump));
    }

    // Diagonal
    for (int jump = 1; sr + jump <= dr && sc + jump <= dc; jump++) {
        printMazePaths(sr + jump, sc + jump, dr, dc,
                       psf + "d" + to_string(jump));
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    printMazePaths(0, 0, n - 1, m - 1, "");
}
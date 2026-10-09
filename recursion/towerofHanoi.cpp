// Tower of Hanoi
// The idea is to move n disks from source to destination using an auxiliary rod.
// For n disks:
// 1. Move n-1 disks from source → auxiliary
// 2. Move the largest disk from source → destination
// 3. Move n-1 disks from auxiliary → destination

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {
    if (n == 0)
        return;

    // Move n-1 disks from source to helper
    towerOfHanoi(n - 1, source, destination, helper);

    // Move nth disk from source to destination
    cout << "Move disk " << n
         << " from " << source
         << " to " << destination << endl;

    // Move n-1 disks from helper to destination
    towerOfHanoi(n - 1, helper, source, destination);
}
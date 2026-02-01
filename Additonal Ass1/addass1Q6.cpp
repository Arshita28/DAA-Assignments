#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

// Distance between two points
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Brute force for small number of points
double bruteForce(vector<Point>& P, int l, int r) {
    double minDist = DBL_MAX;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            minDist = min(minDist, dist(P[i], P[j]));
        }
    }
    return minDist;
}

// Strip closest calculation
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;

    // Sort strip by y-coordinate
    sort(strip.begin(), strip.end(),
         [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1;
             j < strip.size() && (strip[j].y - strip[i].y) < minDist;
             j++) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

// Recursive Divide & Conquer function
double closestUtil(vector<Point>& P, int l, int r) {
    // If small number of points, use brute force
    if (r - l <= 3)
        return bruteForce(P, l, r);

    int mid = (l + r) / 2;
    Point midPoint = P[mid];

    // Solve left and right halves
    double dl = closestUtil(P, l, mid);
    double dr = closestUtil(P, mid + 1, r);

    double d = min(dl, dr);

    // Build strip
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);
    }

    // Find closest in strip
    return min(d, stripClosest(strip, d));
}

// Main closest pair function
double closest(vector<Point>& P) {
    // Sort points by x-coordinate
    sort(P.begin(), P.end(),
         [](Point a, Point b) { return a.x < b.x; });

    return closestUtil(P, 0, P.size() - 1);
}

int main() {
    vector<Point> points = {
        {9,3}, {2,6}, {15,3}, {5,1},
        {1,2}, {12,4}, {7,2}, {4,7},
        {16,5}, {3,3}, {10,5}, {6,4},
        {14,6}, {8,6}, {11,1}, {13,2}
    };

    double ans = closest(points);

    cout << fixed << setprecision(3);
    cout << "Minimum Euclidean Distance = " << ans << endl;

    return 0;
}


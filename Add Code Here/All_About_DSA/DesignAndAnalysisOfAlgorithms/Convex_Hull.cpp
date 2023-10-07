#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Function to calculate the cross product (orientation)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2;  // Clockwise or Counterclockwise
}

// Function to compare points based on polar angle from the anchor point
bool polarCompare(Point a, Point b) {
    // Calculate the polar angle of points a and b with respect to the anchor
    // The anchor is assumed to be the point with the lowest y-coordinate (and leftmost if tied)
    int orientationVal = orientation(anchor, a, b);
    if (orientationVal == 0) {
        // If collinear, choose the one closer to the anchor
        return (distSq(anchor, a) < distSq(anchor, b));
    }
    return (orientationVal == 2);  // Sort in counterclockwise order
}

// Function to calculate the square of the Euclidean distance between two points
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Function to find the convex hull of a set of points
void convexHull(Point points[], int n) {
    if (n < 3) return;  // Convex hull not possible with less than 3 points

    // Find the point with the lowest y-coordinate (and leftmost if tied)
    anchor = points[0];
    int anchorIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < anchor.y || (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
            anchorIdx = i;
        }
    }

    // Move the anchor point to the beginning of the array
    swap(points[0], points[anchorIdx]);

    // Sort the points based on polar angle from the anchor point
    sort(points + 1, points + n, polarCompare);

    vector<Point> hull;
    hull.push_back(points[0]);  // Anchor point
    hull.push_back(points[1]);  // Second point

    for (int i = 2; i < n; i++) {
        // Keep removing the last point from the hull while it makes a clockwise turn
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);  // Add the current point to the hull
    }

    // Print the convex hull
    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}

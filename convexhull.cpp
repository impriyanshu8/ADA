#include<iostream>
#include<cmath>
using namespace std;

struct Point {
    int x, y;
};

// Function to calculate the determinant to  calculate sign
int determinant(Point p1, Point p2, Point p) {
    return (p2.x - p1.x) * (p.y - p1.y) - (p.x - p1.x) * (p2.y - p1.y);
}

// Function to find the leftmost and rightmost points
void findExtremePoints(Point point[], int n, Point& leftmost, Point& rightmost) {
    leftmost = point[0];
    rightmost = point[0];
    for (int i = 1; i < n; i++) {
        if (point[i].x < leftmost.x) {
            leftmost = point[i];
        }
        if (point[i].x > rightmost.x) {
            rightmost = point[i];
        }
    }
}

// Function to calculate perpendicular distance from point p to line ab
double pointToLineDist(Point p, Point a, Point b) {
    double A = b.y - a.y;
    double B = a.x - b.x;
    double C = (b.x * a.y) - (a.x * b.y);
    return abs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
}

// Function to find the farthest point from line ab on one side
Point farthestPoint(Point point[], int n, Point a, Point b, int side) {
    double maxDistance = -1;
    Point farthest = a;

    for (int i = 0; i < n; i++) {
        int sign = determinant(a, b, point[i]);
        if ((side > 0 && sign > 0) || (side < 0 && sign < 0)) {
            double dist = pointToLineDist(point[i], a, b);
            if (dist > maxDistance) {
                maxDistance = dist;
                farthest = point[i];
            }
        }
    }

    return farthest;
}

int main() {
    Point points[] = {{1,2},{2,4},{4,5},{5,6},{7,8},{9,3},{4,3},{5,5},{6,7}};
    int size = sizeof(points) / sizeof(points[0]);

    Point leftmost, rightmost;
    findExtremePoints(points, size, leftmost, rightmost);

    cout << "Leftmost Point: (" << leftmost.x << ", " << leftmost.y << ")\n";
    cout << "Rightmost Point: (" << rightmost.x << ", " << rightmost.y << ")\n";

    Point pAbove = farthestPoint(points, size, leftmost, rightmost, 1);
    Point pBelow = farthestPoint(points, size, leftmost, rightmost, -1);

    cout << "Farthest Point Above Line: (" << pAbove.x << ", " << pAbove.y << ")\n";
    cout << "Farthest Point Below Line: (" << pBelow.x << ", " << pBelow.y << ")\n";

    return 0;
}

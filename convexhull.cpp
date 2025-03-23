#include<iostream>
#include<cmath>
using namespace std;
struct Point {
    int x , y ;
};
int determinant(Point p1, Point p2, Point p) {
    return (p2.x - p1.x) * (p.y - p1.y) - (p.x - p1.x) * (p2.y - p1.y);
}

void findextremepoints(Point point[],int n , Point& leftmost , Point &rightmost){
    leftmost = point[0];
    rightmost = point[0];
    for (int i=0;i<n;i++){
        if (point[i].x < leftmost.x){
            leftmost = point[i];
        }
        if (point[i].x > rightmost.x){
            rightmost = point[i];
        }
    }
}
double pointtolinedist(Point p , Point a , Point b){
        double A = b.y - a.y ;
        double B = a.x - b.x ;
        double C = ((b.x)*(a.y)) - ((a.x)*(b.y)) ;
        double dist = std::abs(A*(p.x) + B*(p.y) + C) / std::sqrt(A*A + B*B);
        return dist;
}
Point farthestPoint (Point point[],int n ,Point &leftmost , Point &rightmost){
    double maxdistance = -1;
    Point farthest = point[0];
    for (int i=0; i<n; i++){
        double dist = pointtolinedist (point[i],leftmost,rightmost);
        if (dist > maxdistance){
            maxdistance = dist ;
            farthest = point[i];
        }
    }
    return farthest;       
}
int main(){

    Point point[] = {{1,2},{2,4},{4,5},{5,6},{7,8},{9,3},{4,3},{5,5},{6,7}};
    int size = sizeof(point) / sizeof (point[0]);
    Point leftmost , rightmost ;
    findextremepoints(point,size,leftmost,rightmost);
    Point p1;
    Point p2;
    for(int i=0;i<size;i++){
    int sign = determinant(leftmost,rightmost,point[i]) ; 
    if(sign>0){
        p1 = point[i];
    }
    else {
     p2 = point[i];
    }
}    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  double x = 5, y = 6;
  Point pointA = creePoint(x, y);
  Point pointB = creePoint(y, x);
  Segment segment = creeSegment(pointA, pointB);
  afficheSegment(segment);
  return 0;
}

Point creePoint(double x, double y) {
  Point point = {x, y};
  return point;
  // return (Point) {x, y};
}

void affichePoint(Point point) {
  printf("%f, %f\n", point.x, point.y);
}

Segment creeSegment(Point A, Point B) {
  return (Segment) {A, B};
}

void afficheSegment(Segment segment) {
  printf("A : %f, %f\n", segment.pointA.x, segment.pointA.y);
  affichePoint(segment.pointB);
}

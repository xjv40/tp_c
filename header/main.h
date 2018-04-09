#ifndef __MAIN_H
#define __MAIN_H
struct point
{
  double x;
  double y;
};
struct segment
{
  struct point pointA;
  struct point pointB;
};
typedef struct segment Segment;
typedef struct point Point;
Point creePoint(double x, double y);
Segment creeSegment(Point A, Point B);
void affichePoint(Point point);
void afficheSegment(Segment segment);
#endif  // __MAIN_H

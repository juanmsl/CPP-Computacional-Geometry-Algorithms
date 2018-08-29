#ifndef TRIANGULATION_MONOTONE_HXX
#define TRIANGULATION_MONOTONE_HXX

#include <typedef/types.hxx>
#include <algorithm>
#include <stack>

#define REGULAR 0
#define START 1
#define SPLIT 2
#define MERGE 3
#define END 4

struct CompPoints {
  bool operator() (const Point& a, const Point& b) const {
    if(a.y() == b.y()) return a.x() < b.x();
    return b.y() < a.y();
  }
};

namespace Triangulation {

  void getSubMononotonePolygons(const Polygon& polygon);
  SegmentLinesVector triangulateMonotonePolygon(const Polygon& polygon);

};

#endif

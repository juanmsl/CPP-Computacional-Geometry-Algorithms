#ifndef UTILS_UTILS_HXX
#define UTILS_UTILS_HXX

#include <typedef/types.hxx>
#include <algorithm>


namespace ch {

  bool isInTheLeft(const Point a, const Point p, const Point q);
  PointsVector sortConvexHullEdges(const SegmentLinesVector& convexHull);
  PointsVector mergeConvexHull(const PointsVector& a, const PointsVector& b);
  Point intersect(const SegmentLine& a, const SegmentLine& b);

}

#endif

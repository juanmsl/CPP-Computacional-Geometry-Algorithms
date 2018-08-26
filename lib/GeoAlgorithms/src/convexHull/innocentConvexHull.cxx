#include <convexHull/innocentConvexHull.hxx>

PointsVector ch::innocent::convexHull(const PointsVector& points) {
  SegmentLinesVector convexHull;

  for(Point point_a : points) {
    for(Point point_b : points) {
      if(point_a != point_b) {
        bool isValid = true;

        for(Point point_c : points) {
          if(point_c != point_a && point_c != point_b) {
            isValid &= !isInTheLeft(point_c, point_a, point_b);
          }
        }

        if(isValid) {
          SegmentLine edge(point_a, point_b);
          convexHull.push_back(edge);
        }
      }
    }
  }

  return sortConvexHullEdges(convexHull);
}
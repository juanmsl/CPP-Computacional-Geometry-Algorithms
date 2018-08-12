#include <convexHull/innocentConvexHull.hxx>

PointCollec_2 ch::innocent::convexHull(const PointCollec_2& points) {
  SegmentCollec_2 convexHull;

  for(Point_2 point_a : points) {
    for(Point_2 point_b : points) {
      if(point_a != point_b) {
        bool isValid = true;

        for(Point_2 point_c : points) {
          if(point_c != point_a && point_c != point_b) {
            isValid &= !isInTheLeft(point_c, point_a, point_b);
          }
        }

        if(isValid) {
          Segment_2 edge(point_a, point_b);
          convexHull.push_back(edge);
        }
      }
    }
  }

  return sortConvexHullEdges(convexHull);
}
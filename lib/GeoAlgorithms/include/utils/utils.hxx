#ifndef UTILS_UTILS_HXX
#define UTILS_UTILS_HXX

#include <typedef/types.hxx>
#include <algorithm>


namespace ch {

  bool isInTheLeft(const Point_2 a, const Point_2 p, const Point_2 q);
  PointCollec_2 sortConvexHullEdges(const SegmentCollec_2& convexHull);
  PointCollec_2 mergeConvexHull(const PointCollec_2& a, const PointCollec_2& b);
  Point_2 intersect(const Segment_2& a, const Segment_2& b);
  StatusThree::iterator getBefore(const StatusThree& statusThree, const StatusType& element);
  StatusThree::iterator getAfter(const StatusThree& statusThree, const StatusType& element);

}

#endif

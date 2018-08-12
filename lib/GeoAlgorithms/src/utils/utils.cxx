#include <utils/utils.hxx>

bool ch::isInTheLeft(Point_2 a, Point_2 p, Point_2 q) {
  return CGAL::orientation(p, q, a) == CGAL::LEFT_TURN;
}

PointCollec_2 ch::sortConvexHullEdges(const SegmentCollec_2& convexHull) {
  PointCollec_2 orderedConvexHull;

  Segment_2 firstSegment = *std::min_element(convexHull.cbegin(), convexHull.cend(), [](Segment_2 a, Segment_2 b) {
    return a[0] < b[0];
  });

  Point_2 firstStartPoint = firstSegment.vertex(0);
  Point_2 lastEndPoint = firstSegment.vertex(1);

  orderedConvexHull.push_back(firstStartPoint);
  orderedConvexHull.push_back(lastEndPoint);

  while(firstStartPoint != lastEndPoint) {
    int i = 0;
    bool foundNextEdge = false;
    Segment_2 segment;

    while(i < convexHull.size() && !foundNextEdge) {
      segment = convexHull[i++];
      Point_2 startPoint = segment.vertex(0);

      foundNextEdge = lastEndPoint == startPoint;
    }

    lastEndPoint = segment.vertex(1);
    if(firstStartPoint != lastEndPoint) orderedConvexHull.push_back(lastEndPoint);
  }

  return orderedConvexHull;
}

PointCollec_2 ch::mergeConvexHull(const PointCollec_2& a, const PointCollec_2& b) {

  Point_2 a_max = *std::max_element(a.cbegin(), a.cend(), [](Point_2 a, Point_2 b) {
      return a.y() < b.y();
  });

  Point_2 a_min = *std::min_element(a.cbegin(), a.cend(), [](Point_2 a, Point_2 b) {
      return a.y() < b.y();
  });

  Point_2 b_max = *std::max_element(b.cbegin(), b.cend(), [](Point_2 a, Point_2 b) {
      return a.y() < b.y();
  });

  Point_2 b_min = *std::min_element(b.cbegin(), b.cend(), [](Point_2 a, Point_2 b) {
      return a.y() < b.y();
  });

  PointCollec_2 convex;

  PointCollec_2::const_iterator it_a = std::find(a.cbegin(), a.cend(), a_min);

  while(*it_a != a_max) {
    convex.push_back(*it_a);
    it_a++;
    if(it_a == a.cend()) {
      it_a = a.begin();
    }
  }
  convex.push_back(*it_a);

  PointCollec_2::const_iterator it_b = std::find(b.cbegin(), b.cend(), b_max);

  while(*it_b != b_min) {
    convex.push_back(*it_b);
    it_b++;
    if(it_b == b.cend()) {
      it_b = b.begin();
    }
  }
  convex.push_back(*it_b);

  return convex;
}
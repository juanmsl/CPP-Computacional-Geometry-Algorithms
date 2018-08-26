#include <utils/utils.hxx>

bool ch::isInTheLeft(Point a, Point p, Point q) {
  return CGAL::orientation(p, q, a) == CGAL::LEFT_TURN;
}

PointsVector ch::sortConvexHullEdges(const SegmentLinesVector& convexHull) {
  PointsVector orderedConvexHull;

  SegmentLine firstSegment = *std::min_element(convexHull.cbegin(), convexHull.cend(), [](SegmentLine a, SegmentLine b) {
    return a[0] < b[0];
  });

  Point firstStartPoint = firstSegment.vertex(0);
  Point lastEndPoint = firstSegment.vertex(1);

  orderedConvexHull.push_back(firstStartPoint);
  orderedConvexHull.push_back(lastEndPoint);

  while(firstStartPoint != lastEndPoint) {
    int i = 0;
    bool foundNextEdge = false;
    SegmentLine segment;

    while(i < convexHull.size() && !foundNextEdge) {
      segment = convexHull[i++];
      Point startPoint = segment.vertex(0);

      foundNextEdge = lastEndPoint == startPoint;
    }

    lastEndPoint = segment.vertex(1);
    if(firstStartPoint != lastEndPoint) orderedConvexHull.push_back(lastEndPoint);
  }

  return orderedConvexHull;
}

PointsVector ch::mergeConvexHull(const PointsVector& a, const PointsVector& b) {

  Point a_max = *std::max_element(a.cbegin(), a.cend(), [](Point a, Point b) {
      return a.y() < b.y();
  });

  Point a_min = *std::min_element(a.cbegin(), a.cend(), [](Point a, Point b) {
      return a.y() < b.y();
  });

  Point b_max = *std::max_element(b.cbegin(), b.cend(), [](Point a, Point b) {
      return a.y() < b.y();
  });

  Point b_min = *std::min_element(b.cbegin(), b.cend(), [](Point a, Point b) {
      return a.y() < b.y();
  });

  PointsVector convex;

  PointsVector::const_iterator it_a = std::find(a.cbegin(), a.cend(), a_min);

  while(*it_a != a_max) {
    convex.push_back(*it_a);
    it_a++;
    if(it_a == a.cend()) {
      it_a = a.begin();
    }
  }
  convex.push_back(*it_a);

  PointsVector::const_iterator it_b = std::find(b.cbegin(), b.cend(), b_max);

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

Point ch::intersect(const SegmentLine &a, const SegmentLine &b) {
  Point A = a[0];
  Point B = a[1];
  Point C = b[0];
  Point D = b[1];

  // Line AB represented as a1x + b1y = c1
  double a1 = B.y() - A.y();
  double b1 = A.x() - B.x();
  double c1 = a1*(A.x()) + b1*(A.y());

  // Line CD represented as a2x + b2y = c2
  double a2 = D.y() - C.y();
  double b2 = C.x() - D.x();
  double c2 = a2*(C.x())+ b2*(C.y());

  double determinant = a1*b2 - a2*b1;

  if (determinant == 0) {
    return Point(MAXIMUN, MAXIMUN);
  }

  double x = (b2*c1 - b1*c2)/determinant;
  double y = (a1*c2 - a2*c1)/determinant;
  return Point(x, y);
}
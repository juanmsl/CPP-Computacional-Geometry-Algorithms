#include <convexHull/divideConvexHull.hxx>

PointsVector ch::divide::convexHull(const PointsVector& points) {
  PointsVector convexHull;
  convexHull = convexHullDivide(points, 0, points.size());
  return convexHull;
}

PointsVector ch::divide::convexHullDivide(const PointsVector& points, int l, int r) {
  int elements = r - l;
  PointsVector convexHull;

  if(elements < 5) {
    for(int i = l; i < r; i++) {
      convexHull.push_back(points[i]);
    }
    convexHull = ch::iterative::convexHull(convexHull);
  } else {
    int m = (l + r) / 2;

    PointsVector ch_a = convexHullDivide(points, l, m);
    PointsVector ch_b = convexHullDivide(points, m, r);

    convexHull = mergeConvexHull(ch_a, ch_b);
  }

  return convexHull;
}
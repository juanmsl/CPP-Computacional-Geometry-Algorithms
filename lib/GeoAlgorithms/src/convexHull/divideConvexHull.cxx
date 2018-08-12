#include <convexHull/divideConvexHull.hxx>

PointCollec_2 ch::divide::convexHull(const PointCollec_2& points) {
  PointCollec_2 convexHull;
  convexHull = convexHullDivide(points, 0, points.size());
  return convexHull;
}

PointCollec_2 ch::divide::convexHullDivide(const PointCollec_2& points, int l, int r) {
  int elements = r - l;
  PointCollec_2 convexHull;

  if(elements < 5) {
    for(int i = l; i < r; i++) {
      convexHull.push_back(points[i]);
    }
    convexHull = ch::iterative::convexHull(convexHull);
  } else {
    int m = (l + r) / 2;

    PointCollec_2 ch_a = convexHullDivide(points, l, m);
    PointCollec_2 ch_b = convexHullDivide(points, m, r);

    convexHull = mergeConvexHull(ch_a, ch_b);
  }

  return convexHull;
}
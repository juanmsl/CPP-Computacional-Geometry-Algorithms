#include <convexHull/iterativeConvexHull.hxx>

PointsVector ch::iterative::convexHull(PointsVector points) {
  PointsVector convexHull;

  std::sort(points.begin(), points.end());

  convexHull.push_back(points[0]);
  convexHull.push_back(points[1]);

  for(long i = 2; i < points.size(); i++) {
    convexHull.push_back(points[i]);

    long lastIndex = convexHull.size() - 1;
    Point p = convexHull[lastIndex - 2];
    Point q = convexHull[lastIndex - 1];
    Point a = convexHull[lastIndex - 0];

    if(a == q) {
      convexHull.erase(convexHull.end() - 1);
    } else {
      while(convexHull.size() > 2 && isInTheLeft(a, p, q)) {
        convexHull.erase(convexHull.end() - 2);

        if(convexHull.size() > 2) {
          lastIndex = convexHull.size() - 1;
          p = convexHull[lastIndex - 2];
          q = convexHull[lastIndex - 1];
          a = convexHull[lastIndex - 0];
        }
      }
    }
  }

  convexHull.push_back(points[points.size() - 2]);

  for(long i = points.size() - 3; i > 0; i--) {
    convexHull.push_back(points[i]);

    long lastIndex = convexHull.size() - 1;
    Point p = convexHull[lastIndex - 2];
    Point q = convexHull[lastIndex - 1];
    Point a = convexHull[lastIndex - 0];

    if(a == q) {
      convexHull.erase(convexHull.end() - 1);
    } else {
      while(convexHull.size() > 2 && isInTheLeft(a, p, q)) {
        convexHull.erase(convexHull.end() - 2);

        if(convexHull.size() > 2) {
          lastIndex = convexHull.size() - 1;
          p = convexHull[lastIndex - 2];
          q = convexHull[lastIndex - 1];
          a = convexHull[lastIndex - 0];
        }
      }
    }
  }

  return convexHull;
}
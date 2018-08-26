#ifndef DIVIDE_AND_CONQUER_CONVEXHULL_HXX
#define DIVIDE_AND_CONQUER_CONVEXHULL_HXX

#include <typedef/types.hxx>
#include <utils/utils.hxx>
#include <convexHull/iterativeConvexHull.hxx>
#include <algorithm>

namespace ch {

  namespace divide {

    PointsVector convexHull(const PointsVector& points);
    PointsVector convexHullDivide(const PointsVector& points, int l, int j);

  }

}

#endif

#ifndef DIVIDE_AND_CONQUER_CONVEXHULL_HXX
#define DIVIDE_AND_CONQUER_CONVEXHULL_HXX

#include <typedef/types.hxx>
#include <utils/utils.hxx>
#include <convexHull/iterativeConvexHull.hxx>
#include <algorithm>

namespace ch {

  namespace divide {

    PointCollec_2 convexHull(const PointCollec_2& points);
    PointCollec_2 convexHullDivide(const PointCollec_2& points, int l, int j);

  }

}

#endif

#ifndef LINEINTERSECT_HXX
#define LINEINTERSECT_HXX

#include <typedef/types.hxx>
#include <utils/utils.hxx>
#include <algorithm>
#include <map>
#include <set>

namespace li {

  PointCollec_2 getIntersections(const SegmentCollec_2& lines);
  void printCandidate(const StatusThree& candidates, const SegmentCollec_2& lines);

}

#endif
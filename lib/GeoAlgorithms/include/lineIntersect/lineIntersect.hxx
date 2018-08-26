#ifndef LINEINTERSECT_HXX
#define LINEINTERSECT_HXX

#include <typedef/types.hxx>
#include <utils/utils.hxx>
#include <algorithm>
#include <map>
#include <set>

typedef std::pair<Point, int> StatusType;
typedef std::set<StatusType> StatusThree;

struct compPoint {
  bool operator() (const Point& a, const Point& b) const {
    if(a.y() == b.y()) return a.x() < b.x();
    return b.y() < a.y();
  }
};

namespace li {

  PointsVector getIntersections(const SegmentLinesVector& lines);
  void printCandidate(const StatusThree& candidates, const SegmentLinesVector& lines);
  StatusThree::iterator getBefore(const StatusThree& statusThree, const StatusType& element);
  StatusThree::iterator getAfter(const StatusThree& statusThree, const StatusType& element);

}

#endif
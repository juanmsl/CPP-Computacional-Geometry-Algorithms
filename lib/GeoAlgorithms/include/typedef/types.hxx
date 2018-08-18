#ifndef TYPEDEF_TYPES_HXX
#define TYPEDEF_TYPES_HXX

#include <CGAL/Simple_cartesian.h>
#include <vector>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;
typedef std::vector<Point_2> PointCollec_2;
typedef std::vector<Segment_2 > SegmentCollec_2;


struct compPoint {
  bool operator() (const Point_2& a, const Point_2& b) const {
    if(a.y() == b.y()) return a.x() < b.x();
    return b.y() < a.y();
  }
};

#endif
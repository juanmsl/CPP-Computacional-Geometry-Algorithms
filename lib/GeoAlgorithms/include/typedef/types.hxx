#ifndef TYPEDEF_TYPES_HXX
#define TYPEDEF_TYPES_HXX

#include <CGAL/Simple_cartesian.h>
#include <vector>
#include <set>
#include <limits>

const double MAXIMUN = std::numeric_limits<double>::max();
const double MINIMUN = std::numeric_limits<double>::min();

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point;
typedef Kernel::Segment_2 SegmentLine;

typedef std::vector<Point> PointsVector;
typedef PointsVector::iterator PointsVectorIterator;
typedef PointsVector::const_iterator PointsVectorConstIterator;
typedef PointsVector::reverse_iterator PointsVectorReverseIterator;
typedef PointsVector::const_reverse_iterator PointsVectorConstReverseIterator;

typedef std::vector<SegmentLine> SegmentLinesVector;
typedef SegmentLinesVector::iterator SegmentLinesVectorIterator;
typedef SegmentLinesVector::const_iterator SegmentLinesVectorConstIterator;
typedef SegmentLinesVector::reverse_iterator SegmentLinesVectorReverseIterator;
typedef SegmentLinesVector::const_reverse_iterator SegmentLinesVectorConstReverseIterator;


#endif
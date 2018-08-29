#ifndef TYPEDEF_TYPES_HXX
#define TYPEDEF_TYPES_HXX

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <vector>
#include <set>
#include <limits>
#include <CGAL/Partition_traits_2.h>

const double MAXIMUN = std::numeric_limits<double>::max();
const double MINIMUN = std::numeric_limits<double>::min();

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Partition_traits_2<Kernel> Traits;
typedef CGAL::Point_2<Kernel> Point;
typedef CGAL::Segment_2<Kernel> SegmentLine;
typedef Traits::Polygon_2 Polygon;
typedef Polygon::Vertex_iterator VertexIterator;
typedef Polygon::Vertex_const_iterator ConstVertexIterator;
typedef Polygon::Edge_const_iterator ConstEdgeIterator;

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

typedef std::vector<Polygon> PolygonsVector;
typedef PolygonsVector::iterator PolygonsVectorIterator;
typedef PolygonsVector::const_iterator PolygonsVectorConstIterator;
typedef PolygonsVector::reverse_iterator PolygonsVectorReverseIterator;
typedef PolygonsVector::const_reverse_iterator PolygonsVectorConstReverseIterator;

#endif
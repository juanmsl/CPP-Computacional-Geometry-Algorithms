#include <lineIntersect/lineIntersect.hxx>

PointsVector li::getIntersections(const SegmentLinesVector& lines) {
  PointsVector intersections;
  std::set<Point > setIntersections;
  std::multimap<Point, int, compPoint> points;
  StatusThree candidatePoints;
  std::vector<bool> isCandidate(lines.size(), false);

  for(int i = 0; i < lines.size(); i++) {
    SegmentLine line = lines[i];
    points.emplace(line[0], i);
    points.emplace(line[1], i);
  }

  for(StatusType current : points) {
    Point point = current.first;
    int lineIndex = current.second;
    SegmentLine line = lines[lineIndex];
    Point otherPoint = line[0] == point ? line[1] : line[0];
    StatusType otherPair = std::make_pair(otherPoint, lineIndex);

    isCandidate[lineIndex] = !isCandidate[lineIndex];

    if(isCandidate[lineIndex]) {
      for(StatusType candidate : candidatePoints) {
        if(CGAL::do_intersect(line, lines[candidate.second])) {
          Point p = ch::intersect(line, lines[candidate.second]);
          std::cout << "Intersection line " << lineIndex << " with line " << candidate.second << ": " << p << std::endl;
          setIntersections.emplace(p);
        }
      }

      candidatePoints.emplace(current);
    } else {
      candidatePoints.erase(otherPair);
    }
  }

  intersections.assign(setIntersections.begin(), setIntersections.end());

  return intersections;
}



StatusThree::iterator li::getBefore(const StatusThree &statusThree, const StatusType &element) {
  StatusThree::iterator iterator = --statusThree.lower_bound(element);
  return iterator;
}

StatusThree::iterator li::getAfter(const StatusThree &statusThree, const StatusType &element) {
  StatusThree::iterator iterator = statusThree.upper_bound(element);
  return iterator;
}
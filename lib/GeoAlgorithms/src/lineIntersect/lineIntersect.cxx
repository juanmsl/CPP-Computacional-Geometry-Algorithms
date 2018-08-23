#include <lineIntersect/lineIntersect.hxx>

PointCollec_2 li::getIntersections(const SegmentCollec_2& lines) {
  PointCollec_2 intersections;
  std::set<Point_2 > setIntersections;
  std::multimap<Point_2, int, compPoint> points;
  StatusThree candidatePoints;
  std::vector<bool> isCandidate(lines.size(), false);

  for(int i = 0; i < lines.size(); i++) {
    Segment_2 line = lines[i];
    points.emplace(line[0], i);
    points.emplace(line[1], i);
  }

  for(StatusType current : points) {
    Point_2 point = current.first;
    int lineIndex = current.second;
    Segment_2 line = lines[lineIndex];
    Point_2 otherPoint = line[0] == point ? line[1] : line[0];
    StatusType otherPair = std::make_pair(otherPoint, lineIndex);

    isCandidate[lineIndex] = !isCandidate[lineIndex];

    if(isCandidate[lineIndex]) {
      for(StatusType candidate : candidatePoints) {
        if(CGAL::do_intersect(line, lines[candidate.second])) {
          Point_2 p = ch::intersect(line, lines[candidate.second]);
          std::cout << "Intersection  in: " << lineIndex << " " << candidate.second << " = " << p << std::endl;
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
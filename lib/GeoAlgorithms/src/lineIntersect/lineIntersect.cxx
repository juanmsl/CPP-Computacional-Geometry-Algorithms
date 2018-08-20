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
      candidatePoints.emplace(current);

      StatusThree::iterator after = ch::getAfter(candidatePoints, current);
      StatusThree::iterator before = ch::getBefore(candidatePoints, current);

      if(before != candidatePoints.end()) {
        if(lineIndex != before->second && CGAL::do_intersect(lines[lineIndex], lines[before->second])) {
          Point_2 p = ch::intersect(lines[lineIndex], lines[before->second]);
          std::cout << "Intersection  in: " << lineIndex << " " << before->second << " = " << p << std::endl;
          setIntersections.emplace(p);
        }
      }
      if(after != candidatePoints.end()) {
        if(lineIndex != after->second && CGAL::do_intersect(lines[lineIndex], lines[after->second])) {
          Point_2 p = ch::intersect(lines[lineIndex], lines[after->second]);
          std::cout << "Intersection  in: " << lineIndex << " " << after->second << " = " << p << std::endl;
          setIntersections.emplace(p);
        }
      }
    }

    if(!isCandidate[lineIndex]) {

      StatusThree::iterator after = ch::getAfter(candidatePoints, otherPair);
      StatusThree::iterator before = ch::getBefore(candidatePoints, otherPair);

      if(before != candidatePoints.end() && after != candidatePoints.end()) {
        if(lineIndex != before->second && lineIndex != after->second && before->second != after->second && CGAL::do_intersect(lines[before->second], lines[after->second])) {
          Point_2 p = ch::intersect(lines[before->second], lines[after->second]);
          std::cout << "Intersection out: " << before->second << " " << after->second << " = " << p << std::endl;
          setIntersections.emplace(p);
        }
      }

      candidatePoints.erase(otherPair);
    }
  }

  intersections.assign(setIntersections.begin(), setIntersections.end());

  return intersections;
}
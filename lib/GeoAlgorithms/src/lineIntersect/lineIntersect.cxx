#include <lineIntersect/lineIntersect.hxx>

PointCollec_2 li::getIntersections(const SegmentCollec_2& lines) {
  PointCollec_2 intersections;
  std::set<Point_2> intersectionsSet;
  std::vector<int> lineCandidates;
  std::vector<bool> isCandidate(lines.size(), false);
  std::multimap<Point_2, int, compPoint> points;
  std::multimap<Point_2, int> intersectionCandidates;

  for(int i = 0; i < lines.size(); i++) {
    Segment_2 line = lines[i];
    points.emplace(line[0], i);
    points.emplace(line[1], i);
  }

  for(std::pair<Point_2, int> pair : points) {
    Point_2 point = pair.first;
    int lineIndex = pair.second;
    Segment_2 line = lines[lineIndex];
    Segment_2 line_H(Point_2(0, point.y()), Point_2(10, point.y()));
    std::multimap<Point_2, int> intersectionCandidatesAux;

    /*
     * Barrer line intersect all candidate lines
     * */
    int currentCandidateIndex = -1;
    for(int i = 0; i < lineCandidates.size(); i++) {
      int candidateLineIndex = lineCandidates[i];
      Segment_2 candidateLine = lines[candidateLineIndex];
      Point_2 intersection = ch::intersect(candidateLine, line_H);
      intersectionCandidatesAux.emplace(intersection, candidateLineIndex);

      if(candidateLineIndex == lineIndex) {
        currentCandidateIndex = i;
      }
    }

    std::vector<int> before;
    std::vector<int> after;
    std::cout << "antes: (" << point << ")" << lineIndex << ": ";
    for(std::pair<Point_2, int> intersection : intersectionCandidates) {
      before.push_back(intersection.second);
      std::cout << intersection.second << " ";
    }
    std::cout << std::endl;
    std::cout << "ahora (" << point << ")" << lineIndex << ": ";
    for(std::pair<Point_2, int> intersection : intersectionCandidatesAux) {
      after.push_back(intersection.second);
      std::cout << intersection.second << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < before.size(); i++) {
      if(before[i] != after[i]) {
        std::cout << "interseccion" << std::endl;

        int beforeIndex = (i - 1) % after.size();
        int afterIndex = (i + 1) % after.size();

        Point_2 intersection = ch::intersect(lines[before[i]], lines[after[i]]);
        intersectionsSet.insert(intersection);

        if(before[i] != after[beforeIndex]) {
          intersection = ch::intersect(lines[before[i]], lines[after[beforeIndex]]);
          intersectionsSet.insert(intersection);
        }
        if(before[i] != after[afterIndex]) {
          intersection = ch::intersect(lines[before[i]], lines[after[afterIndex]]);
          intersectionsSet.insert(intersection);
        }
      }
    }

    /*
     * If current point is end point
     * */
    if(isCandidate[lineIndex]) {
      isCandidate[lineIndex] = false;
      lineCandidates.erase(lineCandidates.begin() + currentCandidateIndex);
      intersectionCandidatesAux.erase(point);
    } else {
      isCandidate[lineIndex] = true;
      lineCandidates.push_back(lineIndex);
      intersectionCandidatesAux.emplace(point, lineIndex);
    }

    intersectionCandidates = std::multimap<Point_2, int>(intersectionCandidatesAux);
  }

  for(Point_2 inter : intersectionsSet) {
    std::cout << inter << std::endl;
  }

  intersections.assign(intersectionsSet.begin(), intersectionsSet.end());

  return intersections;
}
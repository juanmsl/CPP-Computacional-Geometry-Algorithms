#include <triangulation/monotone.hxx>

SegmentLinesVector Triangulation::triangulateMonotonePolygon(const Polygon &polygon) {

  std::map<Point, char, CompPoints> orderedVertex;
  for(Point p : polygon.container()) {
    orderedVertex.emplace(p, 'r');
  }

  auto top = std::find(polygon.container().begin(), polygon.container().end(), orderedVertex.begin()->first);
  auto bottom = std::find(polygon.container().begin(), polygon.container().end(), orderedVertex.rbegin()->first);

  while(top != bottom) {
    orderedVertex[*top++] = 'l';
    if(top == polygon.container().end()) {
      top = polygon.container().begin();
    }
  }

  SegmentLinesVector diagonals;
  std::stack<std::pair<Point, char>> stackVertex;
  auto current = orderedVertex.begin();
  auto last = orderedVertex.end();
  last--;

  stackVertex.push(*current++);
  stackVertex.push(*current++);

  for ( ; current != last; ++current ) {
    std::pair<Point, char> currentTop = stackVertex.top();

    if(current->second != currentTop.second) {
      while (!stackVertex.empty()) {
        std::pair<Point, char> lastPoped = stackVertex.top();
        stackVertex.pop();

        if(stackVertex.size() > 0) {
          SegmentLine line(current->first, lastPoped.first);
          diagonals.push_back(line);
        }
      }

      stackVertex.push(currentTop);
      stackVertex.push(*current);
    } else {
      std::pair<Point, char> lastPoped = stackVertex.top();
      stackVertex.pop();
      bool isInside = true;

      while (!stackVertex.empty() && isInside) {
        Point midpoint = CGAL::midpoint(current->first, stackVertex.top().first);

        isInside = CGAL::bounded_side_2(polygon.vertices_begin(), polygon.vertices_end(), midpoint) == CGAL::ON_BOUNDED_SIDE;

        if(isInside) {
          lastPoped = stackVertex.top();
          stackVertex.pop();

          SegmentLine line(current->first, lastPoped.first);
          diagonals.push_back(line);
        }
      }

      stackVertex.push(lastPoped);
      stackVertex.push(*current);
    }
  }

  return diagonals;

}

void Triangulation::getSubMononotonePolygons(const Polygon &polygon) {

  std::map<Point, int, CompPoints> vertices;
  std::map<SegmentLine, Point, CompPoints> helpers;


  for(Point p : polygon.container()) {
    vertices.emplace(p, REGULAR);
  }

  ConstVertexIterator it1 = polygon.vertices_begin();
  ConstVertexIterator it2 = it1; it2++;
  ConstVertexIterator it3 = it2; it3++;

  while(it3 != polygon.vertices_end()) {

    if(it1->y() >= it2->y() && it2->y() <= it3->y()) {
      vertices[*it2] = (it1->x() >= it2->x()) ? MERGE : END;
    } else if(it1->y() <= it2->y() && it2->y() >= it3->y()) {
      vertices[*it2] = (it1->x() >= it2->x()) ? START : SPLIT;
    }

    it1++; it2++; it3++;
  }

  it3 = polygon.vertices_begin();

  if(it1->y() >= it2->y() && it2->y() <= it3->y()) {
    vertices[*it2] = (it1->x() >= it2->x()) ? MERGE : END;
  } else if(it1->y() <= it2->y() && it2->y() >= it3->y()) {
    vertices[*it2] = (it1->x() >= it2->x()) ? START : SPLIT;
  }

  it1++; it2++; it3++;

  it2 = polygon.vertices_begin();

  if(it1->y() >= it2->y() && it2->y() <= it3->y()) {
    vertices[*it2] = (it1->x() >= it2->x()) ? MERGE : END;
  } else if(it1->y() <= it2->y() && it2->y() >= it3->y()) {
    vertices[*it2] = (it1->x() >= it2->x()) ? START : SPLIT;
  }

  for(std::pair<Point, int> p : vertices) {

    if(p.second == START) {
      polygon.eg
    }
  }
}
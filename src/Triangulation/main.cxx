#include <iostream>
#include <fstream>
#include <chrono>

#include <typedef/types.hxx>
#include <triangulation/monotone.hxx>
#include <CGAL/partition_2.h>

long getTime();
Polygon getPolygonFromFile(const char *filename);
void sendLinesToFile(const std::string& filename, SegmentLinesVector lines);

int main(int argc, char *argv[]) {

  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " inputFile outputFile" << std::endl;
    exit(1);
  }

  Polygon polygon = getPolygonFromFile(argv[1]);
  PolygonsVector polygons;
  SegmentLinesVector diagonals;
  std::string filename = std::string(argv[2]);

  long init = getTime();
  if(polygon.is_simple()) {

    CGAL::y_monotone_partition_2(polygon.vertices_begin(), polygon.vertices_end(), std::back_inserter(polygons));
    Triangulation::getSubMononotonePolygons(p);

    int i = 0;
    for(Polygon p : polygons) {
      SegmentLinesVector subDiagonalds = Triangulation::triangulateMonotonePolygon(p);
      diagonals.insert(diagonals.end(), subDiagonalds.begin(), subDiagonalds.end());
      std::cout << ++i << std::endl;
    }

  }
  long end = getTime();

  sendLinesToFile(filename + ".csv", diagonals);
  std::cout << (end - init) << " ms" << std::endl;


  return 0;
}


long getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


Polygon getPolygonFromFile(const char *filename) {
  std::ifstream input(filename);
  Polygon polygon;
  int n;

  input >> n;

  for(int i = 0; i < n; i++) {
    double x, y;

    input >> x >> y;

    Point p(x, y);
    polygon.push_back(p);
  }

  input.close();
  return polygon;
}

void sendLinesToFile(const std::string& filename, SegmentLinesVector lines) {
  std::ofstream output(filename.c_str());

  for(SegmentLine line : lines) {
    output << line[0].x() << "," << line[0].y() << ",";
    output << line[1].x() << "," << line[1].y() << std::endl;
  }

  output.close();
}
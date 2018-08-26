#include <iostream>
#include <fstream>
#include <chrono>

#include <typedef/types.hxx>
#include <lineIntersect/lineIntersect.hxx>

long getTime();
SegmentLinesVector getLinesFromFile(const char *filename);
void sendPointsToFile(const std::string& filename, PointsVector points);

int main(int argc, char *argv[]) {

  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " inputFile outputFile" << std::endl;
    exit(1);
  }

  SegmentLinesVector lines = getLinesFromFile(argv[1]);
  std::string filename = std::string(argv[2]);

  long init = getTime();
  PointsVector intersections = li::getIntersections(lines);
  long end = getTime();

  sendPointsToFile(filename + ".csv", intersections);
  std::cout << (end - init) << " ms" << std::endl;

  return 0;
}


long getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


SegmentLinesVector getLinesFromFile(const char *filename) {
  std::ifstream input(filename);
  SegmentLinesVector lines;
  int n;

  input >> n;

  for(int i = 0; i < n; i++) {
    double x_a, x_b;
    double y_a, y_b;

    input >> x_a >> y_a >> x_b >> y_b;

    Point a(x_a, y_a);
    Point b(x_b, y_b);
    SegmentLine segment(a, b);
    lines.push_back(segment);
  }

  input.close();
  return lines;
}

void sendPointsToFile(const std::string& filename, PointsVector points) {
  std::ofstream output(filename.c_str());

  for(Point point : points) {
    output << point.x() << "," << point.y() << std::endl;
  }

  output.close();
}
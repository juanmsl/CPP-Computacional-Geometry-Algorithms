#include <iostream>
#include <fstream>
#include <chrono>

#include <typedef/types.hxx>
#include <lineIntersect/lineIntersect.hxx>

long getTime();
SegmentCollec_2 getLinesFromFile(const char *filename);
void sendPointsToFile(const std::string& filename, PointCollec_2 points);

int main(int argc, char *argv[]) {

  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " inputFile outputFile" << std::endl;
    exit(1);
  }

  SegmentCollec_2 lines = getLinesFromFile(argv[1]);
  std::string filename = std::string(argv[2]);

  long init = getTime();
  PointCollec_2 intersections = li::getIntersections(lines);
  long end = getTime();

  sendPointsToFile(filename + ".csv", intersections);
  std::cout << (end - init) << " ms" << std::endl;

  return 0;
}


long getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


SegmentCollec_2 getLinesFromFile(const char *filename) {
  std::ifstream input(filename);
  SegmentCollec_2 lines;

  while(!input.eof()) {
    double x_a, x_b;
    double y_a, y_b;

    input >> x_a >> y_a >> x_b >> y_b;

    Point_2 a(x_a, y_a);
    Point_2 b(x_b, y_b);
    Segment_2 segment(a, b);
    lines.push_back(segment);
  }

  input.close();
  return lines;
}

void sendPointsToFile(const std::string& filename, PointCollec_2 points) {
  std::ofstream output(filename.c_str());

  for(Point_2 point : points) {
    output << point.x() << "," << point.y() << std::endl;
  }

  output.close();
}
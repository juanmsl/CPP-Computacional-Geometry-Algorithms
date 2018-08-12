#include <iostream>
#include <fstream>
#include <chrono>

#include <typedef/types.hxx>
#include <convexHull/innocentConvexHull.hxx>
#include <convexHull/iterativeConvexHull.hxx>
#include <convexHull/divideConvexHull.hxx>

long getTime();
PointCollec_2 getPointsFromFile(const char *filename);
void sendPointsToFile(std::string filename, PointCollec_2 points);

int main(int argc, char *argv[]) {

  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " innocent|iterative|divide inputFile outputFile" << std::endl;
    exit(1);
  }

  std::string type = std::string(argv[1]);

  PointCollec_2 points = getPointsFromFile(argv[2]);
  std::string filename = std::string(argv[3]);
  long init = 0;
  long end = 0;
  PointCollec_2 convexHull;

  if(type == "innocent") {

    init = getTime();
    convexHull = ch::innocent::convexHull(points);
    end = getTime();

  } else if(type == "iterative") {

    init = getTime();
    convexHull = ch::iterative::convexHull(points);
    end = getTime();

  } else if(type == "divide") {

    init = getTime();
    convexHull = ch::divide::convexHull(points);
    end = getTime();

  } else {

    std::cerr << type << " is not a valid type of algorithm" << std::endl;
    exit(1);

  }

  sendPointsToFile(filename + "_" + type + ".csv", convexHull);
  std::cout << (end - init) << " ms" << std::endl;

  return 0;
}


long getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


PointCollec_2 getPointsFromFile(const char *filename) {
  std::ifstream input(filename);
  PointCollec_2 points;

  while(!input.eof()) {
    double x;
    double y;

    input >> x >> y;

    Point_2 point(x, y);
    points.push_back(point);
  }

  input.close();
  return points;
}

void sendPointsToFile(std::string filename, PointCollec_2 points) {
  std::ofstream output(filename.c_str());

  for(Point_2 point : points) {
    output << point.x() << "," << point.y() << std::endl;
  }

  output.close();
}
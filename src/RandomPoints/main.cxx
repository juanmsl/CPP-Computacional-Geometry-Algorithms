#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

void generatePoints(char* file, int n, float r1, float r2, float x, float y, float deg);

int main(int argc, char* argv[]) {

  int n = 50;
  float r1 = 50;
  float r2 = 50;
  float x = 0;
  float y = 0;
  float deg = 0;

  if(argc == 1) {
    std::cerr << "You must provide the following parameters" << std::endl << std::endl;
    std::cerr << "  " << argv[0] << " outputFilename [n] [r1] [r2] [x] [y] [deg]" << std::endl << std::endl;
    std::cerr << "  Required parameters:" << std::endl;
    std::cerr << "  outputFilename   The file where the random points will be generated" << std::endl << std::endl;
    std::cerr << "  Optional parameters:" << std::endl;
    std::cerr << "  n                The number of points that will be generated (Default " << n << ")" << std::endl;
    std::cerr << "  r1               The radius in X axis of the ellipse (Default " << r1 << ")" << std::endl;
    std::cerr << "  r2               The radius in Y axis of the ellipse (Default " << r2 << ")" << std::endl;
    std::cerr << "  x                The coordinate X of the ellipse center (Default " << x << ")" << std::endl;
    std::cerr << "  y                The coordinate Y of the ellipse center (Default " << y << ")" << std::endl;
    std::cerr << "  deg              The number od deegres that the ellipse will be rotated (Default " << deg << ")" << std::endl;
    exit(1);
  }

  char* outputFilename = argv[1];

  if(argc >= 3) n = std::atoi(argv[2]);
  if(argc >= 4) r1 = std::atof(argv[3]);
  if(argc >= 5) r2 = std::atof(argv[4]);
  if(argc >= 6) x = std::atof(argv[5]);
  if(argc >= 7) y = std::atof(argv[6]);
  if(argc >= 8) deg = std::atof(argv[7]);

  std::cout << "Generating " << n << " random point inside in an ellipse" << std::endl;
  std::cout << "  Centered: " << x << ", " << y << std::endl;
  std::cout << "  Radius:   " << r1 << " and " << r2 << std::endl;
  std::cout << "  Rotated:  " << deg << " deg" << std::endl << std::endl;
  std::cout << "Writing file (" << outputFilename << ") ..." << std::endl;

  generatePoints(outputFilename, n, r1, r2, x, y, deg);

  std::cout << "Finished!" << std::endl;

  return 0;
}

void generatePoints(char* file, int n, float r1, float r2, float x, float y, float deg) {
  std::ofstream output(file);

  std::random_device randomDevice;
  std::mt19937 mt(randomDevice());
  std::uniform_real_distribution<double> dist_angle(0, 360);
  std::uniform_real_distribution<double> dist_R1(r1 / 3.0, r1);
  std::uniform_real_distribution<double> dist_R2(r2 / 3.0, r2);

  double cos_deg = cos(deg * 3.1416 / 180.0);
  double sin_deg = sin(deg * 3.1416 / 180.0);

  for(int i = 0; i < n; i++) {
    double angle = dist_angle(mt);
    double gen_x = cos(angle) * dist_R1(mt);
    double gen_y = sin(angle) * dist_R2(mt);

    double xx = cos_deg * gen_x - sin_deg * gen_y;
    double yy = sin_deg * gen_x + cos_deg * gen_y;

    xx += x;
    yy += y;

    output << xx << "\t" << yy << std::endl;
  }

  output.close();
}
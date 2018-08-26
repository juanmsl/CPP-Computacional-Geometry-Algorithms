find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

file(GLOB src_dirs "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.c*")
file(GLOB src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(LIBRARY_NAME GeoAlgorithms)
add_library(${LIBRARY_NAME} SHARED ${src_dirs} ${src})
target_link_libraries(${LIBRARY_NAME} ${CGAL_LIBRARIES})
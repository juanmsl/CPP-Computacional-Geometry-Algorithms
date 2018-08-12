find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

file(GLOB lib_src "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.c*")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(LIBRARY_NAME GeoAlgorithms)
add_library(${LIBRARY_NAME} SHARED ${lib_src})
target_link_libraries(${LIBRARY_NAME} ${CGAL_LIBRARIES})
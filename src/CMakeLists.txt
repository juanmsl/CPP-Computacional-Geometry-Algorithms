include_directories(
    ${PROJECT_SOURCE_DIR}/lib/GeoAlgorithms/include
)

#set(EXECUTABLE_NAME pointsGenerator)
#add_executable(${EXECUTABLE_NAME} RandomPoints/main.cxx)
#
#set(EXECUTABLE_NAME convexHull)
#add_executable(${EXECUTABLE_NAME} ConvexHull/main.cxx)
#target_link_libraries(${EXECUTABLE_NAME} GeoAlgorithms)
#
#set(EXECUTABLE_NAME lineIntersect)
#add_executable(${EXECUTABLE_NAME} LineIntersection/main.cxx)
#target_link_libraries(${EXECUTABLE_NAME} GeoAlgorithms)

set(EXECUTABLE_NAME triangulation)
add_executable(${EXECUTABLE_NAME} Triangulation/main.cxx)
target_link_libraries(${EXECUTABLE_NAME} GeoAlgorithms)
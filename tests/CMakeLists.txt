cmake_minimum_required(VERSION 3.16)

# Qt mayor ya lo detecta tu root (Qt5/Qt6)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets Charts)

enable_testing()

# ---- TestScheduler
add_executable(TestScheduler
  testscheduler.cpp
  ${CMAKE_SOURCE_DIR}/scheduler.cpp
)
target_include_directories(TestScheduler PRIVATE
  ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TestScheduler PRIVATE Qt${QT_VERSION_MAJOR}::Test)

add_test(NAME TestScheduler COMMAND TestScheduler)

# ---- TestMemory
add_executable(TestMemory
  testmemory.cpp
  ${CMAKE_SOURCE_DIR}/memory.cpp
)
target_include_directories(TestMemory PRIVATE
  ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TestMemory PRIVATE Qt${QT_VERSION_MAJOR}::Test)

add_test(NAME TestMemory COMMAND TestMemory)

# ---- TestTLB
add_executable(TestTLB
  testtlb.cpp
  ${CMAKE_SOURCE_DIR}/tlb.cpp
)
target_include_directories(TestTLB PRIVATE
  ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TestTLB PRIVATE Qt${QT_VERSION_MAJOR}::Test)

add_test(NAME TestTLB COMMAND TestTLB)

# ---- TestPC
add_executable(TestPC
  testpc.cpp
  ${CMAKE_SOURCE_DIR}/producer_consumer.cpp
)
target_include_directories(TestPC PRIVATE
  ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TestPC PRIVATE Qt${QT_VERSION_MAJOR}::Test pthread)

add_test(NAME TestPC COMMAND TestPC)


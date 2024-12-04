cmake_minimum_required(VERSION 3.10)

project(l3)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Создаем исполняемый файл для основной программы (замените main.cpp на l3.cpp)
add_executable(main_l3 l3.cpp figures.cpp)

# Интеграция GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включаем тестирование
enable_testing()

# Создаем исполняемый файл для тестов
add_executable(test_l3 test.cpp figures.cpp)

# Связываем тесты с библиотекой GoogleTest
target_link_libraries(test_l3 GTest::gtest_main)

# Регистрируем тесты в CTest
include(GoogleTest)
gtest_discover_tests(test_l3)
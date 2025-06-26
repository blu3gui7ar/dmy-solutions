cmake_minimum_required(VERSION 3.14)
project(OJ)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 查找 GTest
find_package(GTest REQUIRED)

# 添加全局include目录（所有目标都可用）
include_directories(SYSTEM /usr/local/include)  # macOS
include_directories(
    ${PROJECT_SOURCE_DIR}/include  # 项目根目录下的include目录
)

# 添加可执行文件
add_executable(unittest 
    ${PROJECT_SOURCE_DIR}/test/gcd_test.cpp
    ${PROJECT_SOURCE_DIR}/test/get_factors_test.cpp
    ${PROJECT_SOURCE_DIR}/test/factorize_test.cpp
    ${PROJECT_SOURCE_DIR}/test/factorize_cached_test.cpp
    ${PROJECT_SOURCE_DIR}/test/main_test.cpp
)

# 为my_app目标添加include目录
#target_include_directories(unittest PRIVATE
#    ${PROJECT_SOURCE_DIR}/test/include  # 项目根目录下的include目录
#)

# 链接 GTest 库
target_link_libraries(unittest
    # GTest::GTest GTest::Main
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}  # 包含main函数
)
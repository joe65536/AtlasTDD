add_executable(TiereProjektTest TiereProjekt.cpp schwein.cpp schweinTest.cpp)
target_link_libraries(TiereProjektTest gtest gmock gtest_main)
add_test(TiereProjektTest TiereProjektTest)

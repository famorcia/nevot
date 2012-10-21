cmake_minimum_required (VERSION 2.6)
project (NEVoT)

include_directories ("${PROJECT_SOURCE_DIR}/include")

add_library(nevot 
    src/NClockCatalog.cpp 
    src/NClockProperty.cpp 
    src/NConfig.cpp 
    src/NConfig.hpp 
    src/NExecutor.cpp 
    src/NSystemClock.cpp 
    src/NEVoT.cpp
    src/NUtil.cpp)


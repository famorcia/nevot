cmake_minimum_required (VERSION 2.6)
project (NEVoT)

add_library(nevot NClockCatalog.cpp NClockProperty.cpp NConfig.cpp NConfig.hpp NExecutor.cpp NSystemClock.cpp NUtil.cpp)


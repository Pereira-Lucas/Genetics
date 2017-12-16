cmake_minimum_required(VERSION 3.9)
project(Genetics)

set(CMAKE_CXX_STANDARD 17)

# utility files
set(UtilityFiles Utility/random.cpp Utility/random.h)

# Chromosomes files
set(ChromosomesSrc Chromosomes/chromosome.cpp Chromosomes/world.cpp)
set(ChromosomesHds Chromosomes/chromosome.h Chromosomes/world.h)

# Executables list
add_executable(Chromosomes main.cpp ${UtilityFiles} ${ChromosomesSrc} ${ChromosomesHds})

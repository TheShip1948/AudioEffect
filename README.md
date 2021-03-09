# Audio Effect 
## Build Steps 
The following are build steps on Linux, building on other platforms should be the same.
* Move to AudioEffect directory, project code main directory (cd AudioEffect)
* Create a new directory called build (mkdir build)
* Move to build directory (cd build) 
* Run cmake for both driver program called main and unit tests (cmake .. -DUNIT_TESTS=True)
* Build code (make)
* Run driver program (./src/main)
* Run unit test cases (./tests/audio_effect_test) 

## Technologies
* Operating system that I tested the code on is Ubuntu 18.04
* Code is compiled for C++14
* cmake version 3.10.2
* gcc version 7.5.0
* g++ version 7.5.0
* Unit test library is catch2 (https://github.com/catchorg/Catch2) Hint: I used header file version of the library as it is easier to run the project on different machines, but this leads to some overhead in compile time.

## Project Hierarchy and Structure
Project consists of three directories
* src: contains 
  * audio_effect.h: which contains the implementation of detect feedback 
  * main.cpp: the driver program  
* tests: contains audio_effect_test.cpp which uses catch2 unit test library to test different scenarios of detect feedback.
* third_party: contains code of catch2 library a unit test library 
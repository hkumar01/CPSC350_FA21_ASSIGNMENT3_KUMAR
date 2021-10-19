# CPSC350_FA21_ASSIGNMENT3_KUMAR

Hari Kumar
002352411
hkumar@chapman.edu
CPSC350-02  
Assignment 3 Game of Life 

Files Submitted:
- main.cpp
- classic.h
- classic.cpp
- doughnut.h
- doughnut.cpp
- mirror.h
- mirror.cpp
- gameboard.h
- gameboard.cpp
- readme.md
- Makefile

No compile or runtime errors

References:
- Tutored by former student Thomas Moore on creating numberOfNeighbors() function to count number of neighbors and followed the function he created for classic mode. I then carried out the same logic to create neighbor-check functions for doughnut and mirror mode on my own.
- https://www.youtube.com/watch?v=YZ-W5DrKPQ0&t=691s - used same logic from video to count number of neighbors
- Tutored by class TA Josh on doughnut mode logic
- https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/ - used site to learn about 2d dynamically allocated arrays
- https://careerkarma.com/blog/c-plus-plus-string-to-int/ - learned about stoi function here 
- Also used former student Thomas Moore calculation for population density

Instructions to start program in Docker container:

- g++ *.cpp
- ./a.out name_of_input_file name_of_output_file T2E or E2T

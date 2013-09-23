/**
 * @file:   main.cpp
 * @author: Davis St. Aubin
 *
 * Created on September 9, 2013, 3:02 PM
 */

#include "Executive.h"

int main(int argc, char** argv) {
/*
  std::string matFiles[] = {".\\mat_00.txt", ".\\mat_01.txt", ".\\mat_02.txt", ".\\mat_03.txt", ".\\mat_04.txt"};
  std::string directiveFile = "directives.txt";
*/
  std::string matFiles[10];
  for (int i = 1; i < argc-1; i++) {
      matFiles[i-1] = argv[i];
  }
  std::string directiveFile = argv[argc];
  
  Executive overSeer(matFiles, argc-2, directiveFile);
}


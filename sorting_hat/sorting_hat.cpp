//Sorting hat program
// Following https://www.codecademy.com/courses/learn-c-plus-plus/projects/harry-potter-sorting-hat

#include <iostream>
#include "config.h"


#ifdef USE_IO_UTILS
#include "parse_input.h"
#endif

enum house {gryff, huff, raven, slyth}; // 0, 1, 2, 3
void Q1(int (&)[4]);
void Q2(int (&)[4]);
void Q3(int (&)[4]);
void Q4(int (&)[4]);

#ifndef USE_IO_UTILS
int parse_input(void) {
//  std::cout << "Parsing input locally\n";
  float in;
  std::cin >> in;
  return static_cast<int>(in);
}
#endif

int main() {
  
  std::cout << "v" << Sorting_Hat_VERSION_MAJOR << "." << Sorting_Hat_VERSION_MINOR << std::endl;

  int house_points[4] = {0, 0, 0, 0}; // Gryff, Huff, Raven, Slyth
  
  std::cout << "The Sorting Hat Quiz!" << std::endl;
 
  for (int i = 0; i < 4; i++) {
    /*std::cout << "Current standing is:\n"
      << "Gryffindor: " << house_points[gryff]
      << "\nHufflepuff: " << house_points[huff]
      << "\nRavenclaw: " << house_points[raven]
      << "\nSlytherin: " << house_points[slyth] << "\n\n";
    */
    switch (i) {
      case 0:
        Q1(house_points);
        break;
      case 1:
        Q2(house_points);
        break;
      case 2:
        Q3(house_points);
        break;
      case 3:
        Q4(house_points);
        break;
      
    }
  }

  int max = 0;
  std::string decision;
  if (house_points[gryff] > max) {
    max = house_points[gryff];
    decision = "Gryffindor";
  } 
  if (house_points[huff] > max) {
    max = house_points[huff];
    decision = "Hufflepuff";
  }
  if (house_points[raven] > max) {
  max = house_points[raven];
  decision = "Ravenclaw";
  }
  if (house_points[slyth] > max) {
  max = house_points[slyth];
  decision = "Slytherin";
  }
  std::cout << "I see.\nIt seems you're destined for...\n\n\n\n"
    << decision << "!!!!\n";
  
}
void Q1(int (&points)[4]) {
  int ans;
  std::cout << "Q1) When I'm dead, I want people to remember me as:\n\n"
    << "\t1) The Good\n"
    << "\t2) The Great\n"
    << "\t3) The Wise\n"
    << "\t4) The Bold\n";
  
  while (true) {
    ans = parse_input();
    switch (ans) {
      case 1:
        points[huff]++;
        return;
      case 2:
        points[slyth]++;
        return;
      case 3:
        points[raven]++;
        return;
      case 4:
        points[gryff]++;
        return;
      default:
        std::cout << "Answer format is the number of your answer choice\n";
    }
  }
}

void Q2(int (&points)[4]) {
  int ans;
  std::cout << "Q2) Dawn or Dusk?\n" << std::endl;

  while (true) {
    ans = parse_input();
    switch (ans) {
      case 1:
        points[gryff]++;
        points[raven]++;
        return;
      case 2:
        points[slyth]++;
        points[huff]++;
        return;
      default:
        std::cout << "Answer format is 1 for Dawn, 2 for Dusk\n";
    }
  }
}

void Q3(int (&points)[4]) {
  int ans;
  std::cout << "Q3) Which kind of instrument most pleases your ear?\n\n"
    << "\t1) The violin\n"
    << "\t2) The trumpet\n"
    << "\t3) The piano\n"
    << "\t4) The drum\n";

  while (true) {
    ans = parse_input();
    switch (ans) {
      case 1:
        points[slyth]++;
        return;
      case 2:
        points[huff]++;
        return;
      case 3:
        points[raven]++;
        return;
      case 4:
        points[gryff]++;
        return;
      default:
        std::cout << "Answer format is the number of your answer choice\n";
    }
  }
}

void Q4(int (&points)[4]) {
  int ans;
  std::cout << "Q4) Which road tempts you most?\n\n"
    << "\t1) The wide, sunny grassy lane\n"
    << "\t2) The narrow, dark, lantern-lit alley\n"
    << "\t3) The twisting, leaf-strewn path through woods\n"
    << "\t4) The cobbled street lined with ancient buildings\n";

  while (true) {
    ans = parse_input();
    switch (ans) {
      case 1:
        points[huff]++;
        return;
      case 2:
        points[slyth]++;
        return;
      case 3:
        points[gryff]++;
        return;
      case 4:
        points[raven]++;
        return;
      default:
        std::cout << "Answer format is the number of your answer choice\n";
    }
  }
}


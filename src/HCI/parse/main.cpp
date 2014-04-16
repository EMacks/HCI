//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// main file for getting database information into a txt file
//*****************************************************************************
#include "database.h"
#include "keyfeatures.h"
#include "analysis.h"
#include <QApplication>
#include <fstream>
#include <QList>
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Database datab;
  datab.makeConnection();
  int expected[6]= {0,0,0,0,0}, result[2]={0,0};
  datab.getEverything(expected, result);
// do something to output to data to a file easily
  std::ofstream out("tired_data.csv");
  
  /*  std::cout << e.length() << std::endl;
  for(int i = 0; i < e.length(); i++) {
    std::cout << "before " << i << "th test" << std::endl;
    std::cout << e[i].emoTestTired() << std::endl;
    expected[e[i].emoTestTired()]++;
    std::cout << "before " << i << "th result" << std::endl;
    if(e[i].result()) {
      result[1]++;
    } else {
      result[0]++;
    }
    std::cout << "after result" << std::endl;
  }
  std::cout << "after counting" << std::endl;
  */
  for(int i = 0; i < 5; i++)
    out << expected[i] << ", ";
  out << std::endl;
  out << result[0] << ", " << result[1] << std::endl;
  out.close();
  return a.exec();
  
}

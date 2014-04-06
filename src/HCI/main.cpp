//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Main file which is awesome
//*****************************************************************************
#include "mainwindow.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   // if(DOTHIS()) {
      MainWindow w;
      w.exec();
      // }
   
   return a.exec();
}

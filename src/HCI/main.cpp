//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Main file
//*****************************************************************************
#include "dialogs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Database data;
   Dialogs w;
   w.show();
      
   return a.exec();
}

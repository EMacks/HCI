//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Main file which is awesome
//*****************************************************************************
#include "dialogs.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   if(DOTHIS()) {
      Dialogs w;
      w.show();
   }
   
   return a.exec();
}

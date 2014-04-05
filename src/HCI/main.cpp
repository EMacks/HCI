//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Main file which is awesome
//*****************************************************************************
#include "mainwindow.h"
#include <QApplication>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include "database.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
//   if(DOTHIS()) {
      MainWindow w;
      w.show();
      // }
   
   return a.exec();
}

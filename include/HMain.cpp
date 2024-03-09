#include "Main.h"

void Connects(MainWindow *Window, QApplication *Application){
    QPushButton *Add = Window->findChild<QPushButton *>(QString::fromStdString("Add"));
    QPushButton *Remove = Window->findChild<QPushButton *>(QString::fromStdString("Remove"));
    QObject::connect(Window, SIGNAL(StatusError()), Window, SLOT(Exit()));
    QObject::connect(Add, SIGNAL(clicked()), Window, SLOT(AddScreen()));
    QObject::connect(Remove, SIGNAL(clicked()), Window, SLOT(RemoveScreen()));
    QObject::connect(Window, SIGNAL(QuitApp()), Application, SLOT(quit()));
}
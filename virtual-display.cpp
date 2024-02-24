#include <include/Main.h>
using namespace std;

int main(int argc, char *argv[]){
    QApplication App(argc, argv);
    Ui_MainWindow UI;
    MainWindow window;
    UI.setupUi(&window);
    Connects(&window, &App);
    window.show();
    window.KeepUpdate();
    return App.exec();
}
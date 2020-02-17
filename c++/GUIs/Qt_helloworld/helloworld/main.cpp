#include <QCoreApplication>
#include <QDebug>
#include <QLabel>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QLabel *Label = new Qlabel {"Hello World!"};
    label->setWindowTitle("My App");
    label->show();
    return a.exec();
}

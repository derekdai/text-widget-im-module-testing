#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QGridLayout>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QWidget w;
  w.setMinimumSize(1280, 720);

  QTextEdit editor;

  QGridLayout layout;
  layout.addWidget(&editor, 0, 0);

  w.setLayout(&layout);

  w.show();

  return a.exec();
}

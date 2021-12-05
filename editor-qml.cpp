#include <QGuiApplication>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[])
{
  QGuiApplication a(argc, argv);

  QQuickView view;
  view.setSource(QUrl("editor-qml.qml"));
  view.show();

  return a.exec();
}

#include <QApplication>
#include "menu.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("D:/vodopad.jpg"));
    QPalette plt =w.palette();
    plt.setBrush(QPalette::Background,br);
    w.setPalette(plt);
    w.show();

    return a.exec();
}

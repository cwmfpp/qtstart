#include "dialog.h"
#include "rtspclient_self.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    char *argvtmp[] = {"qt", "rtsp://192.168.128.30:8554/slamtv60.264"};

    main_rtspclient(2, argvtmp);
    Dialog w;
    w.show();
    return a.exec();
}

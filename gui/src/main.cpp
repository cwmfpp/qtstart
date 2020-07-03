#include "dialog.h"

#include <QApplication>
#include "rtspclientdemo.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    char *argvtmp[] = {"qt", "rtsp://192.168.128.30:8554/slamtv60.264", "rtsp://192.168.128.30:8554/slamtv61.264"};

    //main_rtspclient(2, argvtmp);
    TestRTSPClientSession();
    Dialog w;
    w.show();
    return a.exec();
}

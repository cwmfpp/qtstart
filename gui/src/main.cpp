#include "dialog.h"
#include "rtspclient_self.h"

#include <QApplication>


static int TestRTSPClient_CallBack(int _iType, RTSPClientAttr *_pstRTSPClientAttr, u_int8_t *_pucData, void *_pvPri)
{
    UsageEnvironment* env = RTSPClientSession::m_penv;


    if(NULL != _pstRTSPClientAttr) {
        *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << " _iType:" << _iType << " len " << _pstRTSPClientAttr->m_uiDataLen << " pcData addr:" << _pucData << " _pvPri addr:" << _pvPri << "\n";
    } else {
        *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << " _iType:" << _iType << " pcData addr:" << _pucData << " _pvPri addr:" << _pvPri << "\n";

    }

    return 0;
}

void TestRTSPClientSession()
{
    RTSPClientSession::RTSPClientSessionInit();

    RTSPClientSession stRTSPClientSession;
    RTSPClientSession stRTSPClientSession2;

    RTSPClientInfo stRTSPClientInfo;
    snprintf(stRTSPClientInfo.m_cRTSPUrl, sizeof(stRTSPClientInfo.m_cRTSPUrl), "%s", "rtsp://192.168.128.30:8554/slamtv60.264");
    stRTSPClientInfo.m_pRTSPClientCallBack = TestRTSPClient_CallBack;
    stRTSPClientSession.StartRTSPClientSession(&stRTSPClientInfo);

    snprintf(stRTSPClientInfo.m_cRTSPUrl, sizeof(stRTSPClientInfo.m_cRTSPUrl), "%s", "rtsp://192.168.128.30:8554/slamtv61.264");
    stRTSPClientInfo.m_pRTSPClientCallBack = TestRTSPClient_CallBack;
    stRTSPClientSession2.StartRTSPClientSession(&stRTSPClientInfo);
#if 0
    sleep(5);
    stRTSPClientSession.StopRTSPClientSession();
    sleep(5);
    stRTSPClientSession2.StopRTSPClientSession();
#endif

}

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

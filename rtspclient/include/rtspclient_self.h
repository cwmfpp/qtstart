#ifndef __RTSPCLIENT_SEFL_H
#define __RTSPCLIENT_SEFL_H
/*
 * add 20200701
 *
 * auth: wenminchen@126.com
 *
 *
*/

#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"

struct RTSPClientAttr{
    unsigned int m_uiDataLen;
    unsigned int m_uiTimestamp;
    int m_iWidth;
    int m_iHigh;
};




#define RTSPC_CALLBACK_TYPE_MEDIA_DATA      1
#define RTSPC_CALLBACK_TYPE_SESSION_CLOSE           2
typedef int (RTSPClient_CallBack)(int _iType, RTSPClientAttr *_pstRTSPClientAttr, unsigned char *_pucData, void *_pvPri);


#define  RTSPCLIENT_URL_LEN     256

class RTSPClientInfo {
public:
    char m_cRTSPUrl[RTSPCLIENT_URL_LEN];//rtsp url
    RTSPClient_CallBack* m_pRTSPClientCallBack;//callback
};


class RTSPClientSession/*: public ourRTSPClient*/ {
public:
  RTSPClientSession();
  virtual ~RTSPClientSession();

public:
  static int RTSPClientSessionInit();
  static int RTSPClientSessionDispatch();
  int StartRTSPClientSession(RTSPClientInfo *_pRTSPClientInfo);
  int StopRTSPClientSession();

private:
  RTSPClient *m_pRTSPClient;
  unsigned char* m_pucReceiveFrame;
  void *m_pvPri;

  public:
  static TaskScheduler* m_pscheduler;
  static UsageEnvironment* m_penv;

};

int main_rtspclient(int argc, char** argv);

void TestRTSPClientSession();

#endif // __RTSPCLIENT_SEFL_H

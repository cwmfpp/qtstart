#include <stdio.h>

#include "rtspclientdemo.h"
#include "rtspclient_self.h"

static int WriteRTSPClientFile(int _iType, u_int8_t *_pucData, int _iDataLen)
{
    static FILE *phRTSP = NULL;
    int iRet = 0;

    UsageEnvironment* env = RTSPClientSession::m_penv;

    if(RTSPC_CALLBACK_TYPE_MEDIA_DATA == _iType) {
        if (NULL == _pucData || _iDataLen <= 0) {
            return -1;
        }

        if(NULL == phRTSP) {
            phRTSP = fopen("rtsp.h264", "a+");
            if (NULL == phRTSP) {
                return -1;
            }
        }

        iRet = fwrite(_pucData, 1, (size_t)_iDataLen, phRTSP);
        *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << " iRet=" << iRet << "\n";
        if (iRet != _iDataLen) {
            *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << "write failed" << "\n";
            return -1;
        }
    } else if(RTSPC_CALLBACK_TYPE_SESSION_CLOSE == _iType) {
        if (NULL != phRTSP) {
            *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << " fclose " << "\n";
            fclose(phRTSP);
            phRTSP = NULL;
        }
    }


    return 0;
}
static int TestRTSPClient_CallBack(int _iType, RTSPClientAttr *_pstRTSPClientAttr, u_int8_t *_pucData, void *_pvPri)
{
    UsageEnvironment* env = RTSPClientSession::m_penv;


    if(NULL != _pstRTSPClientAttr) {
        *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << " _iType:" << _iType << " len " << _pstRTSPClientAttr->m_uiDataLen << " timestamp: " << _pstRTSPClientAttr->m_uiTimestamp << " pcData addr:" << _pucData << " _pvPri addr:" << _pvPri << "\n";
    } else {
        *env << "chenwenmin  " << __func__ << ":" <<__LINE__ << " _iType:" << _iType << " pcData addr:" << _pucData << " _pvPri addr:" << _pvPri << "\n";

    }

    WriteRTSPClientFile(_iType, _pucData, (NULL != _pstRTSPClientAttr) ? _pstRTSPClientAttr->m_uiDataLen : 0);

    return 0;
}

void TestRTSPClientSession()
{
    RTSPClientSession::RTSPClientSessionInit();

    RTSPClientSession stRTSPClientSession;
    RTSPClientSession stRTSPClientSession2;

    RTSPClientInfo stRTSPClientInfo;
    snprintf(stRTSPClientInfo.m_cRTSPUrl, sizeof(stRTSPClientInfo.m_cRTSPUrl), "%s", "rtsp://username1:password1@192.168.128.30:8554/slamtv60.264");
    stRTSPClientInfo.m_pRTSPClientCallBack = TestRTSPClient_CallBack;
    stRTSPClientSession.StartRTSPClientSession(&stRTSPClientInfo);

#if 0
    snprintf(stRTSPClientInfo.m_cRTSPUrl, sizeof(stRTSPClientInfo.m_cRTSPUrl), "%s", "rtsp://192.168.128.30:8554/slamtv61.264");
    stRTSPClientInfo.m_pRTSPClientCallBack = TestRTSPClient_CallBack;
    stRTSPClientSession2.StartRTSPClientSession(&stRTSPClientInfo);
#endif

#if 0
    sleep(5);
    stRTSPClientSession.StopRTSPClientSession();
    sleep(5);
    stRTSPClientSession2.StopRTSPClientSession();
#endif

}

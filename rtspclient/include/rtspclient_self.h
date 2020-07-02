#ifndef __RTSPCLIENT_SEFL_H
#define __RTSPCLIENT_SEFL_H
/*
 * add 20200701
 *
 * auth: wenminchen@126.com
 *
 *
*/


struct RTSPClientAttr{
    unsigned int m_uiDataLen;
    unsigned int m_uiTimestamp;
    int m_iWidth;
    int m_iHigh;
};

typedef int (RTSPClient_CallBack)(int _iType, RTSPClientAttr *_pstRTSPClientAttr, unsigned char *_pucData, void *_pvPri);

int main_rtspclient(int argc, char** argv);

void TestRTSPClientSession();

#endif // __RTSPCLIENT_SEFL_H

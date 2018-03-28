#ifndef UXCCDPERX_H
#define UXCCDPERX_H

#include <QMainWindow>
#include "jai_factory.h"
//#include <GDIPLUS.H>
#include <STRSAFE.H>


#include <QMouseEvent>
#include<QDebug>
#include<cstring>
#include<QPixmap>

#include "uxccdw.h"


//using namespace Gdiplus;

#pragma once

#define NODE_NAME_WIDTH         (int8_t*)"Width"
#define NODE_NAME_HEIGHT        (int8_t*)"Height"
#define NODE_NAME_PIXELFORMAT   (int8_t*)"PixelFormat"
#define NODE_NAME_GAIN          (int8_t*)"GainRaw"
#define NODE_NAME_ACQSTART      (int8_t*)"AcquisitionStart"
#define NODE_NAME_ACQSTOP       (int8_t*)"AcquisitionStop"


class UXCCDPERX /*: public QMainWindow*/
{
//    Q_OBJECT

public:
    UXCCDPERX(/*QWidget *parent = 0*/);

    FACTORY_HANDLE m_hFactory;
    CAM_HANDLE			m_hCam; //Factory Handle
    VIEW_HANDLE			m_hView; //Camera Handle
    THRD_HANDLE			m_hThread;
    int8_t				m_sCameraId[J_CAMERA_ID_SIZE];//Camera ID
    J_tIMAGE_INFO m_CnvImageInfo; // Image info struct



    J_STATUS_TYPE   retval;
    UXCCDW              *uxCCD;

    void close();
    void camerawstart();
    void StreamCBFunc(J_tIMAGE_INFO * pAqImageInfo);
    ~UXCCDPERX();
private:

};

#endif // UXCCDPERX_H

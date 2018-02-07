#include "/media/root/LENOVO/WpSystem/Qt_project/OpenGL/uxdatav.h"

#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/Q3DTheme>
#include <QtGui/QImage>
#include <QtCore/qmath.h>


const int sampleCountX = 50;
const int sampleCountZ = 50;
const int heightMapGridStepX = 6;
const int heightMapGridStepZ = 6;
const float sampleMin = -8.0f;
const float sampleMax = 8.0f;

UXDatav::UXDatav(Q3DSurface *surface):graph(surface)
{
  graph->setAxisX(new QValue3DAxis);
  graph->setAxisY(new QValue3DAxis);
  graph->setAxisZ(new QValue3DAxis);

  proxy = new QSurfaceDataProxy();
  series = new QSurface3DSeries(proxy);
  series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
  series->setFlatShadingEnabled(true);


  fillSqrtSinProxy();

}

UXDatav::~UXDatav()
{
  delete graph;
}

void UXDatav::fillSqrtSinProxy()
{
  float stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
  float stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);

  QSurfaceDataArray *dataArray = new QSurfaceDataArray;

  dataArray->reserve(sampleCountZ);
  for (int i = 0; i < sampleCountZ ; i++){
    QSurfaceDataRow * newRow = new QSurfaceDataRow(sampleCountX);
    float z = qMin(sampleMax, (sampleMin + i*stepZ));
    int index = 0;
    for (int j=0; j<sampleCountZ; j++){
      float x = qMin(sampleMax, (j * stepX + sampleMin));
      float R = qSqrt(z * z + x * x  ) + 0.01f;
      float y = (qSin(R) / R + 0.24f) *1.61f;
      (*newRow)[index++].setPosition(QVector3D(x, y, z));
    }
    *dataArray << newRow;
  }

  proxy->resetArray(dataArray);
  graph->axisX()->setLabelFormat("%.2f");
  graph->axisZ()->setLabelFormat("%.2f");
  graph->axisY()->setTitle("Z轴");
  graph->axisY()->setTitleVisible(true);
  graph->axisX()->setTitle("X轴");
  graph->axisX()->setTitleVisible(true);
  graph->axisZ()->setTitle("Y轴");
  graph->axisZ()->setTitleVisible(true);
  graph->axisX()->setLabels(QStringList(QString("google")));
  graph->axisX()->setRange(sampleMin, sampleMax);
  graph->axisY()->setRange(0.0f, 2.0f);
  graph->axisZ()->setRange(sampleMin, sampleMax);
  graph->axisX()->setLabelAutoRotation(30);
  graph->axisY()->setLabelAutoRotation(90);
  graph->axisZ()->setLabelAutoRotation(30);


  graph->addSeries(series);

  QLinearGradient gr;
  gr.setColorAt(0.0, Qt::blue);
  gr.setColorAt(0.5,Qt::green);
  gr.setColorAt(1.0, Qt::red);

  graph->seriesList().at(0)->setBaseGradient(gr);
  graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

void UXDatav::setgradtoriget()
{
    QLinearGradient *rgr = new QLinearGradient(0, 0, 1, 100);
    rgr->setColorAt(0.0,Qt::blue);
    rgr->setColorAt(0.5,Qt::green);
    rgr->setColorAt(1.0,Qt::red);

    graph->seriesList().at(0)->setBaseGradient(*rgr);
    graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

void UXDatav::setgradtoleft()
{
    QLinearGradient *lgr = new QLinearGradient(0, 0, 1, 100);
    lgr->setColorAt(1.0,QColor(255,223,0));
    lgr->setColorAt(0.0,QColor(128,0,0));

    graph->seriesList().at(0)->setBaseGradient(*lgr);
    graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

void UXDatav::tosurf()
{
    series->setDrawMode(QSurface3DSeries::DrawSurface);
}

void UXDatav::towire()
{
    series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
}

void UXDatav::toonlywire()
{
    series->setDrawMode(QSurface3DSeries::DrawWireframe);
}

void UXDatav::changePresetCamera()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();


    // Restore camera target in case animation has changed it
    graph->scene()->activeCamera()->setTarget(QVector3D(0.0f, 0.0f, 0.0f));

    //! [10]
    static int preset = Q3DCamera::CameraPresetFront;

    graph->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)preset);

    if (++preset > Q3DCamera::CameraPresetDirectlyBelow)
        preset = Q3DCamera::CameraPresetFrontLow;
    //! [10]
}

void UXDatav::informselectchange()
{
//    qDebug() << "Select change";
//    qDebug() << graph->scene()->selectionQueryPosition();
//    qDebug() << graph->focusObject();

        qDebug() <<graph->selectedSeries()->selectedPoint();


}

Q3DSurface* UXDatav::getgraph()
{
    return graph;
}

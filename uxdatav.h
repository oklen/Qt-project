#ifndef DATAV_H
#define DATAV_H

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QPropertyAnimation>
#include <QPaintEvent>

/***************************************
 * Contain the 3d data process and other
 * import interfaces to implement the
 * 3d UI
 * ***************************/

using namespace QtDataVisualization;

class UXDatav : public QObject
{
  Q_OBJECT
 public:
  explicit UXDatav(Q3DSurface *surface);
  ~UXDatav();

    void setAxisXRange(float min, float max);
    void setAxisZRange(float min, float max);
    void fillSqrtSinProxy();
    void enableSqrtSinMode(bool enable);
    void setgradtoriget();
    void setgradtoleft();
    void changetoxslice(){graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndColumn
                                                  |QAbstract3DGraph::SelectionSlice);}
    void changetoyslice(){graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow|
                                                  QAbstract3DGraph::SelectionSlice);}
    void changetopoint(){graph->setSelectionMode(QAbstract3DGraph::SelectionItem);}
    void tosurf();
    void towire();
    void toonlywire();
    void changePresetCamera();
    void informselectchange();

    Q3DSurface* getgraph();

 private:
  Q3DSurface *graph;
  int starts = 1;
  QSurfaceDataProxy *proxy;
  QSurface3DSeries *series;
  QPropertyAnimation m_animationCameraX;
  QPropertyAnimation m_animationCameraY;

  float rangeMinx;
  float rangeMaxz;
  float step_x;
  float step_z;



  
};
#endif

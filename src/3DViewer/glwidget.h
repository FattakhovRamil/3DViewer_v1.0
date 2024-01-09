#ifndef GLWIDGET_H
#define GLWIDGET_H

// #include <QOpenGLFunctions>

#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
// #include <GLUT/glut.h>
// #include <OpenGL/gl.h>
#include <QMouseEvent>
// #include <QMovie>
// #include <QLabel>
#include <QList>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QTimer>

extern "C" {
#include "../back/s21_viewer.h"
}

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  GLWidget(QWidget *parent = 0);
  ~GLWidget();
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);
  void MoveObj();
  void RoteObj();
  void ScaleObj();
  void Getting_max_min();

  const char *str;
  data_struct data1;
  char *str_test;
  char *obj_path;
  float z;
  float y;

  double min_x;
  double max_x;
  double min_y;
  double max_y;
  double min_z;
  double max_z;
  int vertices_count;
  int vertices_count_1;
  double centerX;
  double centerY;
  double centerZ;
  int count_arr;
  double count;
  double move_x_old;
  double move_x;

  double move_y;
  double move_y_old;

  double move_z;
  double move_z_old;

  double rotation_x;
  double rotation_x_old;

  double rotation_y;
  double rotation_y_old;

  double rotation_z;
  double rotation_z_old;

  double scale_obj;
  double scale_obj_old;

 public slots:
};

#endif  // GLWIDGET_H

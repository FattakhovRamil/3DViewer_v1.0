#include "glwidget.h"

#include <cstring>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
  data_struct data1 = {0};
  char *obj_path = nullptr;
  double move_x_old = 0;
  double move_y_old = 0;
  double move_z_old = 0;
  double rotation_x_old = 0;
  double rotation_y_old = 0;
  double rotation_z_old = 0;
  double scale_obj_old = 0;
  double scale_obj = 1;
  // double move_x = 0;
  double count = 0;
}

GLWidget::~GLWidget() {
  remove_data(&data1);
  delete[] obj_path;
}

void GLWidget::initializeGL() {
  QOpenGLWidget::initializeGL();
  initializeOpenGLFunctions();
}

void GLWidget::paintGL() {
  makeCurrent();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  ScaleObj();
  MoveObj();
  RoteObj();
  initializeOpenGLFunctions();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(data1.min_x * 1.5, data1.min_x * 1.5, data1.max_x * 1.5,
          data1.max_y * 1.5, data1.min_z * 100, data1.max_z * 100);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, data1.coord_vert);
  glDrawElements(GL_LINES, data1.num_vert_in_pol, GL_UNSIGNED_INT,
                 data1.polygons);
  glDisableClientState(GL_VERTEX_ARRAY);
  update();
}

void GLWidget::resizeGL(int w, int h)  // Вызывается при изменение размеров окна
{
  glViewport(0, 0, w, h);  // Облость видемости нашего окна
  glMatrixMode(GL_PROJECTION);  // устанавливаем перспективную проекцию
  glLoadIdentity();
}

void GLWidget::MoveObj() {
  if (move_x != move_x_old) {
    transition(&data1, -(move_x_old - move_x), 0);
    move_x_old = move_x;
  }
  if (move_y != move_y_old) {
    transition(&data1, -(move_y_old - move_y), 1);
    move_y_old = move_y;
  }
  if (move_z != move_z_old) {
    transition(&data1, -(move_z_old - move_z), 2);
    move_z_old = move_z;
  }
}

void GLWidget::RoteObj() {
  if (rotation_x != rotation_x_old) {
    rotation_by_x(&data1, -(rotation_x_old - rotation_x));
    rotation_x_old = rotation_x;
  }
  if (rotation_y != rotation_y_old) {
    rotation_by_y(&data1, -(rotation_y_old - rotation_y));
    rotation_y_old = rotation_y;
  }
  if (rotation_z != rotation_z_old) {
    rotation_by_z(&data1, -(rotation_z_old - rotation_z));
    rotation_z_old = rotation_z;
  }
}

void GLWidget::ScaleObj() {
  int zero_count = 0;
  if (scale_obj != scale_obj_old) {
    if (scale_obj == 0) {
      zero_count = 1;
      count = 0;
    }
  }
  if (scale_obj > 0) {
    if (count == 0) {
      scale_data(&data1, 2);
      if (zero_count != 1) {
        count++;
      }
    } else {
      scale_data(&data1, (scale_obj / scale_obj_old));
    }
  } else if (scale_obj < 0) {
    scale_obj *= -1;
    if (count == 0) {
      scale_data(&data1, 0.5);
      if (zero_count != 1) {
        count++;
      }
    } else {
      scale_data(&data1, 1 / (scale_obj / scale_obj_old));
    }
  }
  scale_obj_old = scale_obj;
}

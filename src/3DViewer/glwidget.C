#include <cstring>

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void GLWidget::initializeGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 800, 600, 0, 0, 1);
}

void GLWidget::paintGL() {
  MatrixFill();  // заполнение матрицы
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // openglColor(Qt::red);
  if (str_test == NULL) {
    glBegin(GL_LINE_LOOP);
    glVertex2i(mPosition.x(), mPosition.y());
    glVertex2i(mPosition.x() + 100, mPosition.y() + 100);
    glVertex2i(mPosition.x(), mPosition.y() + 100);
    glEnd();
  } else {
    for (unsigned int i = 0; i < data.count_facets; i++) {
      glBegin(GL_POLYGON);
      for (int j = 0; j < data.polygons[i].numbers_vertexes_in_facets; j++) {
        int vertexIndex = data.polygons[i].vertexes[j];
        // Используйте данные из data.matrix_3d для получения координат вершин
        double x = data.matrix_3d.matrix[vertexIndex][0];
        double y = data.matrix_3d.matrix[vertexIndex][1];
        double z = data.matrix_3d.matrix[vertexIndex][2];
        glVertex3d(x, y, z);
      }
      glEnd();
    }
  }
}

void GLWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void GLWidget::mousePressEvent(QMouseEvent *apEvent) {
  mPosition = apEvent->pos();
}

void GLWidget::MatrixFill() {
  // const char * str = qPrintable(str_test);

  data_struct data = {0};
  int result = main_parser(str_test, &data);
  show_matrix(data);
}

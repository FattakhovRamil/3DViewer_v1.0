#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
//        glVertexPointer(3,GL_FLOAT, 0, &arr); //Сколько переменных на 1
//        вершину, тип, смещение, адрес glEnableClientState(GL_VERTEX_ARRAY); //
//        Разрешаем использовать буфер
//             glColor3d(1,0,0);
//            glDrawArrays(GL_TRIANGLES,0, 3);

//        glDisableClientState(GL_VERTEX_ARRAY);
//        glBegin(GL_TRIANGLES);
//        glColor3d(1,0,0); // цвет треугольника

//        //glVertex3d(0,1, -1.5);
//        glEnd();
//        if (0) {
//    glBegin(GL_LINE_LOOP); // Чтобы что-то отрисовывать и что именно будем
//        glVertex2i(mPosition.x(),mPosition.y());
//        glVertex2i(mPosition.x() + 100,mPosition.y()+100);
//        glVertex2i(mPosition.x(),mPosition.y() + 100);
//    glEnd();
//    } else {
//        for (unsigned int i = 0; i < data1.count_facets; i++) {
//   glBegin(GL_POLYGON);
//              for (int j = 0; j <
//              data1.polygons[i].numbers_vertexes_in_facets; j++) {
//                  int vertexIndex = data1.polygons[i].vertexes[j];
//                  // Используйте данные из data.matrix_3d для получения
//                  координат вершин double x =
//                  data1.matrix_3d.matrix[vertexIndex][0]; double y =
//                  data1.matrix_3d.matrix[vertexIndex][1]; double z =
//                  data1.matrix_3d.matrix[vertexIndex][2]; glVertex3d(x, y, z);
//              }
//              glEnd();

//   }
//}\

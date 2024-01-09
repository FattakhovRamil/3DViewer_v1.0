#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QString>
#include <fstream>
#include <iostream>
#include <string>

#include "glwidget.h"
// #include <QSlider>
#include "../back/s21_viewer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  char* convertQStringToChar(const QString& qstr);
  QString str_1;
  char* str_3;
  char* str_old;
  // GLWidget GLWidget;

  void printFirstTenLines(const std::string& filename);
 private slots:
  void on_open_obj_clicked();

  void on_move_x_valueChanged(int value);
  void on_move_x_Box_valueChanged(double arg1);

  void on_move_y_valueChanged(int value);
  void on_move_y_Box_valueChanged(double arg1);

  void on_move_z_valueChanged(int value);
  void on_move_z_Box_valueChanged(double arg1);

  void on_rotation_x_valueChanged(int value);
  void on_rotation_x_Box_valueChanged(double arg1);

  void on_rotation_y_valueChanged(int value);
  void on_rotation_y_Box_valueChanged(double arg1);

  void on_rotation_z_valueChanged(int value);
  void on_rotation_z_Box_valueChanged(double arg1);

  void on_scale_obj_valueChanged(int value);

  void on_scale_obj_Box_valueChanged(double arg1);

 private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H

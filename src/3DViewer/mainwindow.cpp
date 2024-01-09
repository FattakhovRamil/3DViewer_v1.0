#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // connect(ui->move_x, &QSlider::valueChanged, this,
  // &MainWindow::on_move_x_valueChanged);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_open_obj_clicked() {
  str_1 = QFileDialog::getOpenFileName(
      0, "Open file", QDir::homePath(),
      "Файлы формата .obj (*.obj)");  // получаем имя файла const char * str =

  qPrintable(str_1);
  QByteArray byteArray = str_1.toUtf8();
  char *str_3 = byteArray.data();
  printf("%s str_3\n", str_3);
  if (!str_1.isEmpty()) {
    if (this->ui && this->ui->GLwidget) {
      if (!(this->ui->GLwidget->obj_path == nullptr)) {
        delete[] this->ui->GLwidget->obj_path;
        this->ui->GLwidget->obj_path = nullptr;
      }
      this->ui->GLwidget->obj_path = new char[strlen(str_3) + 1];
      remove_data(&(this->ui->GLwidget->data1));

      main_parser(str_3, &(this->ui->GLwidget->data1), 1);
      int lastIndex = str_1.lastIndexOf('/');

      ui->file_name->setText("Название: " + str_1.mid(lastIndex + 1));

      ui->count_vertex->setText(
          "Кол-во вершин: " +
          QString::number(this->ui->GLwidget->data1.count_vertexes));
      ui->count_facets->setText(
          "Кол-во ребер: " +
          QString::number(this->ui->GLwidget->data1.count_facets));

      ui->move_x_Box->setValue(0);
      ui->move_y_Box->setValue(0);
      ui->move_z_Box->setValue(0);

      ui->rotation_x_Box->setValue(0);
      ui->rotation_y_Box->setValue(0);
      ui->rotation_z_Box->setValue(0);
      this->ui->GLwidget->move_x_old = 0;
      this->ui->GLwidget->move_y_old = 0;
      this->ui->GLwidget->move_z_old = 0;
      this->ui->GLwidget->rotation_x_old = 0;
      this->ui->GLwidget->rotation_y_old = 0;
      this->ui->GLwidget->rotation_z_old = 0;
      this->ui->GLwidget->scale_obj_old = 0;
      this->ui->GLwidget->scale_obj = 0;
      this->ui->GLwidget->count = 0;
    }
  } else {
  }
}

void MainWindow::on_move_x_valueChanged(int value) {
  double doubleValue_x_box = static_cast<double>(value);
  //  ui->move_x_Box->setValue(doubleValue_x_box);
  this->ui->GLwidget->move_x = doubleValue_x_box / 10;
}

void MainWindow::on_move_x_Box_valueChanged(double arg1) {
  double doubleValue_x = static_cast<double>(arg1);
  //  ui->move_x->setValue(doubleValue_x);
  this->ui->GLwidget->move_x = doubleValue_x / 10;
}

// ---------------

void MainWindow::on_move_y_valueChanged(int value) {
  double doubleValue_y_box = static_cast<double>(value);
  ui->move_y_Box->setValue(doubleValue_y_box);
  this->ui->GLwidget->move_y = doubleValue_y_box / 10;
}

void MainWindow::on_move_y_Box_valueChanged(double arg1) {
  double doubleValue_y = static_cast<double>(arg1);
  // ui->move_y->setValue(doubleValue_y);
  this->ui->GLwidget->move_y = doubleValue_y / 10;
}

void MainWindow::on_move_z_valueChanged(int value) {
  double doubleValue_z_box = static_cast<double>(value);
  ui->move_z_Box->setValue(doubleValue_z_box);
  this->ui->GLwidget->move_z = doubleValue_z_box / 10;
}

void MainWindow::on_move_z_Box_valueChanged(double arg1) {
  double doubleValue_z = static_cast<double>(arg1);
  // ui->move_z->setValue(doubleValue_z);
  this->ui->GLwidget->move_z = doubleValue_z / 10;
}

void MainWindow::on_rotation_x_valueChanged(int value) {
  double doubleValue_x_box = static_cast<double>(value);
  ui->rotation_x_Box->setValue(doubleValue_x_box);
  this->ui->GLwidget->rotation_x = doubleValue_x_box;
}

void MainWindow::on_rotation_x_Box_valueChanged(double arg1) {
  double doubleValue_x = static_cast<double>(arg1);
  // ui->rotation_x->setValue(doubleValue_x);
  this->ui->GLwidget->rotation_x = doubleValue_x;
}

//--------------------------------------------------------
void MainWindow::on_rotation_y_valueChanged(int value) {
  double doubleValue_y_box = static_cast<double>(value);
  ui->rotation_y_Box->setValue(doubleValue_y_box);
  this->ui->GLwidget->rotation_y = doubleValue_y_box;
}

void MainWindow::on_rotation_y_Box_valueChanged(double arg1) {
  double doubleValue_y = static_cast<double>(arg1);
  // ui->rotation_y->setValue(doubleValue_y);
  this->ui->GLwidget->rotation_y = doubleValue_y;
}

void MainWindow::on_rotation_z_valueChanged(int value) {
  double doubleValue_z_box = static_cast<double>(value);
  ui->rotation_z_Box->setValue(doubleValue_z_box);
  this->ui->GLwidget->rotation_z = doubleValue_z_box;
}

void MainWindow::on_rotation_z_Box_valueChanged(double arg1) {
  double doubleValue_z = static_cast<double>(arg1);
  // ui->rotation_z->setValue(doubleValue_z);
  this->ui->GLwidget->rotation_z = doubleValue_z;
}

void MainWindow::on_scale_obj_valueChanged(int value) {
  double scale_obj_box = static_cast<double>(value);
  ui->scale_obj_Box->setValue(scale_obj_box);
  this->ui->GLwidget->scale_obj = scale_obj_box;
}

void MainWindow::on_scale_obj_Box_valueChanged(double arg1) {
  double scale_obj_box = static_cast<double>(arg1);
  // ui->scale_obj->setValue(scale_obj_box);
  this->ui->GLwidget->scale_obj = scale_obj_box;
}

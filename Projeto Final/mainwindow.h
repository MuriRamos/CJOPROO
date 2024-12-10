#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

   public:
     MainWindow(QWidget *parent = nullptr);
     ~MainWindow();

   private slots:
     void digitPressed();
     void unaryOperationPressed();
     void binaryOperationPressed();
     void equalsPressed();
     void clearPressed();

   private:
     Ui::MainWindow *ui;
     double currentVal {0.0};
     double lastVal {0.0};
     bool addOpPressed {false};
     bool subOpPressed {false};
     bool mulOpPressed {false};
     bool divOpPressed {false};
};
#endif // MAINWINDOW_H

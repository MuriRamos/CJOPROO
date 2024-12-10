#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   connect(ui->button0, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button1, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button2, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button3, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button4, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button5, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button6, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button7, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button8, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->button9, SIGNAL(released()), this, SLOT(digitPressed()));
   connect(ui->buttonAdd, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
   connect(ui->buttonSub, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
   connect(ui->buttonMul, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
   connect(ui->buttonDiv, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
   connect(ui->buttonEqual, SIGNAL(released()), this, SLOT(equalsPressed()));
   connect(ui->buttonClear, SIGNAL(released()), this, SLOT(clearPressed()));
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::digitPressed()
{
   QPushButton *button = (QPushButton *)sender();
   QString buttonValue = button->text();
   QString displayValue = ui->display->text();

   if ((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0))
   {
      ui->display->setText(buttonValue);
   }
   else
   {
      QString newValue = displayValue + buttonValue;
      double dblNewValue = newValue.toDouble();
      ui->display->setText(QString::number(dblNewValue, 'g', 16));
   }
}

void MainWindow::unaryOperationPressed()
{
   // Implement unary operations if needed (like square root, etc.)
}

void MainWindow::binaryOperationPressed()
{
   QPushButton *button = (QPushButton *)sender();
   QString buttonValue = button->text();
   lastVal = ui->display->text().toDouble();
   ui->display->clear();

   if (buttonValue == "+")
   {
      addOpPressed = true;
   }
   else if (buttonValue == "-")
   {
      subOpPressed = true;
   }
   else if (buttonValue == "*")
   {
      mulOpPressed = true;
   }
   else if (buttonValue == "/")
   {
      divOpPressed = true;
   }
}

void MainWindow::equalsPressed()
{
   double result {0.0};
   currentVal = ui->display->text().toDouble();

   if (addOpPressed)
   {
      result = lastVal + currentVal;
      addOpPressed = false;
   }
   else if (subOpPressed)
   {
      result = lastVal - currentVal;
      subOpPressed = false;
   }
   else if (mulOpPressed)
   {
      result = lastVal * currentVal;
      mulOpPressed = false;
   }
   else if (divOpPressed)
   {
      if (currentVal == 0.0)
       {
          ui->display->setText("ERROR");
          return;
       }
       result = lastVal / currentVal;
       divOpPressed = false;
    }

    ui->display->setText(QString::number(result, 'g', 16));
}

void MainWindow::clearPressed()
{
   currentVal = 0.0;
   lastVal = 0.0;
   ui->display->setText(QString::number(currentVal, 'g', 16));
}

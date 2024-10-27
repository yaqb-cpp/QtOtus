#include <QWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(appendDigit()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(onButtonDot()));
    connect(ui->pushButton_PLUS, SIGNAL(clicked()), this, SLOT(operators()));
    connect(ui->pushButton_DIVIDE, SIGNAL(clicked()), this, SLOT(operators()));
    connect(ui->pushButton_MINUS, SIGNAL(clicked()), this, SLOT(operators()));
    connect(ui->pushButton_MULTI, SIGNAL(clicked()), this, SLOT(operators()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(percent()));
    connect(ui->pushButton_EQUAL, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(onButtonAC()));
    ui->pushButton_PLUS->setCheckable(true);
    ui->pushButton_DIVIDE->setCheckable(true);
    ui->pushButton_MINUS->setCheckable(true);
    ui->pushButton_MULTI->setCheckable(true);
    ui->lineResult->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_equal_clicked(){
    double labelNumber, second_num;
    QString str_number;
    second_num = ui->lineResult->text().toDouble();

    if(ui->pushButton_PLUS->isChecked()){
        labelNumber = first_num + second_num;
        str_number = QString::number(labelNumber,'g',15);
        ui->lineResult->setText(str_number);
        ui->pushButton_PLUS->setChecked(false);
    }
    else if(ui->pushButton_DIVIDE->isChecked()) {
        labelNumber = first_num / second_num;
        str_number = QString::number(labelNumber,'g',15);
        ui->lineResult->setText(str_number);
        ui->pushButton_DIVIDE->setChecked(false);
    }
    else if(ui->pushButton_MINUS->isChecked()) {
        labelNumber = first_num - second_num;
        str_number = QString::number(labelNumber,'g',15);
        ui->lineResult->setText(str_number);
        ui->pushButton_MINUS->setChecked(false);
    }
    else if(ui->pushButton_MULTI->isChecked()){
        labelNumber = first_num * second_num;
        str_number = QString::number(labelNumber,'g',15);
        ui->lineResult->setText(str_number);
        ui->pushButton_MULTI->setChecked(false);
    }
}
void MainWindow::operators(){
    first_num = ui->lineResult->text().toDouble();
    qDebug() << first_num;
    QPushButton *button = (QPushButton*) sender();
    button->setChecked(true);
    ui->lineResult->setText("0");
}
void MainWindow::percent(){
    QPushButton *button = (QPushButton*)sender();
    double number;
    QString str_number;
    if(button->text()=="%"){
        number = (ui->lineResult->text()).toDouble();
        number = number * 0.01;
        str_number = QString::number(number,'g',15);
        ui->lineResult->setText(str_number);
    }
}

void MainWindow::onButtonAC()
{
    ui->lineResult->setText("0");
    ui->pushButton_PLUS->setChecked(false);
    ui->pushButton_DIVIDE->setChecked(false);
    ui->pushButton_MINUS->setChecked(false);
    ui->pushButton_MULTI->setChecked(false);
}
void MainWindow::onButtonDot(){
    if(!ui->lineResult->text().contains('.'))
        ui->lineResult->setText(ui->lineResult->text() + '.');
}
void MainWindow::appendDigit()
{
    QPushButton *button = (QPushButton*)sender();
    double number;
    QString str_number;
    if(ui->lineResult->text().contains(".") && button->text()=="0"){
        str_number = ui->lineResult->text() + button->text();
    }
    else{
    number = (ui->lineResult->text() + button->text()).toDouble();
    str_number = QString::number(number, 'g', 15);
    }
    ui->lineResult->setText(str_number);
}

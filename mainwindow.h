#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_equal_clicked();
    void operators();
    void appendDigit();
    void onButtonDot();
    void percent();
    void onButtonAC();
private:
    double first_num;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

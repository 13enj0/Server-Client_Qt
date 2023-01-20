#ifndef REGISTR_H
#define REGISTR_H

#include <QMainWindow>
#include <mainwindow.h>
#include <QPainter>
namespace Ui {
class Registr;
}

class Registr : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registr(QWidget *parent = nullptr);
    ~Registr();


protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

signals:
      void signal(QString);

private:
    Ui::Registr *ui;
    MainWindow *MainWindows;
    void SetInterfaceStyle();
};

#endif // REGISTR_H

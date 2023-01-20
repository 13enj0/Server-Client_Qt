#include "registr.h"
#include "ui_registr.h"
#include <QErrorMessage>
#include "style.h"
#include <QStyleOption>
Registr::Registr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registr)
{
    ui->setupUi(this);
    this->setWindowIcon(QPixmap(":/image/bebra.png"));
    MainWindows = new MainWindow();

    connect(this, &Registr::signal, MainWindows, &MainWindow::slot );
     SetInterfaceStyle();

}

Registr::~Registr()
{
    delete ui;
}




void Registr::on_pushButton_clicked()
{

    if(ui->lineEdit->text() != "")
    {
        if(ui->lineEdit->text().length() <= 18 )
        {
            emit signal(ui->lineEdit->text());
            MainWindows->show();
            this->close();
        }
        else
        {
           (new QErrorMessage(this))->showMessage("перевищена кількість допустимих символів: '18' ");
        }
    }
}


void Registr::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text() != "")
    {
        if(ui->lineEdit->text().length() <= 18)
        {
            emit signal(ui->lineEdit->text());
            MainWindows->show();
            this->close();
        }
        else
        {
           (new QErrorMessage(this))->showMessage("перевищена кількість допустимих символів: '18' ");
        }
    }
}

void Registr::SetInterfaceStyle()
{

    ui->centralwidget->setStyleSheet(Style::getMainWidgetStyle());
     ui->lineEdit->setStyleSheet(Style::getLineEditlStyle());
     ui->label->setStyleSheet(Style::getLabelStyle());
 ui->pushButton->setStyleSheet(Style::getStartButtonsStyle());
}

void Registr::paintEvent(QPaintEvent *event)
{
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget:: paintEvent(event);

}


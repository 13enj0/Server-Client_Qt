#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include <QStyleOption>
#include <QPainter>
#include <QFont>
#include <QColorDialog>
#include <QColor>
int n = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowIcon(QPixmap(":/image/bebra.png"));

    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;
    SetInterfaceStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slot(QString a)
{

    user = a;
    socket->connectToHost("26.137.112.166", 2323);
    SendToServer("Connect user: " + user);
    }

void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out<< quint16(0)<< QTime::currentTime()<<str;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));

    socket->write(Data);
    ui->lineEdit->clear();

}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status()==QDataStream::Ok)
    {


        for(;;)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in>>nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            QTime time;
            in>>time>>str;
            nextBlockSize = 0; 
            QString struser;

            if(str.contains("5754456542Connect user: ") )
            {
                if(n == 0){
                     ui->textBrowser_2->append("   Users server: ");
                }
                for(int i = 24;i< str.length(); i++)
                {
                    struser += str.at(i);
                }


                   ui->textBrowser_2->append( struser + ";");
                n++;


            }
            else if( str.contains("Connect user: "))
            {
            ui->textBrowser_2->append(time.toString()+ " " + str);

            }
            else if(str.contains("emoji.trololo"))
            {
                ui->textBrowser->append("░░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄▄\n"
                                        "░░░░░█░░░░░░░░░░░░░░░░░░▀▀▄\n"
                                        "░░░░█░░░░░░░░░░░░░░░░░░░░░░█\n"
                                        "░░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░░█\n"
                                        "░▄▀░▄▄▄░░█▀▀▀▀▄▄█░░░██▄▄█░░░░█\n"
                                        "█░░█░▄░▀▄▄▄▀░░░░░░░░█░░░░░░░░░█\n"
                                        "█░░█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄░█\n"
                                        "░█░▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█\n"
                                        "░░█░░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█\n"
                                        "░░░█░░░░██░░▀█▄▄▄█▄▄█▄▄██▄░░█\n"
                                        "░░░░█░░░░▀▀▄░█░░░█░█▀█▀█▀██░█\n"
                                        "░░░░░▀▄░░░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█\n"
                                        "░░░░░░░▀▄▄░░░░░░░░░░░░░░░░░░░█\n"
                                        "░░▐▌░█░░░░▀▀▄▄░░░░░░░░░░░░░░░█\n"
                                        "░░░█▐▌░░░░░░█░▀▄▄▄▄▄░░░░░░░░█\n"
                                        "░░███░░░░░▄▄█░▄▄░██▄▄▄▄▄▄▄▄▀\n"
                                        "░▐████░░▄▀█▀█▄▄▄▄▄█▀▄▀▄\n"
                                        "░░█░░▌░█░░░▀▄░█▀█░▄▀░░░█\n"
                                        "░░█░░▌░█░░█░░█░░░█░░█░░█\n"
                                        "░░█░░▀▀░░██░░█░░░█░░█░░█\n"
                                        "░░░▀▀▄▄▀▀░█░░░▀▄▀▀▀▀█░░█\n"
                                        "░░░░░░░░░░█░░░░▄░░▄██▄▄▀\n"
                                        "░░░░░░░░░░█░░░░▄░░████\n"
                                        "░░░░░░░░░░█▄░░▄▄▄░░▄█\n"
                                        "░░░░░░░░░░░█▀▀░▄░▀▀█\n"
                                        "░░░░░░░░░░░█░░░█░░░█\n"
                                        "░░░░░░░░░░░█░░░▐░░░█\n"
                                        "░░░░░░░░░░░█░░░▐░░░█\n"
                                        "░░░░░░░░░░░█░░░▐░░░█\n"
                                        "░░░░░░░░░░░█░░░▐░░░█\n"
                                        "░░░░░░░░░░░█░░░▐░░░█\n"
                                        "░░░░░░░░░░░█▄▄▄▐▄▄▄█\n"
                                        "░░░░░░░▄▄▄▄▀▄▄▀█▀▄▄▀▄▄▄▄\n"
                                        "░░░░░▄▀▄░▄░▄░░░█░░░▄░▄░▄▀▄\n"
                                        "░░░░░█▄▄▄▄▄▄▄▄▄▀▄▄▄▄▄▄▄▄▄█");
            }

            else
            {


                ui->textBrowser->append( "  " + str + "  ");

            }
        }
    }
    else
    {

        ui->textBrowser_2->append("read error");
    }
}




void MainWindow::on_pushButton_2_clicked()
{
    QString message = user +": " + ui->lineEdit->text();

    if(ui->lineEdit->text() != "")
    {
        SendToServer(message);
    }

}


void MainWindow::on_lineEdit_returnPressed()
{

    QString message = user +": " + ui->lineEdit->text();

    if(ui->lineEdit->text() != "")
    {
        SendToServer(message);
    }

}


void MainWindow::on_pushButton_clicked()
{
    n = 0;
    SendToServer("Users conect to server?");
}

void MainWindow::SetInterfaceStyle()
{
    ui->centralwidget->setStyleSheet(Style::getMainWidgetStyle());
    ui->textBrowser->setStyleSheet(Style::getTextBrowserStyle());
    ui->textBrowser_2->setStyleSheet(Style::getTextBrowserStyle2());
    ui->lineEdit->setStyleSheet(Style::getLineEditMainWindowStyle());
    ui->pushButton_2->setStyleSheet(Style::getButtonMainWindowStyle());
    ui->pushButton->setStyleSheet(Style::getButtonRegistrUsersStyle());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget:: paintEvent(event);

}

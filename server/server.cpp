#include "server.h"

#include <QTime>
int n = -1;
 QString *users = new QString[50];
Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323))
    {
            qDebug()<<"start";

}
    else
    {
     qDebug()<<"ERROR";
    }
    nextBlockSize = 0;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);//індефікатор ввод-вивод
    connect(socket, SIGNAL(readyRead()),this, SLOT(slotReadyRead()) );
    connect(socket, SIGNAL(disconnected()),this, SLOT(sockDisc()) );


    n++;
    Socket.push_back(socket);
    qDebug()<<"client connected"<<socketDescriptor;


}
void Server::slotReadyRead()
{

        socket = (QTcpSocket*)sender();
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_6_2);


    if(in.status()==QDataStream::Ok)
        {
            qDebug()<<"read...";


            for(;;)
            {
                if(nextBlockSize == 0)
                {

                    if(socket->bytesAvailable() < 2)
                    {
                        qDebug()<<"Data < 2, break!!";
                        break;
                    }
                    in>>nextBlockSize;
                    qDebug()<<"nextBlockSize = "<<nextBlockSize;
                }
                if(socket->bytesAvailable() < nextBlockSize)
                {
                    qDebug()<<"Data not full, break";
                    break;
                }

                QString str;
                QTime time;
                in >> time >>str;
                nextBlockSize = 0;
                qDebug()<< str <<"\n";

                if(str.contains("Connect user: "))
                {
                    for(int i = 14; i < str.length(); i++)
                    {
                        QString s = str;
                        s.at(i);
                        users[n] ="5754456542"+ str;
                    }




                }

                if(str == "Users conect to server?")
                {


                    for(int i = 0; i<= n; i++)
                    {
                       SendToClient( users[i]);
                    }

                }
                else
                {
                SendToClient(str);
                }
                break;
            }
        }
        else
        {
            qDebug()<<"DataStream error";
        }

}



void Server::SendToClient(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out<< quint16(0)<< QTime::currentTime() <<str;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));

    //socket->write(Data);

    for(int i =0; i < Socket.size(); i++)
    {
        Socket[i]->write(Data);
    }
}
void Server::sockDisc()
{

    qDebug()<<"Disconnect";

}


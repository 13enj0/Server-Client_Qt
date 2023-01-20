#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QtcpSocket>

class Server : public QTcpServer
{

    Q_OBJECT

public:
     Server();
     QTcpSocket *socket;//створення сокета
private:
     QVector <QTcpSocket*> Socket;//вeктор для сокета
     QByteArray Data;//інформація що передається
     void SendToClient(QString str);//отправка кілєнту
     quint16 nextBlockSize;


public slots:
     void incomingConnection(qintptr socketDescriptor);//провірка нових підключень
     void slotReadyRead();//обработчик получених даних від клієнта
    void sockDisc();




};





#endif // SERVER_H

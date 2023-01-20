#ifndef SERVERCONSOLE_H
#define SERVERCONSOLE_H

#include <QMainWindow>

namespace Ui {
class ServerConsole;
}

class ServerConsole : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerConsole(QWidget *parent = nullptr);
    ~ServerConsole();

private:
    Ui::ServerConsole *ui;
};

#endif // SERVERCONSOLE_H

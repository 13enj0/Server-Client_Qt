#include "serverconsole.h"
#include "ui_ServerConsole.h"

ServerConsole::ServerConsole(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerConsole)
{
    ui->setupUi(this);
}

ServerConsole::~ServerConsole()
{
    delete ui;
}

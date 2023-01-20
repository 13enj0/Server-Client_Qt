#include "style.h"



QString Style::getMainWidgetStyle()
{
    return "QWidget{"

            "background-image: url(:/image/1.jpg);"

            "}";
}

QString Style::getStartButtonsStyle()
{
    return "QPushButton{"
            "color: black;"
            "background: none;"

            "background-color: rgb(37, 148, 156);"
            "border: 2px solid black;"
            "border-radius: 10;"
           "}";
}

QString Style::getLineEditlStyle()
{
    return "    QLineEdit{  "
            "   background: none;    "
            "   background-color: white;    "
            "   Color: black;   "
            "   border: 1px solid black;    "
            "   border-radius: 5;   "
           "   }   ";
}

QString Style::getLabelStyle()
{
    return "QLabel{"
            "Color: white;"
           "}";
}

QString Style::getTextBrowserStyle()
{
    return "QTextBrowser{"
            "Color: black;"
            "background: none;"
            "background-color: rgba(255, 255, 255, 245);"
            "font: 12pt ;"
            "border-radius: 9;"
           "}";
}

QString Style::getTextBrowserStyle2()
{
    return "QTextBrowser{"
            "Color: black;"
            "background: none;"
            "background-color: rgb(230, 230, 230);"
            "font: 12pt ;"
            "border-radius: 9;"
           "}";
}

QString Style::getLineEditMainWindowStyle()
{
    return "    QLineEdit{  "
            "height: 25px;"
            "   background: none;    "
            "   background-color: white;    "
            "   Color: black;   "
            "   border: 1px solid black;    "
            "   border-radius: 8px;   "
           "   }   ";
}

QString Style::getButtonMainWindowStyle()
{
    return "    QPushButton{  "
            "height: 25px;"
            "width: 35px;"
            "   background: none;    "
             "background-color: rgba(255, 255, 255, 135);"
            "   Color: white;   "
            "border: 1px solid white;"
            "   border-radius: 2px;   "
           "   }   ";
}

QString Style::getButtonRegistrUsersStyle()
{
    return "    QPushButton{  "
            "height: 30px;"
            "   background: none;    "
            "background-color: rgba(0, 0, 0, 130);"
            "   Color: white;   "
            "border: 1px solid white;"
            "   border-radius: 2px;   "
           "   }   ";
}



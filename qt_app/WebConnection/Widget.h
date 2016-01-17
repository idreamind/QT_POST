#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QPlainTextEdit>

#include "web/WEB.h"

namespace Ui {
    class Widget;
}

//---------------------------------- Class: ------------------------------------
class Widget : public QWidget
{
    Q_OBJECT

public: //------------------------- Public: ------------------------------------
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots: //----------------- Public Slots: --------------------------------

private slots: //--------------- Private Slots: --------------------------------
    void    p_send(void);
    void    p_toBrowser(QString res);

private: //------------------------ Private: -----------------------------------
    Ui::Widget *ui;

    void    p_init(void);

}; //--------------------------------- End -------------------------------------

#endif // WIDGET_H

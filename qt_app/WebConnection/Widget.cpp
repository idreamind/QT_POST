#include "Widget.h"
#include "ui_Widget.h"

//------------------------------------------------------------------------------
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->p_init();
}
//------------------------------------------------------------------------------
Widget::~Widget()
{
    delete ui;
}
//------------------------------------------------------------------------------
void Widget::p_init()
{
    WEB::inst(this)->c_setHost(QString("localhost"));
    WEB::inst(this)->c_setPort(QString("3000"));
    WEB::inst(this)->c_setPath(QString("/navigation"));

    connect(ui->sendBtn, &QPushButton::clicked, this, &Widget::p_send);
    connect(WEB::inst(), &WEB::s_response, this, &Widget::p_toBrowser);
}
//------------------------------------------------------------------------------
void Widget::p_send()
{
    QString str = ui->requestEditor->toPlainText();
    QStringList list = str.split(QString(" "), QString::SkipEmptyParts);

    QDateTime dt;
    QString time = dt.currentDateTime().toString(QString("yyyy.MM.dd HH:MM:ss"));

    reqList reqlist;
    reqVal val;
    val.key = "lat";
    val.value = (list.length() > 0) ? list.at(0) : tr("53.0518");
    reqlist.append(val);
    val.key = "lon";
    val.value = (list.length() > 1) ? list.at(1) : tr("27.0782");
    reqlist.append(val);
    val.key = "alt";
    val.value = (list.length() > 2) ? list.at(2) : tr("200.00");
    reqlist.append(val);
    val.key = "time";
    val.value = time;
    reqlist.append(val);

    WEB::inst()->c_post(reqlist);
}
//------------------------------------------------------------------------------
void Widget::p_toBrowser(QString res)
{
    ui->responseBrowser->append(res);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

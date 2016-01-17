#include "WEB.h"

WEB *WEB::_web = 0;
//------------------------------------------------------------------------------
WEB::WEB(QObject *parent) : QObject(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    this->p_init();
}
//------------------------------------------------------------------------------
WEB::~WEB()
{
    delete _nam;
    delete _req;
}
//------------------------------------------------------------------------------
WEB *WEB::inst(QObject *parent)
{
    if (!_web) {
        _web = new WEB(parent);
    }
    return _web;
}
//------------------------------------------------------------------------------
void WEB::p_init()
{
    _nam = new QNetworkAccessManager(this);
    connect(_nam, SIGNAL(finished(QNetworkReply*)), SLOT(p_getReply(QNetworkReply*)));

    _req = new QNetworkRequest();
    _req->setHeader(QNetworkRequest::ContentTypeHeader, QString("application/x-www-form-urlencoded"));
    _req->setRawHeader("Content-Type", "application/json");

    _url.setScheme(QString("http"));
}
//------------------------------------------------------------------------------
int WEB::c_post(const QByteArray &data)
{
    int size = data.size();
    _req->setRawHeader("Content-Length", QByteArray::number(size));
    _req->setUrl(_url);

    emit s_request(QString(data));
    _nam->post(*_req, data);
    return size;
}
//------------------------------------------------------------------------------
int WEB::c_post(const QString &path, const QByteArray data)
{
    this->c_setPath(path);
    return this->c_post(data);
}
//------------------------------------------------------------------------------
int WEB::c_post(const reqList data)
{
    QByteArray arr = this->p_createJsonArray(data);
    return this->c_post(arr);
}
//------------------------------------------------------------------------------
int WEB::c_post(const QString &path, const reqList data)
{
    this->c_setPath(path);
    QByteArray arr = this->p_createJsonArray(data);
    return this->c_post(arr);
}
//------------------------------------------------------------------------------
void WEB::p_getReply(QNetworkReply *rep)
{
    if (!rep->error()) {
        emit s_response(QString(rep->readAll()));
    } else {
        emit s_error(rep->errorString());
    }
}
//------------------------------------------------------------------------------
QByteArray WEB::p_createJsonArray(const reqList data)
{
    QByteArray arr,
            start ="{\"",
            end = "\"}",
            mid = "\":\"",
            del = "\",\"";

    arr.append(start);
    for (int i = 0; i < data.length(); i++) {
        reqVal req = data.at(i);
        arr.append(req.key);
        arr.append(mid);
        arr.append(req.value.toByteArray());
        if (i != data.length()-1) {
            arr.append(del);
        } else {
            arr.append(end);
        }
    }

    return arr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

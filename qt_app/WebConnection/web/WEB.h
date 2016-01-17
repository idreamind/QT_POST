#ifndef WEB_H
#define WEB_H

#include <QUrl>
#include <QList>
#include <QObject>
#include <QString>
#include <QByteArray>
#include <QTextCodec>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#ifdef QT_DEBUG
#include <QDebug>
#endif

typedef struct {
    QString path;
    QString key;
    QVariant value;
} reqVal;

typedef QList<reqVal> reqList;

//---------------------------------- Class: ------------------------------------
class WEB : public QObject
{
    Q_OBJECT
public: //------------------------- Public: ------------------------------------
    static WEB *inst(QObject *parent = 0);
    ~WEB();

signals: //------------------------ Signals: -----------------------------------
    void    s_error(QString);
    void    s_request(QString);
    void    s_response(QString);

public slots: //----------------- Public Slots: --------------------------------
    void    c_setHost(const QString &host)          { _url.setHost(host); }
    void    c_setPort(const QString &port)          { _url.setPort(port.toInt()); }
    void    c_setPath(const QString &path)          { _url.setPath(path); }

    QString c_getHost(void)                         { return QString::number(_url.port(), 'f', 0); }
    QString c_getPort(void)                         { return _url.host(); }
    QString c_getPath(void)                         { return _url.toString(); }

    int     c_post(const QString &path, const reqList data);
    int     c_post(const reqList data);
    int     c_post(const QString &path, const QByteArray data);
    int     c_post(const QByteArray &data);

private slots: //--------------- Private Slots: --------------------------------
    void    p_getReply(QNetworkReply *rep);

private: //------------------------ Private: -----------------------------------
    explicit WEB(QObject *parent = 0);
    static WEB *_web;

    void    p_init(void);

    QByteArray  p_createJsonArray(const reqList data);

    QNetworkAccessManager   *_nam;
    QNetworkRequest         *_req;
    QUrl                    _url;

}; //--------------------------------- End -------------------------------------

#endif // WEB_H

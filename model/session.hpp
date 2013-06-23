#ifndef TWIRL_SESSION_HPP
#define TWIRL_SESSION_HPP

#include <QSharedDataPointer>

#include <QList>
#include <QString>

class QNetworkCookie;

namespace twirl {

class SessionData;

class Session {

public:
    Session();
    Session(const QString & path);
    Session(const Session & other);
    Session & operator=(const Session & other);
    virtual ~Session();

    bool isNull() const;

    bool save(const QList<QNetworkCookie> & cookies);
    bool load(QList<QNetworkCookie> & cookies);

    QString path() const;
    void setPath(const QString & path);

private:
    QSharedDataPointer<SessionData> d_ptr;
};

}

#endif // TWIRL_SESSION_HPP

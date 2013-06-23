#include "session.hpp"
#include "sessiondata.hpp"

#include <QtNetwork/QNetworkCookie>
#include <QByteArray>

namespace twirl {

Session::Session() : d_ptr(new SessionData()) {}

Session::Session(const QString & path) : d_ptr(new SessionData(path)) {}

Session::Session(const Session & other) : d_ptr(other.d_ptr) {}

Session & Session::operator=(const Session & other) {
    d_ptr = other.d_ptr;
    return *this;
}

Session::~Session() {}

bool Session::load(QList<QNetworkCookie> & cookies) {
    QFile & file = d_ptr->file;

    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    } else {
        bool result = true;

        const QByteArray data = file.readAll();
        if (file.error()) {
            result = false;
        } else {
            cookies = QNetworkCookie::parseCookies(data);
        }

        file.close();
        return result && !cookies.isEmpty();
    }
}

bool Session::save(const QList<QNetworkCookie> & cookies) {
    QFile & file = d_ptr->file;

    if (cookies.isEmpty() || !file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        return false;
    } else {
        bool result = true;

        for(QList<QNetworkCookie>::const_iterator cookie = cookies.begin(); cookie != cookies.end(); ++cookie) {
            const QByteArray chunk(cookie->toRawForm().append("\r\n"));
            if (file.write(chunk) != chunk.size()) {
                result = false;
                break;
            }
        }

        file.close();
        return result;
    }
}

bool Session::isNull() const {
    return d_ptr->file.fileName().isEmpty();
}

QString Session::path() const {
    return d_ptr->file.fileName();
}

void Session::setPath(const QString & path) {
    d_ptr->file.setFileName(path);
}

}


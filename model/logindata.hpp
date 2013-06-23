#ifndef TWIRL_LOGINDATA_HPP
#define TWIRL_LOGINDATA_HPP

#include <QSharedData>

#include <QString>

namespace twirl {

class LoginData : public QSharedData {
public:
    LoginData();
    LoginData(const QString & username, const QString & password);
    virtual ~LoginData();

    QString username;
    QString password;
};

inline LoginData::LoginData() {}

inline LoginData::LoginData(const QString & username, const QString & password) :
    username(username),
    password(password)
{

}

inline LoginData::~LoginData() {}

} /* namespace twirl */

#endif // TWIRL_LOGINDATA_HPP
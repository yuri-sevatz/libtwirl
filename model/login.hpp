#ifndef TWIRL_LOGIN_HPP
#define TWIRL_LOGIN_HPP

#include <QSharedDataPointer>

#include <QString>

namespace twirl {

class LoginData;

class Login {
public:
    Login();
    Login(const QString & username, const QString & password);
    Login(const Login & other);
    Login & operator=(const Login & other);
    virtual ~Login();

    const QString & username() const;
    void setUsername(const QString & username);
    void resetUsername();

    const QString & password() const;
    void setPassword(const QString & password);
    void resetPassword();

    void clear();

private:
    QSharedDataPointer<LoginData> d_ptr;
};

} /* namespace twirl */

#endif // TWIRL_LOGIN_HPP

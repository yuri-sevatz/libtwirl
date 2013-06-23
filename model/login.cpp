#include "login.hpp"
#include "logindata.hpp"

namespace twirl {
    
Login::Login() : d_ptr(new LoginData()) {}

Login::Login(const QString & username, const QString & password) : d_ptr(new LoginData(username, password)) {}

Login::Login(const Login & other) : d_ptr(other.d_ptr) {}

Login & Login::operator=(const Login & other) {
    d_ptr = other.d_ptr;
    return *this;
}

Login::~Login() {}

const QString & Login::username() const {
    return d_ptr->username;
}

void Login::setUsername(const QString & username) {
    d_ptr->username = username;
}

void Login::resetUsername() {
    d_ptr->username.clear();
}

const QString & Login::password() const {
    return d_ptr->password;
}

void Login::setPassword(const QString & password) {
    d_ptr->password = password;
}

void Login::resetPassword() {
    d_ptr->password.clear();
}

void Login::clear() {
    d_ptr->username.clear();
    d_ptr->password.clear();
}

} /* namespace twirl */
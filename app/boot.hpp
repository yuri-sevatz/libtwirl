#ifndef LIBTWIRL_BOOTSTRAP_HPP
#define LIBTWIRL_BOOTSTRAP_HPP

#include <qt5/QtCore/QSharedDataPointer>

class QCoreApplication;

namespace twirl {

class BootData;

class Boot {
public:
    Boot(QCoreApplication & app);
    virtual ~Boot();

public:
    virtual int main() = 0;

private:
    Boot();
    Q_DISABLE_COPY(Boot);

    QSharedDataPointer<BootData> d_ptr;
};

}

#endif // LIBTWIRL_BOOTSTRAP_HPP

#ifndef BOOTSTRAP_HPP
#define BOOTSTRAP_HPP

#include <QObject>

class QCoreApplication;

namespace twirl {

class Bootstrap : public QObject {
    Q_OBJECT
public:
    Bootstrap();
    virtual ~Bootstrap();

    void init(QCoreApplication & app);

protected:
    virtual void main() = 0;
    Q_SIGNAL void quit();

private:
    Q_SLOT void run();
};

}

#endif // BOOTSTRAP_HPP

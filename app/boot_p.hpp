#ifndef LIBTWIRL_BOOT_P_HPP
#define LIBTWIRL_BOOT_P_HPP

#include <qt5/QtCore/QObject>
#include <qt5/QtCore/QSharedData>

class QCoreApplication;

namespace twirl {

class Boot;

class BootData : public QObject, public QSharedData {
    Q_OBJECT
public:
    BootData(Boot & boot, QCoreApplication & app);

private:
    BootData();

    Q_SIGNAL void quit();
    Q_SLOT void run();

    Boot & boot;
    QCoreApplication & app;
};

}

#endif // LIBTWIRL_BOOT_P_HPP

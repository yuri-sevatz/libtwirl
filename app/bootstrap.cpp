#include "bootstrap.hpp"

#include <QCoreApplication>
#include <QTimer>

namespace twirl {

Bootstrap::Bootstrap() {
}

Bootstrap::~Bootstrap() {

}

void Bootstrap::init(QCoreApplication & app) {

    QTimer::singleShot(0, this, SLOT(run()));
    QObject::connect(this, SIGNAL(quit()), &app, SLOT(quit()));
}

void Bootstrap::run() {
    main();
    quit();
}

}

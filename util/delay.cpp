#include "delay.hpp"

#include <QCoreApplication>
#include <QTimer>

namespace twirl {

Delay::Delay() {}
Delay::~Delay() {}

void Delay::sleep(int msecs) {
    QTimer::singleShot(msecs, this, SLOT(onFinished()));
    loop = true;
    do {
        QCoreApplication::processEvents();
    } while (loop);
}

void Delay::onFinished() {
    loop = false;
}

}

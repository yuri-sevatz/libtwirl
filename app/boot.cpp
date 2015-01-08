#include "boot.hpp"
#include "boot_p.hpp"

#include <QCoreApplication>
#include <QTimer>

namespace twirl {

BootData::BootData(Boot & boot, QCoreApplication & app) : boot(boot), app(app) {
    QTimer::singleShot(0, this, &BootData::run);
}

void BootData::run() {
    app.exit(boot.main());
}

Boot::Boot(QCoreApplication & app) : d_ptr(new BootData(*this, app)) {}
Boot::~Boot() {}

} /* namespace twirl */

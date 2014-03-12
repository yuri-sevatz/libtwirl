#include "requestloader.hpp"

#include <QCoreApplication>

#include <QtNetwork/QNetworkReply>

namespace twirl {

RequestLoader::RequestLoader() {

}

RequestLoader::~RequestLoader() {

}

QNetworkReply * RequestLoader::load(QNetworkReply * reply) {
    if (reply) {
        QEventLoop loop;
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
    }

    return reply;
}

}
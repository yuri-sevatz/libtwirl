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
        while(!reply->isFinished()) {
            QCoreApplication::processEvents();
        }
    }

    return reply;
}

}
#ifndef TWIRL_REQUESTLOADER_HPP
#define TWIRL_REQUESTLOADER_HPP

#include <QtGlobal>

class QNetworkReply;

namespace twirl {

class RequestLoader {
public:
    RequestLoader();
    virtual ~RequestLoader();

    QNetworkReply * load(QNetworkReply * reply);
private:
    Q_DISABLE_COPY(RequestLoader);
};

}

#endif // TWIRL_REQUESTLOADER_HPP

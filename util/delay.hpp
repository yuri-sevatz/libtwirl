#ifndef TWIRL_DELAY_HPP
#define TWIRL_DELAY_HPP

#include <QObject>

namespace twirl {

class Delay : public QObject {
    Q_OBJECT
public:
    Delay();
    virtual ~Delay();

    void sleep(int msecs);
private:
    Q_DISABLE_COPY(Delay);

    Q_SLOT void onFinished();

    bool loop;
};

}

#endif // TWIRL_DELAY_HPP

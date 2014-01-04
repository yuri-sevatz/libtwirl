#ifndef TWIRL_DOMLOADER_HPP
#define TWIRL_DOMLOADER_HPP

#include <QObject>
#include <QFlags>
#include <QMutex>
#include <QString>

class QWebFrame;

namespace twirl {

class DomLoader : public QObject {
    Q_OBJECT
public:
    DomLoader(QWebFrame & frame);
    virtual ~DomLoader();

    void load();

protected:
    Q_SLOT void onNodeInserted();
    Q_SLOT void onNodeRemoved();

private:
    Q_SLOT void inject();

    enum Change {
        INSERT = 1 << 0,
        REMOVE = 1 << 1,
    };

    Q_DECLARE_FLAGS(Changes, Change);

    void process(Changes to);

    void start(Changes to);
    bool ended(Changes to);

    static const QString hook;

    QWebFrame & frame;
    QMutex lock;
    Changes change;
};

}

#endif // TWIRL_DOMLOADER_HPP

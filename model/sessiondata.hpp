#ifndef TWIRL_SESSIONDATA_HPP
#define TWIRL_SESSIONDATA_HPP

#include <QSharedData>

#include <QFile>

namespace twirl {

class SessionData : public QSharedData {
public:
    SessionData();
    SessionData(const QString & path);
    SessionData(const SessionData & other);
    virtual ~SessionData();

    QFile file;
};

inline SessionData::SessionData() {}

inline SessionData::SessionData(const QString & path) : file(path) {}

inline SessionData::SessionData(const SessionData & other) : file(other.file.fileName()) {}

inline SessionData::~SessionData() {}


} /* namespace twirl */

#endif // TWIRL_SESSIONDATA_HPP
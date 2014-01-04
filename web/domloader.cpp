#include "domloader.hpp"

#include <QCoreApplication>
#include <QMutexLocker>
#include <QWebFrame>

#include <QDebug>

namespace twirl {

const QString DomLoader::hook("cppHook");

DomLoader::DomLoader(QWebFrame & frame) :
    frame(frame)
{
    connect(&frame, SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(inject()));
}

DomLoader::~DomLoader() {}

void DomLoader::inject() {
    qDebug() << "Injecting...";
    frame.addToJavaScriptWindowObject(hook, this);
    frame.evaluateJavaScript("document.addEventListener('DOMNodeInsertedIntoDocument', function(){" + hook + ".onNodeInserted()}, true)");
    frame.evaluateJavaScript("document.addEventListener('DOMNodeRemovedFromDocument', function(){" + hook + ".onNodeRemoved()}, true)");
}

void DomLoader::onNodeInserted() {
    QMutexLocker(&this->lock);
    change |= INSERT;
}

void DomLoader::onNodeRemoved() {
    QMutexLocker(&this->lock);
    change |= REMOVE;
}

void DomLoader::load() {
    process(INSERT);
}

void DomLoader::process(Changes to) {
    start(to);
    do {
        QCoreApplication::processEvents();
    } while(!ended(to));
}

inline void DomLoader::start(Changes to) {
    QMutexLocker(&this->lock);
    change &= !to;
}

inline bool DomLoader::ended(Changes to) {
    QMutexLocker(&this->lock);
    return (change & to) == to;
}

}
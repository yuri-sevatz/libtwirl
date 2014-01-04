#include "pageloader.hpp"

#include <QCoreApplication>

#include <QWebFrame>
#include <QWebPage>

namespace twirl {

PageLoader::PageLoader(QWebPage & page) :
    page(page)
{
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(onLoad(bool)));
}

PageLoader::~PageLoader() {}

inline void PageLoader::process(State during) {
    while(state == during) {
        QCoreApplication::processEvents();
    }
}

bool PageLoader::load() {
    process(state = IDLE);
    return state == DONE;
}

bool PageLoader::load(const QUrl & url) {
    page.mainFrame()->load(url);
    return load();
}

void PageLoader::onLoad(bool success) {
    state = success ? DONE : FAIL;
}

}
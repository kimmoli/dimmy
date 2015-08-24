#include "viewhelper.h"

#include <stdio.h>

#include <QGuiApplication>
#include <QDir>
#include <qpa/qplatformnativeinterface.h>
#include <QFileInfo>

ViewHelper::ViewHelper(QQuickView *parent) :
    QObject(parent),
    view(parent)
{
    opacity = 0.5;
}

void ViewHelper::detachWindow()
{
    view->close();
    view->create();

    QPlatformNativeInterface *native = QGuiApplication::platformNativeInterface();
    native->setWindowProperty(view->handle(), QLatin1String("CATEGORY"), "notification");
    setDefaultRegion();

    view->showFullScreen();
}

void ViewHelper::setMouseRegion(const QRegion &region)
{
    QPlatformNativeInterface *native = QGuiApplication::platformNativeInterface();
    native->setWindowProperty(view->handle(), QLatin1String("MOUSE_REGION"), region);
}

void ViewHelper::setDefaultRegion()
{
    setMouseRegion(QRegion(0,0,1,1));
}


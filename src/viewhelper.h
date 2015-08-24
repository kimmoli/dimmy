#ifndef VIEWHELPER_H
#define VIEWHELPER_H

#include <QObject>
#include <QQuickView>
#include <QProcess>
#include <QThread>

class ViewHelper : public QObject
{
    Q_OBJECT

public:
    explicit ViewHelper(QQuickView *parent = 0);
    void setDefaultRegion();

    void setOpa(qreal opa) { opacity = opa; }
    Q_INVOKABLE qreal opa() { return opacity; }

public slots:
    void detachWindow();

private:
    void setMouseRegion(const QRegion &region);
    QQuickView *view;

    qreal opacity;

};

#endif // VIEWHELPER_H

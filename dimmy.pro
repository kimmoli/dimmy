TARGET = dimmy

QT += dbus gui-private
CONFIG += sailfishapp

DEFINES += APP_VERSION=\\\"$$VERSION\\\"

SOURCES += \
    src/viewhelper.cpp \
    src/main.cpp

HEADERS += \
    src/viewhelper.h

OTHER_FILES += \
    qml/overlay.qml \
    rpm/dimmy.spec

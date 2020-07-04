QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -pthread -L$$PWD/lib/live555/x86 -lrtspclient -lliveMedia -lBasicUsageEnvironment -lgroupsock -lUsageEnvironment

INCLUDEPATH +=\
    gui/include \
    include/live555/BasicUsageEnvironment \
    include/live555/groupsock \
    include/live555/liveMedia \
    include/live555/UsageEnvironment \
    rtspclient/include \
    demo/rtspclientdemo/include

SOURCES += \
    demo/rtspclientdemo/src/rtspclientdemo.cpp \
    #rtspclient/src/rtspclient_self.cpp \
    gui/src/main.cpp \
    gui/src/dialog.cpp

HEADERS += \
    demo/rtspclientdemo/include/rtspclientdemo.h \
    gui/include/dialog.h \
    rtspclient/include/rtspclient_self.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/config.cpp \
    core/ftps.cpp \
    main.cpp \
    hello.cpp

HEADERS += \
    common/common.h \
    common/cstring.h \
    common/gtime.h \
    common/logger.h \
    common/types.h \
    core/config.h \
    core/ftps.h \
    hello.h

FORMS += \
    hello.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lyaml-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lyaml-cppd
else:unix: LIBS += -L$$PWD/lib/ -lyaml-cpp

INCLUDEPATH += $$PWD/lib/include
DEPENDPATH += $$PWD/lib/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libyaml-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libyaml-cppd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/yaml-cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/yaml-cppd.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libyaml-cpp.a

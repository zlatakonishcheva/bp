QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Expr.cpp \
    Heatmap.cpp \
    Stop_crit.cpp \
    dom.cpp \
    function.cpp \
    function1.cpp \
    function2.cpp \
    function3.cpp \
    function4.cpp \
    instead_of_eigen.cpp \
    main.cpp \
    mainwidget.cpp \
    newton_crit.cpp \
    opt_method.cpp \
    random_crit.cpp \
    sup_stop.cpp

HEADERS += \
    Expr.h \
    Heatmap.h \
    Stop_crit.h \
    dom.h \
    function.h \
    function1.h \
    function2.h \
    function3.h \
    function4.h \
    instead_of_eigen.h \
    mainwidget.h \
    newton_crit.h \
    opt_method.h \
    random_crit.h \
    sup_stop.h

FORMS += \
    mainwidget.ui \
    newton_crit.ui \
    random_crit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

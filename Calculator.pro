QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    commands/command.cpp \
    commands/operatorcommand.cpp \
    commands/pushstackcommand.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp \
    memory.cpp \
    operators/add.cpp \
    operators/divide.cpp \
    operators/minus.cpp \
    operators/multiply.cpp \
    operators/operatorcreator.cpp \
    parser.cpp \
    translator.cpp \
    validator.cpp

HEADERS += \
    calculator.h \
    commands/command.h \
    commands/operatorcommand.h \
    commands/pushstackcommand.h \
    contstants.h \
    exceptions/invalidexpressionexception.h \
    exceptions/unknownoperatorexception.h \
    facade.h \
    mainwindow.h \
    memory.h \
    operators/add.h \
    operators/divide.h \
    operators/minus.h \
    operators/multiply.h \
    operators/operator.h \
    operators/operatorcreator.h \
    parser.h \
    translator.h \
    validator.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

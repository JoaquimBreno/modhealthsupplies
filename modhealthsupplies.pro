QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cadastro.cpp \
    cadastroepi.cpp \
    cadastromedicamento.cpp \
    cadastrovacina.cpp \
    consultainsumo.cpp \
    consultalocal.cpp \
    consultalocalportipo.cpp \
    consultanomeinsumo.cpp \
    controler.cpp \
    epi.cpp \
    insumo.cpp \
    locais.cpp \
    main.cpp \
    mainwindow.cpp \
    medicamento.cpp \
    storagemanager.cpp \
    table.cpp \
    vacina.cpp

HEADERS += \
    cadastro.h \
    cadastroepi.h \
    cadastromedicamento.h \
    cadastrovacina.h \
    consultainsumo.h \
    consultalocal.h \
    consultalocalportipo.h \
    consultanomeinsumo.h \
    controler.h \
    epi.h \
    insumo.h \
    locais.h \
    mainwindow.h \
    medicamento.h \
    storagemanager.h \
    table.h \
    vacina.h

FORMS += \
    cadastro.ui \
    cadastroepi.ui \
    cadastromedicamento.ui \
    cadastrovacina.ui \
    consultainsumo.ui \
    consultalocal.ui \
    consultalocalportipo.ui \
    consultanomeinsumo.ui \
    mainwindow.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

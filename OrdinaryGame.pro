TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
SOURCES += \
        animation.cpp \
        bars.cpp \
        collider.cpp \
        customtexture.cpp \
        environment.cpp \
        functions.cpp \
        game.cpp \
        interface.cpp \
        inventory.cpp \
        main.cpp \
        map.cpp \
        mousecontrol.cpp \
        mypointofview.cpp \
        part.cpp \
        player.cpp

HEADERS += \
    Constants.h \
    animation.h \
    bars.h \
    collider.h \
    customtexture.h \
    environment.h \
    functions.h \
    game.h \
    interface.h \
    inventory.h \
    map.h \
    mousecontrol.h \
    mypointofview.h \
    part.h \
    player.h

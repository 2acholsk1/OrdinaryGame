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
        customtexture.cpp \
        environment.cpp \
        game.cpp \
        main.cpp \
        part.cpp

HEADERS += \
    Constants.h \
    animation.h \
    customtexture.h \
    environment.h \
    game.h \
    part.h

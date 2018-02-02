#include "controllersize.h"
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>

ControllerSize::ControllerSize(QObject *parent) : QObject(parent)
{
    QRect screenSize = QGuiApplication::primaryScreen()->geometry();
    setWidthScreen(screenSize.width());
    setHeightScreen(screenSize.height());
    setHeightListDelegate(heightScreen() / 15);
    setHeightPixelSize(heightListDelegate() * 0.175);
}

int ControllerSize::heightScreen() const
{
    return m_heightScreen;
}

int ControllerSize::widthScreen() const
{
    return m_widthScreen;
}

int ControllerSize::heightListDelegate() const
{
    return m_heightListDelegate;
}

int ControllerSize::heightPixelSize() const
{
    return m_heightPixelSize;
}

void ControllerSize::setHeightScreen(int heightScreen)
{
    if (m_heightScreen == heightScreen)
        return;

    m_heightScreen = heightScreen;
    emit heightScreenChanged(heightScreen);
}

void ControllerSize::setWidthScreen(int widthScreen)
{
    if (m_widthScreen == widthScreen)
        return;

    m_widthScreen = widthScreen;
    emit widthScreenChanged(widthScreen);
}

void ControllerSize::setHeightListDelegate(int heightListDelegate)
{
    if (m_heightListDelegate == heightListDelegate)
        return;

    m_heightListDelegate = heightListDelegate;
    emit heightListDelegateChanged(heightListDelegate);
}

void ControllerSize::setHeightPixelSize(int heightPixelSize)
{
    if (m_heightPixelSize == heightPixelSize)
        return;

    m_heightPixelSize = heightPixelSize;
    emit heightPixelSizeChanged(heightPixelSize);
}

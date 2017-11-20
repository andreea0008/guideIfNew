#include "settings.h"
#include <QDebug>

Settings::Settings(QObject *parent) : QObject(parent)
{

}

bool Settings::isOnline() const
{
    return m_isOnline;
}

void Settings::setIsOnline(bool isOnline)
{
    qDebug() << isOnline;
    if (m_isOnline == isOnline)
        return;

    m_isOnline = isOnline;
    emit isOnlineChanged(isOnline);
}

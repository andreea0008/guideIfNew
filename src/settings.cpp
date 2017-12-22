#include "settings.h"
#include <QDebug>
#include "xml.h"
Settings::Settings(QObject *parent) : QObject(parent)
{
    m_updateExist = false;
}

bool Settings::isOnline() const
{
    return m_isOnline;
}

bool Settings::updateExist() const
{
    return m_updateExist;
}

void Settings::getUpdateExist()
{
    setUpdateExist(xml::getInstance()->isNeedUpdateListCompanies(1.001));
}

void Settings::setIsOnline(bool isOnline)
{
    if (m_isOnline == isOnline)
        return;

    m_isOnline = isOnline;
    emit isOnlineChanged(isOnline);
}

void Settings::setUpdateExist(bool updateExist)
{
    m_updateExist = updateExist;
    emit updateExistChanged(updateExist);
}

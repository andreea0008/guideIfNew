#include "listcompany.h"
#include <QDebug>
#include "xml.h"

ListCompany::ListCompany(QObject *parent) : AbstractListCategory(parent)
{

}

ListCompany::~ListCompany()
{

}

void ListCompany::setPathToFileAboutCompany(QString path)
{
    fileAboutCompany = path;

    for(int i = 0; i< m_dataCompany.size(); i++){
        beginRemoveRows(QModelIndex(), i, i);
        m_dataCompany.removeAt(i);
        endRemoveRows();
    }

    QString tag = "boutique";
    xml::getInstance()->loadCompany(m_dataCompany, tag);
}

void ListCompany::setTagGroup(QString tag)
{
    if(!m_dataCompany.isEmpty()){
        for(int i = 0; i< m_dataCompany.size(); i++){
            beginRemoveRows(QModelIndex(), i, i);
            m_dataCompany.removeAt(i);
            endRemoveRows();
        }
    }

    xml::getInstance()->loadCompany(m_dataCompany, tag);
}

void ListCompany::addCompany(const QString &nameCompany)
{
    addCompanyToList(nameCompany);
}
QList<QVariant> ListCompany::listPhones(int index)
{
    return getListPhones(index);
}

QList<QVariant> ListCompany::listSchedule(int index)
{
    return getListWorHour(index);
}









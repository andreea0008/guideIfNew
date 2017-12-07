#include "listcompany.h"
#include <QDebug>
#include "xml.h"

ListCompany::ListCompany(QObject *parent) : QAbstractItemModel(parent)
{
    m_rolesList[Id] = "idCompany";
    m_rolesList[NameCompany] = "nameCompany";
    m_rolesList[AddressCompany] = "addressCompany";
    m_rolesList[Phones] = "phonesCompany";
    m_rolesList[HourFrom] = "hourFrom";
    m_rolesList[HourTo] = "hourTo";
    m_rolesList[TypeSpecialization] = "typeSpecialization";
    m_rolesList[Description] = "description";
    m_rolesList[Url] = "urlCompany";
    m_rolesList[Facebook] = "facebookCompany";
    m_rolesList[Email] = "emailCompany";
}

ListCompany::~ListCompany()
{

}

int ListCompany::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_dataCompany.count();
}

int ListCompany::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 1;
}

QModelIndex ListCompany::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant ListCompany::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.column() != 0 || index.row() < 0 || index.row() >= m_dataCompany.count())
        return QVariant();

    Company *currentCompany = m_dataCompany[index.row()];
    switch (role) {
    case Id: return currentCompany->getIdCompany();
    case NameCompany: return currentCompany->getNameCompany();
    case AddressCompany: return currentCompany->getAddressCompany();
    case HourFrom: return currentCompany->getHourFromWork();
    case HourTo: return currentCompany->getHourToWork();
    case TypeSpecialization: return currentCompany->getTypeSpecialization();
    case Description: return currentCompany->getDescription();
    case Url: return currentCompany->getUrl();
    case Facebook: return currentCompany->getFacebookUrl();
    case Email: return currentCompany->getEmail();
    default: return QVariant();
    }
    return QVariant();
}

QModelIndex ListCompany::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QHash<int, QByteArray> ListCompany::roleNames() const
{
    return m_rolesList;
}

void ListCompany::setPathToFileAboutCompany(QString path)
{
    fileAboutCompany = path;

    for(int i = 0; i< m_dataCompany.size(); i++){
        beginRemoveRows(QModelIndex(), i, i);
        m_dataCompany.removeAt(i);
        endRemoveRows();
    }


    qDebug() << "count_item_company" << m_dataCompany.count();

    QString tag = "boutique";
    xml::getInstance()->loadCompany(m_dataCompany, tag);

    qDebug() << "count_item_company_after_load" << m_dataCompany.count();
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
    beginInsertRows(QModelIndex(), m_dataCompany.count(), m_dataCompany.count());
    m_dataCompany << new Company(nameCompany);
    endInsertRows();
}
QList<QVariant> ListCompany::listPhones(int index)
{
    QList<QVariant> list;

    if(index < 0 && index > m_dataCompany.size())
        return list;
    QStringList stringList = m_dataCompany[index]->getPhones();
    foreach (QString tempString, stringList) {
        list.push_back(QVariant::fromValue(tempString));
    }
    return list;
}

QList<QVariant> ListCompany::listSchedule(int index)
{
    QList<QVariant> list;
    if(index < 0 && index > m_dataCompany.size())
        return list;
    QStringList stringList = m_dataCompany[index]->getSchedule();
    foreach (QString tempString, stringList) {
        list.push_back(QVariant::fromValue(tempString));
    }
    return list;
}









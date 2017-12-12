#include "abstractlistcategory.h"
#include <qdebug.h>
AbstractListCategory::AbstractListCategory(QObject *parent) : QAbstractItemModel(parent)
{
    roles();
}

AbstractListCategory::~AbstractListCategory()
{

}

void AbstractListCategory::roles()
{
    m_roles[Id] = "idCompany";
    m_roles[NameCompany] = "nameCompany";
    m_roles[AddressCompany] = "addressCompany";
    m_roles[Phones] = "phonesCompany";
    m_roles[HourFrom] = "hourFrom";
    m_roles[HourTo] = "hourTo";
    m_roles[TypeSpecialization] = "typeSpecialization";
    m_roles[Description] = "description";
    m_roles[Url] = "urlCompany";
    m_roles[Facebook] = "facebookCompany";
    m_roles[Email] = "emailCompany";
}

int AbstractListCategory::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_dataCompany.count();
}

int AbstractListCategory::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 1;
}

QModelIndex AbstractListCategory::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant AbstractListCategory::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.column() != 0 || index.row() < 0 || index.row() >= m_dataCompany.size())
        return QVariant();
    Company *currentCompany = m_dataCompany[index.row()];
    switch (role) {
    case Id: return currentCompany->getIdCompany();
    case NameCompany: currentCompany->getNameCompany(); return currentCompany->getNameCompany();
    case AddressCompany: return currentCompany->getAddressCompany();
    case HourFrom: return currentCompany->getHourFromWork();
    case HourTo: return currentCompany->getHourToWork();
    case TypeSpecialization: return currentCompany->getTypeSpecialization();
    case Description: return currentCompany->getDescription();
    case Url: return currentCompany->getUrl();
    case Facebook: return currentCompany->getFacebookUrl();
    case Email: return currentCompany->getEmail();
    default:
        return QVariant();
    }
}

QModelIndex AbstractListCategory::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();

}

QHash<int, QByteArray> AbstractListCategory::roleNames() const
{
    return m_roles;
}

void AbstractListCategory::addCompanyToList(QString nameCompany)
{
    beginInsertRows(QModelIndex(), m_dataCompany.size(), m_dataCompany.size());
    m_dataCompany << new Company(nameCompany);
    endInsertRows();
}

void AbstractListCategory::addCompanyToList(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address, const QString &description)
{
    beginInsertRows(QModelIndex(), m_dataCompany.size(), m_dataCompany.size());
    m_dataCompany.push_front(new Company(idCompany, nameCompany, phones, shedule, address, description));
    updateRowData();
    endInsertRows();
}


void AbstractListCategory::deleteCompanyFromList(const int idCompany)
{
    for(int i = 0; i < m_dataCompany.size(); i++){
        if(dataCompany()[i]->getIdCompany() == idCompany){
            beginRemoveRows(QModelIndex(), i, i);
            m_dataCompany.removeAt(i);
            endRemoveRows();
        }
    }
}

bool AbstractListCategory::isCurrentFavorite(const int idCompany)
{
    for(int i = 0; i < m_dataCompany.size(); i++){
        if(m_dataCompany[i]->getIdCompany() == idCompany)
            return true;
    }
    return false;
}

void AbstractListCategory::updateRowData()
{
    for (int i = 0; i < m_dataCompany.size(); i++){
        QModelIndex index = createIndex(i, 0);
        dataChanged(index, index);
    }
}

QVector<Company *> AbstractListCategory::dataCompany() const
{
    return m_dataCompany;
}

void AbstractListCategory::setDataCompany(const QVector<Company *> &dataCompany)
{
    m_dataCompany = dataCompany;
}

QList<QVariant> AbstractListCategory::getListPhones(int index)
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

QList<QVariant> AbstractListCategory::getListWorHour(int index)
{
    QList<QVariant> list;
    if(index < 0 && index > dataCompany().size())
        return list;
    QStringList stringList = dataCompany()[index]->getSchedule();
    foreach (QString tempString, stringList) {
        list.push_back(QVariant::fromValue(tempString));
    }
    return list;
}

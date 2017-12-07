#include "crowncompanies.h"
#include <QDebug>
#include "xml.h"


CrownCompanies::CrownCompanies(QObject *parent):
    QAbstractItemModel(parent)
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

    xml::getInstance()->loadFavoriteCategoryByType(m_dataCompany, xml::CROWN);
}

CrownCompanies::~CrownCompanies()
{

}

int CrownCompanies::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_dataCompany.size();
}

int CrownCompanies::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 1;
}

QModelIndex CrownCompanies::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant CrownCompanies::data(const QModelIndex &index, int role) const
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
}

QModelIndex CrownCompanies::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QHash<int, QByteArray> CrownCompanies::roleNames() const
{
    return m_roles;
}

void CrownCompanies::addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address,  const QString &description)
{
    if(isCrown(idCompany))
        return;
    beginInsertRows(QModelIndex(), m_dataCompany.count(), m_dataCompany.count());
    m_dataCompany << new Company(idCompany, nameCompany, phones, shedule, address, description);
    endInsertRows();
    xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::CROWN);
}

void CrownCompanies::deleteCompany(const int idCompany)
{
    for(int i = 0; i < m_dataCompany.size(); i++){
        if(m_dataCompany[i]->getIdCompany() == idCompany){
            beginRemoveRows(QModelIndex(), i, i);
            m_dataCompany.removeAt(i);
            endRemoveRows();
        }
    }

   xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::CROWN);
}

bool CrownCompanies::isCrown(const int idCompany)
{
    for(int i = 0; i < m_dataCompany.size(); i++){
        if(m_dataCompany[i]->getIdCompany() == idCompany)
            return true;
    }
    return false;
}



#include "crowncompanies.h"

CrownCompanies::CrownCompanies(QObject *parent):
    QAbstractItemModel(parent)
{
    m_roles[NameCompany] = "nameCompany";
    addCompany("CROWN_COMPANY_1");
    addCompany("CROWN_COMPANY_2");
    addCompany("CROWN_COMPANY_3");
    addCompany("CROWN_COMPANY_4");
    addCompany("CROWN_COMPANY_5");
    addCompany("CROWN_COMPANY_6");
    addCompany("CROWN_COMPANY_7");
    addCompany("CROWN_COMPANY_8");
    addCompany("CROWN_COMPANY_9");
    addCompany("CROWN_COMPANY_10");
    addCompany("CROWN_COMPANY_11");
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
    case NameCompany: return currentCompany->getNameCompany();
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

CrownCompanies::addCompany(const QString &nameCompany)
{
    beginInsertRows(QModelIndex(), m_dataCompany.count(), m_dataCompany.count());
    m_dataCompany << new Company(nameCompany);
    endInsertRows();
}

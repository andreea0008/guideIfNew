#include "lovecompanies.h"
#include <QAbstractItemModel>
Lovecompanies::Lovecompanies(QObject *parent) : QAbstractItemModel(parent)
{
    m_roles[NameCompany] = "nameCompany";
    addCompany("Love_companies_1");
    addCompany("Love_companies_2");
    addCompany("Love_companies_3");
    addCompany("Love_companies_4");
    addCompany("Love_companies_5");
    addCompany("Love_companies_6");
}

Lovecompanies::~Lovecompanies()
{

}

int Lovecompanies::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_dataCompany.count();
}

int Lovecompanies::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 1;
}

QModelIndex Lovecompanies::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant Lovecompanies::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.column() != 0 || index.row() < 0 || index.row() >= m_dataCompany.count())
        return QVariant();

    Company *currentCompany = m_dataCompany[index.row()];
    switch (role) {
    case NameCompany:
        return currentCompany->getNameCompany();
    default:
        return QVariant();
    }
}

QModelIndex Lovecompanies::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QHash<int, QByteArray> Lovecompanies::roleNames() const
{
    return m_roles;
}

void Lovecompanies::addCompany(const QString &nameCompany)
{
    beginInsertRows(QModelIndex(), m_dataCompany.count(), m_dataCompany.count());
    m_dataCompany << new Company(nameCompany);
    endInsertRows();
}

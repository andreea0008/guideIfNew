#include "favoritecompanies.h"

FavoriteCompanies::FavoriteCompanies(QObject *parent)
    :QAbstractItemModel(parent)
{
    m_roles[NameCompany] = "nameCompany";
    addCompany("FAVORITE_COMPANY_1");
    addCompany("FAVORITE_COMPANY_2");
    addCompany("FAVORITE_COMPANY_3");
    addCompany("FAVORITE_COMPANY_4");
    addCompany("FAVORITE_COMPANY_5");
    addCompany("FAVORITE_COMPANY_6");
    addCompany("FAVORITE_COMPANY_7");
    addCompany("FAVORITE_COMPANY_8");
    addCompany("FAVORITE_COMPANY_9");
    addCompany("FAVORITE_COMPANY_10");
    addCompany("FAVORITE_COMPANY_11");
}

FavoriteCompanies::~FavoriteCompanies()
{

}

int FavoriteCompanies::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_dataCompany.count();
}

int FavoriteCompanies::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 1;
}

QModelIndex FavoriteCompanies::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant FavoriteCompanies::data(const QModelIndex &index, int role) const
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

QModelIndex FavoriteCompanies::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QHash<int, QByteArray> FavoriteCompanies::roleNames() const
{
    return m_roles;
}

void FavoriteCompanies::addCompany(const QString &nameCompany)
{
    beginInsertRows(QModelIndex(), m_dataCompany.count(), m_dataCompany.count());
    m_dataCompany << new Company(nameCompany);
    endInsertRows();
}


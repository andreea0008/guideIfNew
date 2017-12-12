#include "favoritecompanies.h"
#include "xml.h"
#include <QDebug>
FavoriteCompanies::FavoriteCompanies(QObject *parent)
    :AbstractListCategory(parent)
{
    setDataCompany(xml::getInstance()->loadFavoriteCategoryByType(xml::FAVORITE));
}

FavoriteCompanies::~FavoriteCompanies()
{

}

void FavoriteCompanies::addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address,  const QString &description)
{
    if(isFavorite(idCompany))
        return;
    addCompanyToList(idCompany, nameCompany, phones, shedule, address, description);
    xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::FAVORITE);
}

void FavoriteCompanies::deleteCompany(const int idCompany)
{
    deleteCompanyFromList(idCompany);
    xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::FAVORITE);
}

bool FavoriteCompanies::isFavorite(const int idCompany)
{
    return isCurrentFavorite(idCompany);
}

QList<QVariant> FavoriteCompanies::listPhones(int index)
{
    return getListPhones(index);
}

QList<QVariant> FavoriteCompanies::listSchedule(int index)
{
    return getListWorHour(index);
}


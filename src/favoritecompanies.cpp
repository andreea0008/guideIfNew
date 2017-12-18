#include "favoritecompanies.h"
#include "xml.h"
#include <QDebug>
FavoriteCompanies::FavoriteCompanies(QObject *parent)
    :AbstractListCategory(parent),
      isMoved(false),
      isDelete(false),
      isAdd(false)
{
    setDataCompany(xml::getInstance()->loadFavoriteCategoryByType(xml::FAVORITE));
}

FavoriteCompanies::~FavoriteCompanies()
{

}

void FavoriteCompanies::addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones,
                                   const QStringList &shedule, const QString &address,  const QString &description,
                                   const QString &facebookUrl, const QString &url)
{
    if(isFavorite(idCompany))
        return;
    isAdd = addCompanyToList(idCompany, nameCompany, phones, shedule, address, description, facebookUrl, url);
}

void FavoriteCompanies::deleteCompany(const int idCompany)
{
    deleteCompanyFromList(idCompany);
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

QList<QVariant> FavoriteCompanies::listCompanyForReport()
{
    return listCompanyByName();
}

void FavoriteCompanies::transitionItem(int from, int to)
{
    isMoved = moveItems(from, to);
}

void FavoriteCompanies::visibleChange()
{
    if(isMoved || isDelete || isAdd){
        xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::FAVORITE);
    }
}


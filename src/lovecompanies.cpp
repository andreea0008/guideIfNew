#include "lovecompanies.h"
#include <QAbstractItemModel>
#include "xml.h"

Lovecompanies::Lovecompanies(QObject *parent) : AbstractListCategory(parent)
{
    setDataCompany(xml::getInstance()->loadFavoriteCategoryByType(xml::LOVE));
}

Lovecompanies::~Lovecompanies()
{

}

void Lovecompanies::addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address,  const QString &description)
{
    if(isLove(idCompany))
        return;
    addCompanyToList(idCompany, nameCompany, phones, shedule, address, description);
    xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::LOVE);
}

void Lovecompanies::deleteCompany(const int idCompany)
{
    deleteCompanyFromList(idCompany);
   xml::getInstance()->saveFavoriteCategoryByType(dataCompany(), xml::LOVE);
}

bool Lovecompanies::isLove(const int idCompany)
{
    return isCurrentFavorite(idCompany);
}

#include "crowncompanies.h"
#include <QDebug>
#include "xml.h"


CrownCompanies::CrownCompanies(QObject *parent):
    AbstractListCategory(parent)
{
    setDataCompany(xml::getInstance()->loadFavoriteCategoryByType(xml::CROWN));
}

CrownCompanies::~CrownCompanies()
{

}

void CrownCompanies::addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address,  const QString &description)
{
    if(isCrown(idCompany))
        return;
    addCompanyToList(idCompany, nameCompany, phones, shedule, address, description);
    xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::CROWN);
}

void CrownCompanies::deleteCompany(const int idCompany)
{
    deleteCompanyFromList(idCompany);
   xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::CROWN);
}

bool CrownCompanies::isCrown(const int idCompany)
{
   return isCurrentFavorite(idCompany);
}



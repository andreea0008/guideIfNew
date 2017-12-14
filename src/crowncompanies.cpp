#include "crowncompanies.h"
#include <QDebug>
#include "xml.h"


CrownCompanies::CrownCompanies(QObject *parent):
    AbstractListCategory(parent),
    isMoved(false),
    isDelete(false),
    isAdd(false)
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
    isAdd = addCompanyToList(idCompany, nameCompany, phones, shedule, address, description);

}

void CrownCompanies::deleteCompany(const int idCompany)
{
    isDelete = deleteCompanyFromList(idCompany);
}

bool CrownCompanies::isCrown(const int idCompany)
{
    return isCurrentFavorite(idCompany);
}

QList<QVariant> CrownCompanies::listPhones(int index)
{
    return getListPhones(index);
}

QList<QVariant> CrownCompanies::listSchedule(int index)
{
    return getListWorHour(index);
}

QList<QVariant> CrownCompanies::listCompanyForReport()
{
    return listCompanyByName();
}

void CrownCompanies::transitionItem(int from, int to)
{
    isMoved = moveItems(from, to);
}

void CrownCompanies::visibleChange()
{
xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::CROWN);
}



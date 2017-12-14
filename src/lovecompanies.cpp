#include "lovecompanies.h"
#include <QAbstractItemModel>
#include "xml.h"

Lovecompanies::Lovecompanies(QObject *parent) : AbstractListCategory(parent),
  isMoved(false),
  isDelete(false),
  isAdd(false)
{
    setDataCompany(xml::getInstance()->loadFavoriteCategoryByType(xml::LOVE));
}

Lovecompanies::~Lovecompanies()
{

}

void Lovecompanies::addCompany(const int idCompany, const QString &nameCompany,
                               const QStringList &phones, const QStringList &shedule,
                               const QString &address,  const QString &description)
{
    if(isLove(idCompany))
        return;

    isAdd = addCompanyToList(idCompany, nameCompany, phones, shedule, address, description);
}

void Lovecompanies::deleteCompany(const int idCompany)
{
   isDelete = deleteCompanyFromList(idCompany);
}

bool Lovecompanies::isLove(const int idCompany)
{
    return isCurrentFavorite(idCompany);
}

QList<QVariant> Lovecompanies::listPhones(int index)
{
    return getListPhones(index);
}

QList<QVariant> Lovecompanies::listSchedule(int index)
{
    return getListWorHour(index);
}

QList<QVariant> Lovecompanies::listCompanyForReport()
{
    return listCompanyByName();
}

void Lovecompanies::transitionItem(int from, int to)
{
    isMoved = moveItems(from, to);
}

void Lovecompanies::visibleChange()
{
    if(isMoved || isDelete ||isAdd){
        xml::getInstance()->saveFavoriteCategoryByType(m_dataCompany, xml::LOVE);
    }
}

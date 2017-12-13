#include "reportselectedcompanies.h"
#include <QDebug>

ReportSelectedCompanies::ReportSelectedCompanies()
{

}

void ReportSelectedCompanies::setNameFavoritesCompany(const QVariantList &loverCompany, const QVariantList &favoriteCompany, const QVariantList &crownCompany)
{
    _loverList.clear();
    _favoriteList.clear();
    _crownList.clear();

    foreach (QVariant nameCompany, loverCompany) {
        _loverList.push_back(nameCompany.toString());
    }
    foreach (QVariant nameCompany, favoriteCompany) {
        _favoriteList.push_back(nameCompany.toString());
    }
    foreach (QVariant nameCompany, crownCompany) {
        _crownList.push_back(nameCompany.toString());
    }
}

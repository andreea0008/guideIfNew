#ifndef REPORTSELECTEDCOMPANIES_H
#define REPORTSELECTEDCOMPANIES_H
#include <QObject>

class ReportSelectedCompanies : public QObject
{
    Q_OBJECT
public:
    explicit ReportSelectedCompanies();

    Q_INVOKABLE void setNameFavoritesCompany(const QVariantList &loverCompany, const QVariantList &favoriteCompany, const QVariantList &crownCompany);

private:
    QStringList _loverList;
    QList<QString> _favoriteList;
    QList<QString> _crownList;
};

#endif // REPORTSELECTEDCOMPANIES_H

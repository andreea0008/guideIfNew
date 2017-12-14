#ifndef FAVORITECOMPANIES_H
#define FAVORITECOMPANIES_H

#include "abstractlistcategory.h"
#include "company.h"

class FavoriteCompanies : public AbstractListCategory
{
    Q_OBJECT
public:
    explicit FavoriteCompanies(QObject *parent = 0);
    ~FavoriteCompanies();

    Q_INVOKABLE void addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address, const QString &description);
    Q_INVOKABLE void deleteCompany(const int idCompany);
    Q_INVOKABLE bool isFavorite(const int idCompany);
    Q_INVOKABLE QList<QVariant> listPhones(int index);
    Q_INVOKABLE QList<QVariant> listSchedule(int index);
    Q_INVOKABLE QList<QVariant> listCompanyForReport();
    Q_INVOKABLE void transitionItem(int from, int to);
    Q_INVOKABLE void visibleChange();

private:
    bool isMoved;
    bool isDelete;
    bool isAdd;
};

#endif // FAVORITECOMPANIES_H

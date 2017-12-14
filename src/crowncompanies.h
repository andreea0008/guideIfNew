#ifndef CROWNCOMPANIES_H
#define CROWNCOMPANIES_H
#include "abstractlistcategory.h"
#include <QVariant>
#include "company.h"

class CrownCompanies : public AbstractListCategory
{
    Q_OBJECT
public:
    explicit CrownCompanies(QObject *parent = 0);
    ~CrownCompanies();

    Q_INVOKABLE void addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address, const QString &description);
    Q_INVOKABLE void deleteCompany(const int idCompany);
    Q_INVOKABLE bool isCrown(const int idCompany);
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

#endif // CROWNCOMPANIES_H

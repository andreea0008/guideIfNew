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
};

#endif // CROWNCOMPANIES_H

#ifndef NAMECOMPANIES_H
#define NAMECOMPANIES_H
#include <QObject>
#include <QVariant>
#include <QDebug>
#include "abstractlistcategory.h"
#include "company.h"


class Lovecompanies : public AbstractListCategory
{
    Q_OBJECT
public:
    explicit Lovecompanies(QObject *parent = 0);
    ~Lovecompanies();

    Q_INVOKABLE void addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones,
                                const QStringList &shedule, const QString &address, const QString &description);
    Q_INVOKABLE void deleteCompany(const int idCompany);
    Q_INVOKABLE bool isLove(const int idCompany);
    Q_INVOKABLE QList<QVariant> listPhones(int index);
    Q_INVOKABLE QList<QVariant> listSchedule(int index);
};

#endif // NAMECOMPANIES_H

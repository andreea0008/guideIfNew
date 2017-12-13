#ifndef LISTCOMPANY_H
#define LISTCOMPANY_H
#include "company.h"
#include "abstractlistcategory.h"


class ListCompany : public AbstractListCategory
{
    Q_OBJECT
public:
    explicit ListCompany(QObject *parent = 0);
    ~ListCompany();

    Q_INVOKABLE void setPathToFileAboutCompany(QString path);
    Q_INVOKABLE void setTagGroup(QString tag);
    Q_INVOKABLE void addCompany(const QString &nameCompany);
    Q_INVOKABLE QList<QVariant> listPhones(int index);
    Q_INVOKABLE QList<QVariant> listSchedule(int index);
private:
    QString fileAboutCompany;
    int selectedIndex;
};

#endif // LISTCOMPANY_H

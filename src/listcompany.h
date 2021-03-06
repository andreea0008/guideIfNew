#ifndef LISTCOMPANY_H
#define LISTCOMPANY_H
#include <QAbstractItemModel>
#include "company.h"


class ListCompany : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit ListCompany(QObject *parent = 0);
    ~ListCompany();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QModelIndex parent(const QModelIndex &child) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void setPathToFileAboutCompany(QString path);
    Q_INVOKABLE void setTagGroup(QString tag);
    Q_INVOKABLE void addCompany(const QString &nameCompany);
    Q_INVOKABLE QList<QVariant> listPhones(int index);
    Q_INVOKABLE QList<QVariant> listSchedule(int index);

private:
    QString fileAboutCompany;
    enum ListCompanyRoles{ Id, NameCompany, AddressCompany, Phones, HourFrom, HourTo,
                           TypeSpecialization, Description, Url, Facebook, Email } ;
    QHash<int, QByteArray> m_rolesList;
    QVector<Company*> m_dataCompany;
    int selectedIndex;
};

#endif // LISTCOMPANY_H

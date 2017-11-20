#ifndef NAMECOMPANIES_H
#define NAMECOMPANIES_H
#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QAbstractItemModel>
#include "company.h"


class Lovecompanies : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit Lovecompanies(QObject *parent = 0);
    ~Lovecompanies();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QModelIndex parent(const QModelIndex &child) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addCompany(const QString &nameCompany);

private:
    enum CompanyRoles{ NameCompany};
    QHash<int, QByteArray> m_roles;
    QList<Company *> m_dataCompany;
};

#endif // NAMECOMPANIES_H

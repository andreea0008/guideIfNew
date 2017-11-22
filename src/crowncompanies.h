#ifndef CROWNCOMPANIES_H
#define CROWNCOMPANIES_H
#include <QAbstractItemModel>
#include "company.h"



class CrownCompanies : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit CrownCompanies(QObject *parent = 0);
    ~CrownCompanies();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QModelIndex parent(const QModelIndex &child) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE addCompany(const QString &nameCompany);

private:
    enum CompanyRoles{ NameCompany };
    QHash<int, QByteArray> m_roles;
    QVector<Company *> m_dataCompany;
};

#endif // CROWNCOMPANIES_H

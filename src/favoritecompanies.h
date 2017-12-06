#ifndef FAVORITECOMPANIES_H
#define FAVORITECOMPANIES_H
#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QAbstractItemModel>
#include "company.h"

class FavoriteCompanies : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit FavoriteCompanies(QObject *parent = 0);
    ~FavoriteCompanies();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QModelIndex parent(const QModelIndex &child) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addCompany(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule, const QString &address, const QString &description);
    Q_INVOKABLE void deleteCompany(const int idCompany);
    Q_INVOKABLE bool isFavorite(const int idCompany);
private:
    enum CompanyRoles{ Id, NameCompany };
    QHash<int, QByteArray> m_roles;
    QVector<Company *> m_dataCompany;
};

#endif // FAVORITECOMPANIES_H

#ifndef ABSTRACTLISTCATEGORY_H
#define ABSTRACTLISTCATEGORY_H

#include <QAbstractItemModel>
#include "company.h"

class AbstractListCategory : public QAbstractItemModel
{
public:
    explicit AbstractListCategory(QObject *parent = 0);
    ~AbstractListCategory();
    enum CompanyRoles{ Id, NameCompany, AddressCompany, Phones, HourFrom, HourTo,
                       TypeSpecialization, Description, Url, Facebook, Email };
    void roles();
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QModelIndex parent(const QModelIndex &child) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual void addCompanyToList(QString nameCompany);
    virtual bool addCompanyToList(const int idCompany, const QString &nameCompany, const QStringList &phones, const QStringList &shedule,
                                  const QString &address,  const QString &description, const QString &facebookUrl, const QString &url);
    virtual bool deleteCompanyFromList(const int idCompany);
    virtual bool isCurrentFavorite(const int idCompany);
    void updateRowData();

    QVector<Company *> dataCompany() const;
    void setDataCompany(const QVector<Company *> &dataCompany);

    QList<QVariant> getListPhones(int index);
    QList<QVariant>getListWorHour(int index);

    QList<QVariant> listCompanyByName();

    virtual bool moveItems(int from, int to);

protected:
    QHash<int, QByteArray> m_roles;
    QVector<Company *> m_dataCompany;
};

#endif // ABSTRACTLISTCATEGORY_H

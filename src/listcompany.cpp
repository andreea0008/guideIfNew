#include "listcompany.h"
#include <QDebug>
#include "xml.h"

ListCompany::ListCompany(QObject *parent) : QAbstractItemModel(parent)
{
    m_rolesList[NameCompany] = "nameCompany";
//    addCompany("Rest_1");
//    addCompany("Rest_2");
//    addCompany("Rest_3");
}

ListCompany::~ListCompany()
{

}

int ListCompany::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_dataCompany.count();
}

int ListCompany::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 1;
}

QModelIndex ListCompany::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant ListCompany::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.column() != 0 || index.row() < 0 || index.row() >= m_dataCompany.count())
        return QVariant();

    Company *currentCompany = m_dataCompany[index.row()];
    switch (role) {
    case NameCompany: return currentCompany->getNameCompany();
    default: return QVariant();
    }
    return QVariant();
}

QModelIndex ListCompany::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QHash<int, QByteArray> ListCompany::roleNames() const
{
    return m_rolesList;
}

void ListCompany::setPathToFileAboutCompany(QString path)
{
    fileAboutCompany = path;
    qDebug() << path;

    for(int i = 0; i< m_dataCompany.size(); i++){
        beginRemoveRows(QModelIndex(), i, i);
        m_dataCompany.removeAt(i);
        endRemoveRows();
    }


    qDebug() << "count_item_company" << m_dataCompany.count();

    xml::getInstance()->loadCompany(m_dataCompany, fileAboutCompany);
}

void ListCompany::addCompany(const QString &nameCompany)
{
    beginInsertRows(QModelIndex(), m_dataCompany.count(), m_dataCompany.count());
    m_dataCompany << new Company(nameCompany);
    endInsertRows();
}









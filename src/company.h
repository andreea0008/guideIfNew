#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>
#include <QVector>

class Company : public QObject{
    Q_OBJECT

public:
    Company(const QString &nameCompany, QObject *parent = 0);
    Company(int id, const QString &nameCompany, QObject *parent = 0);
    Company(int id,const QString &nameCompany, const QString &addressCompany, const QString &hourFrom, const QString &hourTo,
           const QString &specialization = "", const QString &description = "", QObject *parent = 0);
    QString getNameCompany() const { return m_company; }
    QString getAddressCompany() const { return m_address; }
    QVector<QString> getListPhones() const {return m_phones; }
    QString getHourFromWork() const { return m_hourFrom; }
    QString getHourToWork() const { return m_hourTo; }
    QString getTypeSpecialization() const { return m_typeSpecialization; }
    QString getDescription() const { return m_description; }
    int getIdCompany() const { return m_id; }

private:
    int m_id;
    QString m_company;
    QString m_address;
    QVector<QString> m_phones;
    QString m_hourFrom, m_hourTo;
    QString m_typeSpecialization;
    QString m_description;
};

#endif // COMPANY_H

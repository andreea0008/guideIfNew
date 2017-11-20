#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>

class Company : public QObject{
    Q_OBJECT

public:
    Company(const QString &nameCompany, QObject *parent = 0);
    QString getNameCompany() const { return m_company; }

private:
    QString m_company;
};

#endif // COMPANY_H

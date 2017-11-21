#include "company.h"

Company::Company(const QString &nameCompany, QObject *parent):QObject(parent), m_company(nameCompany)
{}

Company::Company(const QString &nameCompany, const QString &addressCompany, const QString &hourFrom,
                 const QString &hourTo, const QString &specialization, const QString &description, QObject *parent) :
    QObject(parent), m_company(nameCompany), m_address(addressCompany), m_hourFrom(hourFrom),
    m_hourTo(hourTo), m_typeSpecialization(specialization), m_description(description)
{

}



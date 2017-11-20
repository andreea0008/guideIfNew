#include "company.h"

Company::Company(const QString &nameCompany, QObject *parent):QObject(parent), m_company(nameCompany)
{}

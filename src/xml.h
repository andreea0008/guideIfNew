#ifndef XML_H
#define XML_H
#include "category.h"
#include "company.h"
class xml
{
public:
    static xml* getInstance();

    void saveCategory(QVector<MyCategory *> &listCategory, bool isDefault = true);
    bool loadCategory(QVector<MyCategory *> &listCategory, bool isCustom = true);

    bool loadCompany(QVector<Company *> &listCompany, QString &tag, bool isDefault = true);

    bool isExistDefaultFile();
    bool isExistCustomFile();

private:
    xml();
    xml(xml const&) = delete;
    void operator=(xml const&) = delete;
    static xml* instance;

    const QString defaultPathToFile;
    const QString customPathToFile;
};

#endif // XML_H

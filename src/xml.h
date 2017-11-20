#ifndef XML_H
#define XML_H
#include "category.h"
#include "company.h"
class xml
{
public:
    static xml* getInstance();

    void saveCategory(QList<MyCategory *> &listCategory, bool isDefault = true);
    bool loadCategory(QList<MyCategory *> &listCategory, bool isCustom = true);

    bool loadCompany(QList<Company *> &listCompany, QString &pathToFile, bool isDefault = true);

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

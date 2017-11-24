#include "xml.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDir>
#include <QString>

xml *xml::instance = 0;

xml::xml()
    :defaultPathToFile("DefaultListCategory.xml"),
      customPathToFile("CustomListCategory.xml"),
      crownCompany("CrowmCompany.xml")
{
}

xml *xml::getInstance()
{
    if(instance == 0)
        instance = new xml();
    return instance;
}

void xml::saveCategory(QVector<MyCategory*> &listCategory, bool isDefault)
{
    QString fileName = defaultPathToFile;
    if(!isDefault)
        fileName = customPathToFile;
    QFile fileForWriteCategory(fileName);
    fileForWriteCategory.open(QIODevice::WriteOnly);


    QXmlStreamWriter xmlWriter(&fileForWriteCategory);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("category");

    xmlWriter.writeTextElement("count_category", QString::number(10));

    if(listCategory.size() != 0){

        for(int i = 0; i < listCategory.size(); i++){
            xmlWriter.writeStartElement("cut" + QString::number(listCategory.at(i)->getId()));
            xmlWriter.writeTextElement("name_category", listCategory.at(i)->getCategory());
            xmlWriter.writeTextElement("path_offline", listCategory.at(i)->getPathToFile());
            xmlWriter.writeTextElement("path_online", "path_online_category");
            xmlWriter.writeTextElement("tag", listCategory.at(i)->getTag());
            xmlWriter.writeEndElement();
        }
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    fileForWriteCategory.flush();
    fileForWriteCategory.close();
}

bool xml::loadCategory(QVector<MyCategory *> &listCategory, bool isCustom)
{
    QString fileName;
    QFile fileForReadCategory;

    if(isExistDefaultFile()){
        fileName = customPathToFile;
        if(!isCustom)
            fileName = defaultPathToFile;
        fileForReadCategory.setFileName(fileName);
    }else{
        fileForReadCategory.setFileName(":/xmls/xmls/DefaultListCategory.xml");
    }


    if(fileForReadCategory.open(QIODevice::ReadOnly)){
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&fileForReadCategory);

        if(xmlReader.readNextStartElement()){
            if(xmlReader.name() == "category"){
                while (xmlReader.readNextStartElement()) {
                    QString cat, pOff, pOn, tag;
                    while (xmlReader.readNextStartElement()){
                        if(xmlReader.name() == "name_category")
                            cat = xmlReader.readElementText();

                        if(xmlReader.name() == "path_offline")
                            pOff = xmlReader.readElementText();

                        if(xmlReader.name() == "path_online")
                            pOn = xmlReader.readElementText();

                        if(xmlReader.name() == "tag")
                            tag = xmlReader.readElementText();
                    }
                    if(!cat.isEmpty())
                        listCategory.push_back(new MyCategory(listCategory.size() +1, cat, pOff, pOn, tag));
                }
            }
        }
        return true;
    }
    return false;
}

void xml::saveCrownCategory(QVector<Company *> &listCompany)
{
    QFile fileForWriteCrownCathegory(crownCompany);
    if(!fileForWriteCrownCathegory.open((QIODevice::WriteOnly))){
        qWarning("file_crown_company not open");
        return;
    }

    QXmlStreamWriter xmlWriter(&fileForWriteCrownCathegory);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("CROWN");
    if(listCompany.count() != 0){
        for(int i = 0; i < listCompany.size(); i++){
            xmlWriter.writeStartElement("crown_id_company" + QString::number(i+1));
            xmlWriter.writeTextElement("id", QString::number(listCompany[i]->getIdCompany()));
            xmlWriter.writeTextElement("name_company", listCompany[i]->getNameCompany());

            xmlWriter.writeEndElement();
        }
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    fileForWriteCrownCathegory.flush();
    fileForWriteCrownCathegory.close();
}

bool xml::loadCrownCategory(QVector<Company *> &listCompany)
{
    QFile fileForReadCategory(crownCompany);

    if(!fileForReadCategory.open((QIODevice::ReadOnly))){
        qWarning("file_crown_company not open");
        return false;
    }

    QXmlStreamReader xmlReader(&fileForReadCategory);

    if(xmlReader.readNextStartElement()) {
        if(xmlReader.name() == "CROWN"){
            while(xmlReader.readNextStartElement()){

                int id;
                QString nameCompanyFromParser;

                if(xmlReader.name() == "id")
                    id = xmlReader.readElementText().toInt();
                if(xmlReader.name() == "name_company")
                    nameCompanyFromParser = xmlReader.readElementText();

                if(!nameCompanyFromParser.isEmpty())
                    listCompany.push_back(new Company(id, nameCompanyFromParser));
            }
        }
    }
}

bool xml::loadCompany(QVector<Company *> &listCompany, QString &tag, bool isDefault)
{
    Q_UNUSED(isDefault);

//    QFile file(":/xmls/xmls/xmlLists/restourants.xml");
    QFile file(":/xmls/xmls/xmlLists/companies.xml");

    if(!file.open(QIODevice::ReadOnly)){
        qWarning("f_not_open");
        return false;
    }
    QXmlStreamReader xmlReader(&file);

    listCompany.clear();
    while(xmlReader.readNextStartElement()){
        if(xmlReader.name() == "rss"){
            continue;
        }
        if(xmlReader.name() == "channel"){
            continue;
        }
        if(xmlReader.name() == tag){
            qDebug() << xmlReader.name();
            while(xmlReader.readNextStartElement()){
                if(xmlReader.name() == "item"){
                    QString nameCompany, address;
                    int id = 0;
                    while(xmlReader.readNextStartElement()){
                        if(xmlReader.name() == "restourant" )
                            nameCompany = xmlReader.readElementText();
                        else if(xmlReader.name() == "address")
                            address = xmlReader.readElementText();
                        else if(xmlReader.name() == "id")
                            id = xmlReader.readElementText().toInt();
                        else
                            xmlReader.skipCurrentElement();
                    }
                    if(!nameCompany.isEmpty()){
                        listCompany.push_back(new Company(id, nameCompany));
                    }
                }
            }
        }else{
            xmlReader.skipCurrentElement();
        }
    }

    return false;
}

bool xml::isExistDefaultFile()
{
    QFile defaultFileCategories("DefaultListCategory.xml");
    return defaultFileCategories.exists();
}

bool xml::isExistCustomFile()
{
    QFile defaultFileCategories("CustomListCategory.xml");
    return defaultFileCategories.exists();
}



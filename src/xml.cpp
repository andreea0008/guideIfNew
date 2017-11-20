#include "xml.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDir>
xml *xml::instance = 0;

xml::xml()
    :defaultPathToFile("DefaultListCategory.xml"),
      customPathToFile("CustomListCategory.xml")
{
}

xml *xml::getInstance()
{
    if(instance == 0)
        instance = new xml();
    return instance;
}

void xml::saveCategory(QList<MyCategory*> &listCategory, bool isDefault)
{
    qDebug() << __FUNCTION__ << isDefault;
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
            xmlWriter.writeEndElement();
        }
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    fileForWriteCategory.flush();
    fileForWriteCategory.close();
}

bool xml::loadCategory(QList<MyCategory *> &listCategory, bool isCustom)
{
    qDebug() << QDir::homePath() << isCustom;
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
        qDebug() << "file_open";
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&fileForReadCategory);

        if(xmlReader.readNextStartElement()){
            if(xmlReader.name() == "category"){
                while (xmlReader.readNextStartElement()) {
                    QString cat, pOff, pOn;
                    while (xmlReader.readNextStartElement()){
                        if(xmlReader.name() == "name_category")
                            cat = xmlReader.readElementText();

                        if(xmlReader.name() == "path_offline")
                            pOff = xmlReader.readElementText();

                        if(xmlReader.name() == "path_online")
                            pOn = xmlReader.readElementText();
                    }
                    if(!cat.isEmpty())
                        listCategory.push_back(new MyCategory(listCategory.size() +1, cat, pOff, pOn));
                }
            }
        }
        return true;
    }
    return false;
}

bool xml::loadCompany(QList<Company *> &listCompany, QString &pathToFile, bool isDefault)
{
    Q_UNUSED(pathToFile);
    Q_UNUSED(isDefault);

    QFile file(":/xmls/xmls/xmlLists/restourants.xml");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "f_not_open";
        return false;
    }

    qDebug() << "f_open";
    QXmlStreamReader xmlReader(&file);

    listCompany.clear();
    while(xmlReader.readNextStartElement()){
        if(xmlReader.name() == "rss"){
            continue;
        }
        if(xmlReader.name() == "channel"){
            continue;
        }
        if(xmlReader.name() == "item"){
            while(xmlReader.readNextStartElement()){
                if(xmlReader.name() == "restourant" ){
                    QString nameCompany = xmlReader.readElementText();
                    listCompany.push_back(new Company(nameCompany));
                }
                else
                    xmlReader.skipCurrentElement();
            }
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



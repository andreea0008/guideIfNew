#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/category.h"
#include "src/settings.h"
#include "src/lovecompanies.h"
#include "src/favoritecompanies.h"
#include "src/crowncompanies.h"
#include "src/listcompany.h"
#include "src/reportselectedcompanies.h"
#include "src/feedback.h"
#include "controllersize.h"
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<Category>("com.guide.Category", 1, 0, "Category", "Nope");
    qmlRegisterUncreatableType<ListCompany>("com.guide.ListCompany", 1, 0, "ListCompany", "Nope");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CATEGORY", new Category(&engine));
    engine.rootContext()->setContextProperty("LoveCompanies", new Lovecompanies(&engine));
    engine.rootContext()->setContextProperty("FavoriteCompanies", new FavoriteCompanies(&engine));
    engine.rootContext()->setContextProperty("CrownCompanies", new CrownCompanies(&engine));
    engine.rootContext()->setContextProperty("ListCompanies", new ListCompany(&engine));
    engine.rootContext()->setContextProperty("Settings", new Settings(&engine));
    engine.rootContext()->setContextProperty("ReportSelectedCompany", new ReportSelectedCompanies());
    engine.rootContext()->setContextProperty("Feedback", new Feedback());
    ControllerSize controllerSize(&engine);
    engine.rootContext()->setContextProperty("ControllerSize", &controllerSize);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

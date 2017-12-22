#include "feedback.h"
#include <QDebug>

Feedback::Feedback(QObject *parent) : QObject(parent)
{

}

void Feedback::sendFeedbackAboutApplication(const QString &text)
{
    qDebug() << text;
}

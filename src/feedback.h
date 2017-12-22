#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QObject>

class Feedback : public QObject
{
    Q_OBJECT
public:
    explicit Feedback(QObject *parent = 0);

public slots:
    Q_INVOKABLE void sendFeedbackAboutApplication(const QString& text);
};

#endif // FEEDBACK_H

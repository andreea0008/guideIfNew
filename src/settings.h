#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isOnline READ isOnline WRITE setIsOnline NOTIFY isOnlineChanged)

    bool m_isOnline;

public:
    explicit Settings(QObject *parent = 0);
    bool isOnline() const;

signals:
    void isOnlineChanged(bool isOnline);

public slots:
    void setIsOnline(bool isOnline);
};

#endif // SETTINGS_H

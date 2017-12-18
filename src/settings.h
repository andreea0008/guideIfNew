#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isOnline READ isOnline WRITE setIsOnline NOTIFY isOnlineChanged)
    Q_PROPERTY(bool updateExist READ updateExist WRITE setUpdateExist NOTIFY updateExistChanged)
    bool m_isOnline;    
    bool m_updateExist;

public:
    explicit Settings(QObject *parent = 0);
    bool isOnline() const;

    bool updateExist() const;

    Q_INVOKABLE void getUpdateExist();

signals:
    void isOnlineChanged(bool isOnline);

    void updateExistChanged(bool updateExist);

public slots:
void setIsOnline(bool isOnline);
void setUpdateExist(bool updateExist);
};

#endif // SETTINGS_H

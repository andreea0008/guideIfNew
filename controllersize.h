#ifndef CONTROLLERSIZE_H
#define CONTROLLERSIZE_H

#include <QObject>
#include <QDesktopServices>

class ControllerSize : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int heightScreen READ heightScreen WRITE setHeightScreen NOTIFY heightScreenChanged)
    Q_PROPERTY(int widthScreen READ widthScreen WRITE setWidthScreen NOTIFY widthScreenChanged)
    Q_PROPERTY(int heightListDelegate READ heightListDelegate WRITE setHeightListDelegate NOTIFY heightListDelegateChanged)
    Q_PROPERTY(int heightPixelSize READ heightPixelSize WRITE setHeightPixelSize NOTIFY heightPixelSizeChanged)
public:
    explicit ControllerSize(QObject *parent = 0);
    int heightScreen() const;
    int widthScreen() const;
    int heightListDelegate() const;
    int heightPixelSize() const;

signals:
    void heightScreenChanged(int heightScreen);
    void widthScreenChanged(int widthScreen);
    void heightListDelegateChanged(int heightListDelegate);

    void heightPixelSizeChanged(int heightPixelSize);

public slots:
    void setHeightScreen(int heightScreen);
    void setWidthScreen(int widthScreen);
    void setHeightListDelegate(int heightListDelegate);
    void setHeightPixelSize(int heightPixelSize);

private:
    int m_heightScreen;
    int m_widthScreen;
    int m_heightListDelegate;
    int m_heightPixelSize;
};

#endif // CONTROLLERSIZE_H

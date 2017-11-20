import QtQuick 2.0
import "Cells"

Item{
    id: topHead
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    height: window.height * 0.1

    FontLoader{
        id: fontLoaderHead
        source: "qrc:/fonts/fonts/Bodoni-Bold-Cyrillic.ttf"
    }

    Rectangle{
        anchors.fill: parent
        color: "#242424"
        radius: parent.height / 3
        Rectangle{
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.radius
            color: "#242424"
        }
    }

    Image{
        id: backArrow
        height: parent.height * 0.5
        width: height
        anchors.left: parent.left
        anchors.leftMargin: height / 2
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/Delegates/img/left-arrow.png"
        visible: stackAllCategory.depth > 1
        MouseArea{
            anchors.fill: parent
            onReleased: stackAllCategory.pop()
        }
    }

    Text{
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: backArrow.visible ? backArrow.right : parent.left
        anchors.leftMargin: parent.height / 4
        font.pixelSize: parent.height * 0.6
        color: "#fff"
        text: "GuideIf"
        font.family: fontLoaderHead.name
        font.bold: true
    }

    OnlineButton{
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }
}

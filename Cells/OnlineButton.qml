import QtQuick 2.0

Item {
    height: parent.height * 0.25
    width: 50

    property bool isOnline: false

    Rectangle{
        id: rectOnline
        anchors.verticalCenter: parent.verticalCenter
        color: "#27ae60"
        width: parent.height
        height: width
        radius: height / 2

        Rectangle{
            anchors.fill: parent
            color: "#242424"
            radius: height / 2
            visible: !isOnline
            opacity: 0.5
        }
    }

    Text{
        anchors.left: rectOnline.right
        anchors.leftMargin: 3
        anchors.verticalCenter: rectOnline.verticalCenter
        text: isOnline ? qsTr("Online") : qsTr("Offline")
        color: "#fff"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            isOnline ? isOnline = false : isOnline = true
            Settings.setIsOnline(isOnline)
        }
    }
}

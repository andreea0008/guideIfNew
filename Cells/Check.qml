import QtQuick 2.0

Rectangle{
    id: control
    width: 40
    height: width

    property bool isActive: false

    color: "transparent"
    border.color: "#f40612"
    border.width: width / 14
    radius: width / 4

    Rectangle{
        anchors.centerIn: parent
        width: control.width * 0.6
        height: width
        color: isActive ? "#f40612" : "transparent"
        radius: control.width / 8

    }

    MouseArea{
        anchors.fill: parent
        onClicked: isActive ? isActive = false : isActive = true
    }
}

import QtQuick 2.0

Rectangle{
    width: 40
    height: width

    property bool isActive: false

    color: "transparent"
    border.color: "#f40612"
    border.width: 3
    radius: 10

    Rectangle{
        anchors.centerIn: parent
        width: 24
        height: 24
        color: isActive ? "#f40612" : "transparent"
        radius: 5

    }

    MouseArea{
        anchors.fill: parent
        onClicked: isActive ? isActive = false : isActive = true
    }
}

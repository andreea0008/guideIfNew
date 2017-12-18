import QtQuick 2.0

Rectangle {
    id: mainBox
    property variant schedule
    height: 100
    color: "transparent"
//    Component.onCompleted: height = getHeight()


    Item{
        id: itemLabelHours
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 40

        Text {
            id: idText
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            text: "Hours Today:"
            color: "white"
        }

    }
    ListView {
        id: list
        anchors.top: itemLabelHours.bottom
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        model: schedule
        clip: true
        spacing: 1
        interactive: false

        delegate:
            Text{
            id: textHoursDelegate
            width: list.width
            height: 20
            text: modelData
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 10
            color: "white"
        }
    }

    function getHeight(){
        var heightListHours = (textHoursDelegate.height * list.count) + (list.spacing * list.count);
        return heightListHours + itemLabelHours.height
    }
}

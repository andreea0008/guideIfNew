import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {
    id: mainBox
    property alias cuisineLabel: cuisineLabel.text
    property alias modelList: list.model
    property alias isCusineLabelVisible: cuisineLabel.visible
    property alias textCusineLabel: cuisineLabel.text
    property int pointSizeText: 10
    property color cText: "#fff"

    height: getHeight()

    Component.onCompleted: {
        height = getHeight()
    }


    Text {
        id: cuisineLabel
        anchors.left: parent.left
        anchors.top: parent.top
        text: "Cuisine:"
        font.pointSize: pointSizeText * 1.3
        color: cText
    }

    Text {
        id: cuisineDescription
        anchors.left: cuisineLabel.right
        anchors.top: cuisineLabel.bottom
        anchors.topMargin: 10
        visible: cuisineLabel.visible
        text: "italian, european"
        color: cText
    }

    Text {
        id: hourLabelToday
        anchors.left: parent.left
        anchors.top: cuisineDescription.bottom
        anchors.topMargin: 15
        text: "Hours Today:"
        font.pointSize: pointSizeText * 1.3
        color: cText
    }

    ListModel{
        id: model

        ListElement{
            days: "Mon - Fri:"
            hours: "08:00 - 23:00"
        }

        ListElement{
            days: "Sat - Sun:"
            hours: "08:00 - 23:00"
        }
    }

    ListView {
        id: list
        anchors.top: hourLabelToday.bottom
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: cuisineLabel.width / 2
        model: model
        clip: true
        spacing: 1
        interactive: false

        delegate: Row{

            spacing: 20
            Text{
                id: textHoursDelegate
                text: days
                font.pointSize: pointSizeText
                color: cText
            }

            Text{
                id: textDaysDelegate
                text: hours
                font.pointSize: pointSizeText
                color: cText
            }
        }
    }

    function getHeight() {
        return list.height + cuisineDescription.height + hourLabelToday.height + cuisineLabel.height
    }


}

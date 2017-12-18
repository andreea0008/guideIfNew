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

    property variant schedule

    height: getHeight()

    onVisibleChanged: {
        console.log("on_visible_chanhe")
    }

    Component.onCompleted: {
        console.log("on_complete_chanhe")
        height = getHeight()
    }

    Text {
        id: cuisineLabel
        anchors.left: parent.left
        anchors.top: parent.top
        text: "Cuisine:"
        font.pointSize: pointSizeText * 1.3
        color: cText
        visible: cuisineDescription.visible
    }

    Text {
        id: cuisineDescription
        anchors.left: cuisineLabel.right
        anchors.top: cuisineLabel.bottom
        anchors.topMargin: 10
        color: cText
        visible: text.length !== 0
    }

    Text {
        id: hourLabelToday
        anchors.left: parent.left
        anchors.top: cuisineDescription.visible ? cuisineDescription.bottom : mainBox.top
        anchors.topMargin: 15
        text: "Hours Today:"
        font.pointSize: pointSizeText * 1.3
        color: cText
    }

    ListView {
        id: list
        anchors.top: hourLabelToday.bottom
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: cuisineLabel.width / 2
        model: schedule
        clip: true
        spacing: 1
        interactive: false

        delegate:
            Text{
            id: textHoursDelegate
            width: list.width
            text: modelData
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: pointSizeText
            color: cText

            Rectangle{
                anchors.fill: parent
                color: "red"
                opacity: 0.1
            }
        }
    }

    function getHeight() {
        var heightCuisine = 0
        if(list.visible)
            heightCuisine += list.height
        if(cuisineDescription.visible)
            heightCuisine += cuisineDescription.height
        if(hourLabelToday.visible)
            heightCuisine += hourLabelToday.height
        if(cuisineLabel.visible)
            heightCuisine += cuisineLabel.height
        console.log("heightCuisine", heightCuisine)
        return heightCuisine
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {
    id: mainBox
    property alias addressLabelText: addressLabel.text
    property alias addressText: address.text
    property color cText: "#fff"

    ColumnLayout{
        Text {
            id: addressLabel
            text: qsTr("Address")
            font.pixelSize: mainBox.height / 5
            color: cText
        }
        Text {
            id: address
            text: qsTr("200 5th Ave, New York, NY 10010")
            anchors.left: parent.left
            anchors.leftMargin: 25
            font.pixelSize: mainBox.height * 0.2
            color: cText
        }
    }
}

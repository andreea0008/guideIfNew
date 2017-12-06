import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {
    property alias countElements: listElement.count
    property alias heightSpacing: listElement.spacing
    property int widthDelegateRectangle: 200
    property int heightDelegateRectangle: 40
    property color cText: "#fff"
    property variant phoneList: ["1", "2", "3"]

    signal callToNumber(var phone)

    ListView{
        id: listElement
        anchors.fill: parent
        clip: true
        interactive: false
        model: phoneList
        spacing: 1
        delegate: Rectangle{
            id: delegateRect
            width: widthDelegateRectangle
            height: heightDelegateRectangle
            color: "transparent"

            property real multiplierPhoneText: 0.6
            property real dividerPhoneText: 0.5

            property real multiplierPhoneIcon: 0.7
            property real deviderPhoneIcon: 0.8
            Item{
                id: itemMain
                anchors.fill: parent
                anchors.leftMargin: delegateRect.width / 10
                anchors.rightMargin: delegateRect.width / 10

                Text {
                    id: phoneText
                    text: modelData
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: parent.width * 0.75
                    font.pixelSize: height * delegateRect.dividerPhoneText
                    color: cText

                    MouseArea{
                        anchors.fill: parent
                        onPressed: delegateRect.pressed()
                        onReleased: delegateRect.released()
                    }
                }

                Item{
                    id: phoneIcon
                    anchors.left: phoneText.right
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    Image{
                        id: imgCall
                        anchors.centerIn: parent
                        height: parent.height * delegateRect.multiplierPhoneIcon
                        width: height
                        antialiasing: true
                        source: "/Delegates/img/phone-call-button.png"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: delegateRect.pressed()
                        onReleased: delegateRect.released()
                    }
                }

            }

            function pressed(){
                phoneText.font.pixelSize = itemMain.height * multiplierPhoneText
                imgCall.height = itemMain.height * deviderPhoneIcon
            }

            function released(){
                phoneText.font.pixelSize = itemMain.height * dividerPhoneText
                imgCall.height = itemMain.height * multiplierPhoneIcon
                callToNumber(phoneText.text)
            }
        }
    }
}

import QtQuick 2.0

Item {
    anchors.left: parent.left
    anchors.right: parent.right
    height: column.height
    property int heightItem: 40
    property string siteLink: ""
    property string facebookLink: ""

    onVisibleChanged: {
        console.log(height)
    }

    Column{
        id: column
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width * 0.1
        anchors.rightMargin: parent.width * 0.1
        height: facebookItem.height + wwwItem.height

        Item{
            id: wwwItem
            anchors.left: parent.left
            anchors.right: parent.right
            height: heightItem
            visible: siteLink.length !== 0

            Text {
                id: wwwText
                anchors.left: parent.left

                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                text: siteLink
                font.pixelSize: parent.height * 0.5
            }
            Item{
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width * 0.25
                Image {
                    id: icon
                    anchors.centerIn: parent
                    height: heightItem * 0.6
                    width: height
                    source: "../Delegates/img/world.png"
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: console.log(wwwText.text)
            }
        }

        Item{
            id: facebookItem
            anchors.left: parent.left
            anchors.right: parent.right
            height: heightItem
            visible: facebookLink.length > 0

            Text {
                id: wwwFacebook
                anchors.left: parent.left
                anchors.right: facebookIconItem.left
                anchors.verticalCenter: parent.verticalCenter
                elide: Text.ElideRight
                color: "white"
                text: facebookLink
                font.pixelSize: parent.height * 0.5
            }
            Item{
                id: facebookIconItem
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width * 0.25
                Image {
                    id: iconFacebook
                    anchors.centerIn: parent
                    height: heightItem * 0.6
                    width: height
                    source: "../Delegates/img/facebook_logo.png"
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: console.log(wwwFacebook.text)
            }
        }
    }

}

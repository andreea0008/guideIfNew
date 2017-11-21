import QtQuick 2.0

Item{
    height: 80
    width: parent.width

    signal addToCrown(var isCrown)
    signal addToFavorite(var isFavorite)
    signal addToLove(var isLove)

    property alias nameRestourant: nameRest.text
    property real shadow: 0.5
    property color shadowColor: "#1b1b1b"
    Text{
        id: nameRest
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        font.pointSize: 20
        verticalAlignment: Text.AlignVCenter
        text: "Eataly"
        color: "#f40612"
        wrapMode: Text.Wrap
    }

    Item{
        id: loveItem
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height/2

        Image{
            id: loveFavorite
            anchors.centerIn: parent
            source: "../Delegates/img/favourite-star_not_selected.png"
            height: parent.height/2
            width: height
            antialiasing: true

            property bool isSelected: false

            onIsSelectedChanged: addToLove(isSelected)

            Rectangle{
                anchors.fill: parent
                color: shadowColor
                visible: !parent.isSelected
                opacity: shadow
            }

            MouseArea{
                anchors.fill: parent
                onClicked: parent.isSelected ? parent.isSelected = false : parent.isSelected = true
            }
        }
        Item{
            id: starItem
            anchors.right: loveItem.left
            anchors.rightMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.height/2

            Image{
                id: starFavorite
                anchors.centerIn: parent
                source: "../Delegates/img/star.png"
                height: parent.height/2
                width: height
                antialiasing: true

                property bool isSelected: false
                onIsSelectedChanged: addToFavorite(isSelected)

                Rectangle{
                    anchors.fill: parent
                    color: shadowColor
                    visible: !parent.isSelected
                    opacity: shadow
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: parent.isSelected ? parent.isSelected = false : parent.isSelected = true
                }
            }
        }
        Item{
            anchors.right: starItem.left
            anchors.rightMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.height/2

            Image{
                id: crownFavorite
                anchors.centerIn: parent
                source: "../Delegates/img/crown.png"
                height: parent.height/2
                width: height
                antialiasing: true

                property bool isSelected: false
                onIsSelectedChanged: addToCrown(isSelected)

                Rectangle{
                    anchors.fill: parent
                    color: shadowColor
                    visible: !parent.isSelected
                    opacity: shadow
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: parent.isSelected ? parent.isSelected = false : parent.isSelected = true
                }
            }
        }
    }
}

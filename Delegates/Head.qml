import QtQuick 2.0

Item{
    height: heightColumn
    width: parent.width

    property int idCompany: 0
    property alias nameRestourant: nameRest.text
    property int  heightColumn: 80

    signal addToCrown(var isCrown)
    signal addToFavorite(var isFavorite)
    signal addToLove(var isLove)

    QtObject{
        id: privateProperties
        property real shadow: 0.5
        property color shadowColor: "#1b1b1b"
        property color colorNameCompany: "#f40612"
    }

    Text{
        id: nameRest
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: loveItem.left

        font.pointSize: 20
        verticalAlignment: Text.AlignVCenter
        text: nameRestourant
        color: privateProperties.colorNameCompany
        wrapMode: Text.WordWrap

        Component.onCompleted: console.log(nameRest.height)

        states: [
        State{
                name: "22px"
                when: nameRest.text.length <= 15
                PropertyChanges{ target: nameRest; font.pointSize: 22}
            },
            State{
                    name: "17px"
                    when: nameRest.text.length > 15 && nameRest.text.length <= 30
                    PropertyChanges{ target: nameRest; font.pointSize: 17}
                },
            State{
                    name: "15px"
                    when: nameRest.text.length >30
                    PropertyChanges{ target: nameRest; font.pointSize: 15}
                }

        ]
    }

    Item{
        id: crownItem
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height/2

        Image{
            id: crownFavorite
            anchors.centerIn: parent
            source: "../Delegates/img/crown.png"
            height: parent.height/2
            width: height
            antialiasing: true

            property bool isSelected: false//CrownCompanies.isCrown(nameRest.text)

            Component.onCompleted: isSelected = CrownCompanies.isCrown(idCompany)

            onVisibleChanged: {
                if(visible)
                    console.log("visible")
                else
                    console.log("invisible")
            }

            onIsSelectedChanged: addToCrown(isSelected)

            Rectangle{
                anchors.fill: parent
                color: privateProperties.shadowColor
                visible: !parent.isSelected
                opacity: privateProperties.shadow
            }

            MouseArea{
                anchors.fill: parent
                onClicked: parent.isSelected ? parent.isSelected = false : parent.isSelected = true
            }
        }
    }

    Item{
        id: starItem
        anchors.right: crownItem.left
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

            Component.onCompleted: isSelected = FavoriteCompanies.isFavorite(idCompany)

            property bool isSelected: false

            onIsSelectedChanged: addToFavorite(isSelected)

            Rectangle{
                anchors.fill: parent
                color: privateProperties.shadowColor
                visible: !parent.isSelected
                opacity: privateProperties.shadow
            }

            MouseArea{
                anchors.fill: parent
                onClicked: parent.isSelected ? parent.isSelected = false : parent.isSelected = true
            }
        }
    }

    Item{
        id: loveItem
        anchors.right: starItem.left
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.height/2

        Image{
            id: loveFavorite
            anchors.centerIn: parent
            source: "../Delegates/img/favourite-star_not_selected.png"
            height: parent.height/2
            width: height
            antialiasing: true

            Component.onCompleted: isSelected = LoveCompanies.isLove(idCompany)

            property bool isSelected: false

            onIsSelectedChanged: addToLove(isSelected)

            Rectangle{
                anchors.fill: parent
                color: privateProperties.shadowColor
                visible: !parent.isSelected
                opacity: privateProperties.shadow
            }

            MouseArea{
                anchors.fill: parent
                onClicked: parent.isSelected ? parent.isSelected = false : parent.isSelected = true
            }
        }

    }
}

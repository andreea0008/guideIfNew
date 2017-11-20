import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

ScrollView{
    id: scrollView
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
    verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff
    Item {
        id: mainItem
        property alias nameRestText: head.nameRestourant
        property alias addressLabelText: address.addressLabelText
        property alias address: address.addressText
        property alias descriptionText: description.text
        width: scrollView.width
        height: getHeightColumn()

        property real shadow: 0.6

        Column{
            anchors.fill: parent
            anchors.margins: 20
            spacing: 10

            Head{
                id: head
                onAddToCrown:  console.log(isCrown)
                onAddToFavorite: console.log(isFavorite)
                onAddToLove: console.log(isLove)
            }

            Address{
                id: address
                height: 80
                width: parent.width
                addressLabelText: "Address:"
            }

            Phones{
                id: phones
                height: (countElements * heightDelegateRectangle) + ((countElements -1) * heightSpacing)
                width:  parent.width
                widthDelegateRectangle: parent.width

                onCallToNumber: console.log("Call to - ", phone)
            }

            Cuisine{
                id: cuisine
                width: parent.width
                height: 200
            }

            Text{
                id: description
                width: parent.width
                text: "Offering many of the city’s best restaurants and shops set amid classic New York architecture, the Flatiron
    District is no longer under the tourist radar. At 23rd Street is the famous triangular Flatiron Building,
    which makes a good picture no matter what angle you photograph it from. Be sure to look up at the elegant
    architecture as you stroll the streets - much of this neighborhood is part of a historic district that was
    home to many of the city’s most famous department stores at the turn of the century. At the northern end
    of the neighborhood, Madison Square Park is best known
    for being home to a famous burger shack, but it can
    also be a quiet refuge to spend an afternoon, and it
    frequently hosts interesting public art exhibits. In
    the lower part of the Flatiron District you'll find
    Union Square, a bustling crossroads at all times of
    day and night"
                wrapMode: Text.Wrap
                color: "#fff"
            }
        }

        function getHeightColumn(){
            return head.height + address.height + phones.height + cuisine.height + description.height + 100
        }
    }

}



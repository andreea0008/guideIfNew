import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

ScrollView{
    id: scrollView
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
    verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff

    property int idCompany: 0
    property string nameCompany: ""
    property string address: ""
    property variant listPhones: ""
    property variant listSchedule: ""
    property string facebookLink: ""
    property string siteLink: ""
    property alias description: description.text


    Rectangle {
        id: mainItem
        width: scrollView.width
        height: getHeightColumn()


        property real shadow: 0.6

        color: "#1b1b1b"

        Column{
            anchors.fill: parent
            anchors.margins: 20
            spacing: 10

            Head{
                id: head
                idCompany: scrollView.idCompany
                onAddToCrown:  addOrRemoveCrownFavorite(isCrown)
                onAddToFavorite: addOrRemoveFavorite(isFavorite)
                onAddToLove: addOrRemoveLoveFavorite(isLove)
                nameRestourant: scrollView.nameCompany

                function addOrRemoveLoveFavorite(isLove){
                    if(isLove)
                        LoveCompanies.addCompany(idCompany, nameRestourant, listPhones, listSchedule, scrollView.address, description.text, facebookLink, siteLink)
                    else
                        LoveCompanies.deleteCompany(idCompany)
                }

                function addOrRemoveCrownFavorite(isCrown){
                    if(isCrown)
                        CrownCompanies.addCompany(idCompany, nameRestourant, listPhones, listSchedule, scrollView.address, description.text, facebookLink, siteLink)
                    else
                        CrownCompanies.deleteCompany(idCompany)
                }

                function addOrRemoveFavorite(isFavorite){
                    if(isFavorite)
                        FavoriteCompanies.addCompany(idCompany, nameRestourant, listPhones, listSchedule, scrollView.address, description.text, facebookLink, siteLink)
                    else
                        FavoriteCompanies.deleteCompany(idCompany)
                }
            }

            Address{
                id: address
                height: 80
                width: parent.width
                addressLabelText: "Address:"
                addressText: scrollView.address
            }

            Phones{
                id: phones
                height: (countElements * heightDelegateRectangle) + ((countElements -1) * heightSpacing)
                width:  parent.width
                widthDelegateRectangle: parent.width
                phoneList: listPhones

                onCallToNumber: console.log("Call to - ", phone)
            }

            SiteAndSocialNetworks{
                siteLink: scrollView.siteLink
                facebookLink: scrollView.facebookLink
                Rectangle{
                    color: "red"
                    opacity: 0.1
                    anchors.fill: parent
                }
            }

//            Cuisine{
//                id: cuisine
//                width: parent.width
//                schedule: listSchedule
//                height: 170
//                Rectangle{
//                    color: "red"
//                    opacity: 0.1
//                    anchors.fill: parent
//                }
//            }

            WorksHour{
                width: parent.width
                schedule: listSchedule
            }

            Text{
                id: description
                width: parent.width
                visible: text.length > 0
                text:
                    "Offering many of the city’s best restaurants and shops set amid classic New York architecture, the Flatiron
                    District is no longer under the tourist radar. At 23rd Street is the famous triangular Flatiron Building,
                    which makes a good picture no matter what angle you photograph it from. Be sure to look up at the elegant
                    architecture as you stroll the streets - much of this neighborhood is part of a historic district that was
                    home to many of the city’s most famous department stores at the turn of the century. At the northern end
                    of the neighborhood, Madison Square Park is best known for being home to a famous burger shack, but it can
                    also be a quiet refuge to spend an afternoon, and it frequently hosts interesting public art exhibits. In
                    the lower part of the Flatiron District you'll find Union Square, a bustling crossroads at all times of
                    day and night"
                wrapMode: Text.Wrap
                color: "white"
            }
        }

        function getHeightColumn(){
            return head.height + address.height + phones.height /*+ cuisine.height*/ + description.height + 100
        } 
    }

}



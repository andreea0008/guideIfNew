import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
import "Delegates"
import "Window"
import "Cells"
import "Delegates/lists"

Rectangle {
    id: window
    anchors.top: topHead.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: panelManager.top
    visible: panelManager.idPanelButton === 5
    default property PanelManager panelManager : PanelManager
    color: "#1b1b1b"

    onVisibleChanged: console.log("visible")

    ColumnLayout{
        implicitHeight: parent.height
        implicitWidth: parent.width
        height: window.height * 0.3
        Item{
            id: itemStatistic
            anchors.left: parent.left
            anchors.leftMargin: window.width * 0.05
            anchors.top: parent.top
            anchors.right: parent.right
            height: window.height * 0.1
            Text{
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: check.left

                text: "I want send statistic"
                color: "white"
            }

            Check{
                id: check
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                height: parent.height * 0.6
                width: height

                onIsActiveChanged: {
                    ReportSelectedCompany.setNameFavoritesCompany(LoveCompanies.listCompanyForReport(),
                                                                  FavoriteCompanies.listCompanyForReport(),
                                                                  CrownCompanies.listCompanyForReport())
                }
            }
        }

        Item{
            id: itemUpdate
            anchors.left: parent.left
            anchors.leftMargin: window.width * 0.05
            anchors.top: itemStatistic.bottom
            anchors.right: parent.right
            height: window.height * 0.1
            Text{
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right

                text: "Update information"
                color: "white"
            }

            UpdateButton{
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                visibleSettingsPage: window.visible

            }
        }

        Item{
            anchors.left: parent.left
            anchors.leftMargin: window.width * 0.05
            anchors.top: itemUpdate.bottom
            anchors.right: parent.right
            height: window.height * 0.5



            Text{
                id: titleFeedback
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height * 0.2
                text: "Please, write some words about our application"
                verticalAlignment: Text.AlignVCenter
                color: "white"
            }

            TextArea{
                id: textEditMessage
                anchors.top: titleFeedback.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height * 0.6
                color: "white"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                wrapMode: Text.Wrap

                background: Rectangle{
                    color: "transparent"
                    radius: height * 0.05
                    border.color: "#bdc3c7"
                }
            }

            Item {
                id: itemSendButton
                anchors.top: textEditMessage.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: parent.height * 0.2

                Rectangle{
                    id: rectButtonSend
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    height: parent.height * 0.75
                    width: height * 2.5
                    radius: height * 0.2
                    color: mouseAreaButtonSend.pressed ? "#65c6bb" : "#16A086"

                    Item {
                        id: itemForIconAndText
                        anchors.fill: parent
                        Item{
                            id: itemImage
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            width: parent.height
                            Image {
                                id: icon
                                source: "qrc:/Delegates/img/mail_send.png"
                                anchors.centerIn: parent
                                width: parent.width * 0.5
                                height: width
                                antialiasing: true
                            }
                        }

                        Item{
                            id: itemButton
                            anchors.left: itemImage.right
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom

                            Text {
                                id: textButton
                                text: qsTr("Send")
                                anchors.centerIn: parent
                                anchors.leftMargin: (icon.width /2) * (-1)
                                verticalAlignment: Text.AlignVCenter
                                color: "white"
                                font.bold: true
                            }
                        }
                    }
                    MouseArea{
                        id: mouseAreaButtonSend
                        anchors.fill: parent

                        onReleased: {
                            if(textEditMessage.text.length >= 4){
                                Feedback.sendFeedbackAboutApplication(textEditMessage.text)
                                textEditMessage.clear()
                                textEditMessage.focus = false
                            }
                        }
                    }
                }
            }
        }
    }
}

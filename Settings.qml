import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
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
            anchors.top: parent.top
            anchors.right: parent.right
            height: window.height * 0.1
            Text{
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: window.width * 0.1
                anchors.right: check.left

                text: "I want send statistic"
                color: "white"
            }

            Check{
                id: check
                anchors.right: parent.right
                anchors.rightMargin: window.width * 0.05
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
            anchors.left: parent.left
            anchors.top: itemStatistic.bottom
            anchors.right: parent.right
            height: window.height * 0.1
            Text{
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: window.width * 0.1
                anchors.right: parent.right

                text: "Update information"
                color: "white"
            }

            UpdateButton{
                anchors.right: parent.right
                anchors.rightMargin: window.width * 0.05
                anchors.verticalCenter: parent.verticalCenter
                visibleSettingsPage: window.visible

            }
        }
    }
}

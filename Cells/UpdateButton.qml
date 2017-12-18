import QtQuick 2.0

Rectangle {
    id: control
    width: 75
    height: 25

    color: "#f40612"

    property bool isUpdate: false
    property bool existUpdates: false
    property bool visibleSettingsPage: true
    onVisibleSettingsPageChanged: {
        textButton.text = "Update"
    }

    radius: 3

    Connections{
        target: Settings
        onUpdateExistChanged:{
            console.log(updateExist)
            isUpdate = true
            existUpdates = updateExist
            if(existUpdates){
                control.color = "#16A086"
                textButton.text = "Install"
            }
            else
                textButton.text = "Not update"
        }
    }

    Text{
        id: textButton
        anchors.centerIn: parent
        text: Settings.updateExist ? "132" : "Update"
        color: "#ECF0F1"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("press_update_or_install")
            if(isUpdate){
                console.log("Install updates")
            }else{
                console.log("Update")
                Settings.getUpdateExist();
            }
        }
    }


}

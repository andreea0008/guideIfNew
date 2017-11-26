import QtQuick 2.5
import QtQuick.Controls 2.1
import com.guide.Category 1.0
import "Delegates"
import "Window"
import "Delegates/lists"

StackView{
    id: stackAllCategory
    anchors.top: topHead.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: panelManager.top
    visible: panelManager.idPanelButton === 4

    default property PanelManager panelManager : PanelManager

    onVisibleChanged: {
        if(!visible)
            releaseStack()
    }

    focus: true
    Keys.onReleased: if ((event.key === Qt.Key_Escape || event.key === Qt.Key_Back) && stackAllCategory.depth > 1) {
                         stackAllCategory.pop();
                         event.accepted = true;
                     }

    initialItem: Rectangle{
        width: parent.width
        height: parent.height
        color: "#1b1b1b"

        ListView{
            id: list
            anchors.fill: parent
            spacing: 3
            clip: true
            model: CrownCompanies
            antialiasing: true

            delegate: DelegateSceneItemsList{
                id: delegateItem
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: parent.width * 0.01
                anchors.rightMargin: parent.width * 0.01

                height: stackAllCategory.height / 15

                Rectangle{
                    anchors.fill: parent
                    color: "#1b1b1b"
                }

                Rectangle{
                    width: parent.width
                    height: delegateItem.height
                    color: "#2b2b2a"//"#141414"
                    radius: height / 8

                    property int halfHeight: height/2
                    Text {
                        id: name
                        text: nameCompany
                        verticalAlignment: Text.AlignVCenter
                        color: "#fff"
                        height: parent.height
                        anchors.left: parent.left
                        anchors.leftMargin: height/2
                        font.pointSize: 12
                        font.family: fontLoader.name
                    }
                }

                draggedItemParent: list

//                onMoveRectangleRequested: LoveCompanies.move(from, to)

//                onClick: stackAllCategory.push(pathToFileCategory)

            }
        }

        Text{
            anchors.centerIn: parent
            visible:  list.count === 0
            text: qsTr("Немає обраних")
            color: "white"
        }

    }

    function releaseStack(){
        if(stackAllCategory.depth > 1){
            stackAllCategory.pop()
            releaseStack();
        }
    }
}

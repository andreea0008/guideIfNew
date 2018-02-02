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
    visible: panelManager.idPanelButton === 1

    default property PanelManager panelManager : PanelManager
    property alias listModel: list.model

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
            model: CATEGORY
            antialiasing: true

            delegate: DelegateSceneItemsList{
                id: delegateItem
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: parent.width * 0.01
                anchors.rightMargin: parent.width * 0.01

                height: /*stackAllCategory.height / 15*/ControllerSize.heightListDelegate

                property bool isPressed: false

                Rectangle{
                    anchors.fill: parent
                    color: "#1b1b1b"
                }

                Rectangle{
                    width: parent.width
                    height: delegateItem.height
                    radius: height / 8

                    gradient: Gradient{
                        GradientStop{ position: 0.0; color: "#2b2b2a"}
                        GradientStop{ position: 1.0; color: delegateItem.isPressed ? "#141414" : "#2b2b2a" }
                    }

                    property int halfHeight: height/2
                    Text {
                        id: name
                        text: categoryName
                        verticalAlignment: Text.AlignVCenter
                        color: "#fff"
                        height: parent.height
                        anchors.left: parent.left
                        anchors.leftMargin: height/2
                        font.pointSize: ControllerSize.heightPixelSize
                        font.family: fontLoader.name

//                        Rectangle{
//                            width: 200
//                            height: ControllerSize.heightPixelSize
//                            anchors.verticalCenter: parent.verticalCenter
//                        }
                    }
                }

//                draggedItemParent: list

//                onMoveRectangleRequested: CATEGORY.move(from, to)

//                onPressedButton: isPressed = true

//                onReleaseButton: isPressed = false
                onClick: {
                    ListCompanies.setTagGroup(tag)
                    if(pathToFileCategory !== "path_offline_category"){
                        stackAllCategory.push(Qt.resolvedUrl(pathToFileCategory))
                    }
                }
            }
        }
    }

    function releaseStack(){
        if(stackAllCategory.depth > 1){
            stackAllCategory.pop()
            releaseStack();
        }
    }
}

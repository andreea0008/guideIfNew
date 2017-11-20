import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2

Item{
    id: root

    default property Item contentItem
    property Item draggedItemParent

    onContentItemChanged:
        contentItem.parent = contentRectangleWrapper

    signal openSettingsItem()
    signal visibleItemsChange(var isVisibleItem)
    signal moveRectangleRequested(int from, int to)
    signal click();

    width: contentItem.width
    height: contentItem.height

    MouseArea{
        anchors.fill: parent
        onClicked: clicked()
    }

    Rectangle{
        id: contentRectangleWrapper
        anchors.fill: parent

        Drag.active: dragArea.drag.active

        Drag.hotSpot {
            x: contentItem.width /2
            y: contentItem.height /2
        }

        MouseArea{
            id: dragArea
            anchors.fill: parent
            drag.target: parent

            drag.axis: Drag.YAxis
            drag.smoothed: false

            onClicked: click()

            onReleased: {
                if(drag.active)
                    root.moveRectangleRquested()
            }
        }

        states: [
            State {
                when: dragArea.drag.active
                name: "dragging"

                ParentChange {
                    target: contentRectangleWrapper
                    parent: draggedItemParent
                }

                PropertyChanges{
                    target: contentRectangleWrapper
                    opacity: 0.5
                    anchors.fill: undefined
                    width: contentItem.width
                    height: contentItem.height
                }

                PropertyChanges{
                    target: contentRectangleWrapper
                    height: 0
                }
            }
        ]
    }


    Loader{
        id: topDropLoader
        active: model.index === 0
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.verticalCenter
        height: contentItem.height
        sourceComponent: Component{
            DraggableItemDropArea{
                dropIndex: 0
            }
        }
    }

    DraggableItemDropArea{
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.verticalCenter
        height: contentItem.height
        dropIndex: model.index + 1
    }

    function moveRectangleRquested(){
        var dropArea = contentRectangleWrapper.Drag.target
        if(!dropArea)
            return

        var dropIndex = dropArea.dropIndex
        if(model.index < dropIndex){
            dropIndex--
        }
        if(model.index === dropIndex)
            return

        moveRectangleRequested(model.index, dropIndex)
    }
}

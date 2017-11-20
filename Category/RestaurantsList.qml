import QtQuick 2.0
import "../Delegates"
import "../Window"
import "../Delegates/lists"
import com.guide.ListCompany 1.0


Item{
    property int idCategory: -1
    onIdCategoryChanged: {
        ListCompanies.setIndexCategory(idCategory)
    }

    ListView{
        id: list
        spacing: 3
        clip: true
        model: ListCompanies
        antialiasing: true
        anchors.fill: parent

        property int idCategory: 0



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

            onMoveRectangleRequested: CATEGORY.move(from, to)

            onClick: stackAllCategory.push("qrc:/Delegates/RestDelegate.qml")

        }
    }
}






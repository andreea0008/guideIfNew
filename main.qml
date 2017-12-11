import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import "Delegates"
import "Delegates/lists"
import "Window"
import "Cells"
import "Category"
import com.guide.Category 1.0


Window {
    id:window
    visible: true
    width: 360
    height: 640
    title: qsTr("Hello World")
    color: "#1b1b1b"
    flags: Qt.FramelessWindowHint | Qt.Window

    FontLoader{
        id: fontLoader
        source: "qrc:/fonts/fonts/helvetica.otf"
    }

    //    top
    TopHead{
        id: topHead
    }

    //    Item{
    //        id: topHead
    //        anchors.top: parent.top
    //        anchors.left: parent.left
    //        anchors.right: parent.right
    //        height: window.height * 0.1
    //        Rectangle{
    //            anchors.fill: parent
    //            color: "#242424"
    //            radius: parent.height / 3
    //            Rectangle{
    //                anchors.bottom: parent.bottom
    //                anchors.left: parent.left
    //                anchors.right: parent.right
    //                height: parent.radius
    //                color: "#242424"
    //            }
    //        }

    //        Image{
    //            id: backArrow
    //            height: parent.height * 0.5
    //            width: height
    //            anchors.left: parent.left
    //            anchors.leftMargin: height / 2
    //            anchors.verticalCenter: parent.verticalCenter
    //            source: "qrc:/Delegates/img/left-arrow.png"
    //            visible: stackAllCategory.depth > 1
    //            MouseArea{
    //                anchors.fill: parent
    //                onReleased: stackAllCategory.pop()
    //            }
    //        }

    //        Text{
    //            anchors.verticalCenter: parent.verticalCenter
    //            anchors.left: backArrow.visible ? backArrow.right : parent.left
    //            anchors.leftMargin: parent.height / 4
    //            font.pixelSize: parent.height * 0.6
    //            color: "#fff"
    //            text: "GuideIf"
    //            font.family: fontLoader.name
    //            font.bold: true
    //        }

    //        OnlineButton{
    //            anchors.right: parent.right
    //            anchors.rightMargin: 10
    //            anchors.verticalCenter: parent.verticalCenter
    //        }
    //    }

    //check
    //    Item{
    //        anchors.fill: parent
    //        Check{
    //            anchors.centerIn: parent.Center
    //            x: 100
    //            y: 100
    //        }
    //    }

    //top
    //    RestDelegate{
    //        anchors.fill: parent
    //        width: parent.width
    //        nameRestText: "Eataly"
    //    }

    //    Item{
    //        anchors.fill: parent


    StackCategory{
        id: stackAllCategory
        panelManager: panelManager
    }

    StackLoverCategory{
        id: stackLoverCategory
        panelManager: panelManager
    }

    StackFavoriteCategory{
        id: stackFavoriteCategory
        panelManager: panelManager
    }

    StackCrownCategory{
        id: stackCrownCategory
        panelManager: panelManager
    }

    //bottom
    PanelManager{
        id: panelManager
        anchors.bottom: parent.bottom
        width: parent.width

        onCategoryPressed: {
            if (stackAllCategory.depth > 1){
                stackAllCategory.pop()
                stackLoverCategory.pop
                stackFavoriteCategory.pop()
                stackCrownCategory.pop()
            }
        }



//        onIdPanelButtonChanged: {
//            console.log(idPanelButton, stackAllCategory.depth)
//            if(idPanelButton == 1){
//                stackAllCategory.visible = true
//                stackLoverCategory.visible = false
//                stackFavoriteCategory.visible = false
//            }
//            else if(idPanelButton == 2){
//                stackAllCategory.visible = false
//                stackLoverCategory.visible = true
//                stackFavoriteCategory.visible = false
//            }
//            else if(idPanelButton == 3){
//                stackAllCategory.visible = false
//                stackLoverCategory.visible = false
//                stackFavoriteCategory.visible = true
//            }
//            else{
//                stackAllCategory.visible = false
//                stackLoverCategory.visible = false
//            }
//        }
    }
}

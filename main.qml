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

    Settings{
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

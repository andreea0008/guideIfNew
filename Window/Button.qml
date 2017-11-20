import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle{
    id: box
    color: isChecked ? "#1b1b1b" : "#434443"

    property real koefHeight: 0.5
    property alias imageSource: img.source
    property bool isChecked: false
    property int idCategorie: 999
    property int currentIdSelect: 888

    signal menuCategoryChange(var idCategory)

    onCurrentIdSelectChanged: {
        if(currentIdSelect != idCategorie)
            isChecked = false
        else
            isChecked = true
    }

    Image{
        id: img
        source: "qrc:/Window/img/ic_burger_menu.png"
        height: parent.height * koefHeight
        width: height
        anchors.centerIn: parent
        antialiasing: true
    }

    MouseArea{
        anchors.fill: parent
        onPressed: {
            menuCategoryChange(idCategorie)
            isChecked = true
        }
    }    
}

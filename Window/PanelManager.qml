import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: mainItem
    height: parent.height * 0.1
    width: parent.width
    color: "#434443"

    property int widthButton: (width/5 - 1)
    property string category: "Кате Categ "
    property alias idPanelButton: categoriesItem.cat

    signal categoryPressed()

//    Rectangle{
//        anchors.top: parent.top
//        anchors.left: parent.left
//        anchors.right: parent.right
//        height: 1
//        color: "#fff"
//    }


    Item{
        id: categoriesItem
        property int cat: 1

        onCatChanged: {
            switch(cat){
                case 1: category = "Category"
                    break
                case 4: category = "Category"
                    break
                case 5: category = "Settings"
                    break
            }

        }
    }

    RowLayout{
        id: rowLayout
        anchors.fill: parent
//        anchors.topMargin: 1
        spacing: 0
        Button{
            id: categories
            Layout.preferredWidth: mainItem.width/5
            Layout.preferredHeight: mainItem.height
            isChecked: true
            idCategorie: 1
            currentIdSelect: categoriesItem.cat

            onMenuCategoryChange: {
                categoryPressed()
                categoriesItem.cat = idCategory
            }
        }
        Button{
            id: loveCategories
            Layout.preferredWidth: mainItem.width/5
            Layout.preferredHeight: mainItem.height
            imageSource: "qrc:/Delegates/img/favourite-star_not_selected.png"
            idCategorie: 2
            currentIdSelect: categoriesItem.cat

            onMenuCategoryChange: categoriesItem.cat = idCategory
        }
        Button{
            id: startCategories
            Layout.preferredWidth: mainItem.width/5
            Layout.preferredHeight: mainItem.height
            imageSource: "qrc:/Delegates/img/star.png"
            idCategorie: 3
            currentIdSelect: categoriesItem.cat

            onMenuCategoryChange: categoriesItem.cat = idCategory
        }
        Button{
            id: crownCategories
            Layout.preferredWidth: mainItem.width/5
            Layout.preferredHeight: mainItem.height
            imageSource: "qrc:/Delegates/img/crown.png"
            idCategorie: 4
            currentIdSelect: categoriesItem.cat

            onMenuCategoryChange: categoriesItem.cat = idCategory
        }
        Button{
            id: settings
            Layout.preferredWidth: mainItem.width/5
            Layout.preferredHeight: mainItem.height
            imageSource: "qrc:/Window/img/ic_settings.png"
            idCategorie: 5
            currentIdSelect: categoriesItem.cat

            onMenuCategoryChange: categoriesItem.cat = idCategory
        }
    }
}

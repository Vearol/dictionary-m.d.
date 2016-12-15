import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Item {
    id: medicamentTable
    anchors.fill: parent

   FocusScope {
       id: scope
       width: 400
       height: 300
       anchors.top: parent.top
       anchors.right: parent.right
       anchors.left: parent.left

       Rectangle {
           anchors.fill: parent

           TableView {
               anchors {
                   top: parent.top
                   left: parent.left
                   right: parent.right
                   bottom: parent.bottom
               }
               model: drugModel

               TableViewColumn {
                   role: "name"
                   title: "name"
               }
               TableViewColumn {
                   role: "creator"
                   title: "creator"
               }
               TableViewColumn {
                   role: "status"
                   title: "status"
               }
               TableViewColumn {
                   role: "price"
                   title: "price"
               }
               TableViewColumn {
                   role: "amount"
                   title: "amount"
               }
               TableViewColumn {
                   role: "dose"
                   title: "dose"
               }
               TableViewColumn {
                   role: "form"
                   title: "form"
               }
               TableViewColumn {
                   role: "cures"
                   title: "cures"
               }
           }
       }


        ElButton {
            width: parent.width
            height: 30
            anchors.top: scope.bottom

            text: "Back"
            onClicked: medicamentTable.destroy()
        }
    }
}

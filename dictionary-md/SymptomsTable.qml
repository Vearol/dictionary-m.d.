import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Item {
    id: symptomsTable
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
               model: diseaseModel

               TableViewColumn {
                   role: "name"
                   title: "name"
               }

               TableViewColumn {
                   role: "symptoms"
                   title: "symptoms"
                   width: 600
               }
           }
       }


        Button {
            width: parent.width
            height: 30
            anchors.top: scope.bottom
            text: "Back"
            onClicked: symptomsTable.destroy()
        }
    }
}

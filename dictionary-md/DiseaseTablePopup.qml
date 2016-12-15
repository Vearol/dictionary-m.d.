import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import "Colors.js" as Colors

Item {
    id: diseaseTable
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
               }
               TableViewColumn {
                   role: "procedures"
                   title: "procedures"
               }
               TableViewColumn {
                   role: "drugs"
                   title: "drugs"
               }
           }
       }

       Rectangle {
           id: addNewRow
           anchors.top: scope.bottom
           height: 50
           width: parent.width
           color: Colors.disabledTextColor

           Text {
               anchors.left: parent.left
               anchors.margins: 5
               height: 20
               width: 30
               text: "Name:"
           }
           Rectangle {
               anchors.left: parent.left
               anchors.leftMargin: 50
               anchors.margins: 5
               height: 20
               width: 100

               TextEdit {
                   id: newName
                   anchors.fill: parent
               }
           }

           Text {
               anchors.left: parent.left
               anchors.leftMargin: 165
               anchors.margins: 5
               height: 20
               width: 50
               text: "Symptoms:"
           }
           Rectangle {
               anchors.left: parent.left
               anchors.leftMargin: 250
               anchors.right: parent.right
               anchors.margins: 5
               height: 20

               TextEdit {
                   id: newSymptoms
                   anchors.fill: parent
               }
           }
           Text {
               anchors.bottom: parent.bottom
               anchors.left: parent.left
               anchors.margins: 5
               height: 20
               width: 50
               text: "Procedures:"
           }
           Rectangle {
               anchors.bottom: parent.bottom
               anchors.left: parent.left
               anchors.leftMargin: 90
               anchors.margins: 5
               height: 20
               width: 350

               TextEdit {
                   id: newProcedures
                   anchors.fill: parent
               }
           }
           Text {
               anchors.bottom: parent.bottom
               anchors.left: parent.left
               anchors.leftMargin: 450
               anchors.margins: 5
               height: 20
               width: 30
               text: "Drugs:"
           }
           Rectangle {
               anchors.bottom: parent.bottom
               anchors.left: parent.left
               anchors.leftMargin: 500
               anchors.right: parent.right
               anchors.margins: 5
               height: 20

               TextEdit {
                   id: newDrugs
                   anchors.fill: parent
               }
           }
       }

       Rectangle {
           id: removeRow
           anchors.top: addNewRow.bottom
           height: 25
           width: parent.width
           color: Colors.darkGrayColor

           Text {
               anchors.left: parent.left
               anchors.margins: 5
               height: 20
               width: 30
               text: "Name:"
               color: Colors.normalTextColor
           }
           Rectangle {
               anchors.left: parent.left
               anchors.leftMargin: 50
               anchors.margins: 5
               height: 20
               width: 100

               TextEdit {
                   id: nameToRemove
                   anchors.fill: parent
               }
           }

           Button {
               anchors.right: parent.right
               anchors.rightMargin: 500
               width: 100
               text: "Remove"
               enabled: nameToRemove.text != ""
               onClicked: dict.removeRow(nameToRemove.text, "disease")
           }

           Button {
               anchors.right: parent.right
               anchors.rightMargin: 50
               width: 100
               text: "Back"
               onClicked: diseaseTable.destroy()
           }

           Button {
               anchors.right: parent.right
               anchors.rightMargin: 250
               width: 200
               text: "Add"
               enabled: {
                   if (newDrugs.text == "" || newName.text == "" || newProcedures.text == "" || newSymptoms.text == "")
                       return false;
                   else
                       return true;
               }

               onClicked: {
                   dict.addRow(newName.text, newSymptoms.text, newProcedures.text, newDrugs.text, "disease");
                   diseaseTable.update()
               }
           }
       }

   }
}


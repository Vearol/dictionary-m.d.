import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Window {
    visible: true
    minimumWidth: 800
    minimumHeight: 600

    Rectangle {
        visible: true
        width: 800
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
    }

}


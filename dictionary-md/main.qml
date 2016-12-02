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
            Button {
                text: "Set data"
                onClicked: diseaseModel.setData(index)
            }
            Text {
                id: select1
                text: qsTr("Select by:")
            }
            Button {
                onClicked: diseaseModel.getData(select1.text)
            }
        }
    }


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
                model: drugModel

                TableViewColumn {
                    role: "name"
                    title: "name"
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
                    role: "creator"
                    title: "creator"
                }
                TableViewColumn {
                    role: "form"
                    title: "form"
                }
                TableViewColumn {
                    role: "dose"
                    title: "dose"
                }
            }
            Button {
                text: "Set data"
                onClicked: drugModel.setData(index)
            }
        }
        Text {
            id: select2
            text: qsTr("Select by:")
        }
        Button {
            onClicked: drugModel.getData(select2.text)
        }
    }
}


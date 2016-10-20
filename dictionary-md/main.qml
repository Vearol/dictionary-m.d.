import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    minimumWidth: 800
    minimumHeight: 600

    Rectangle {
        width: 500
        height: 500
        MouseArea {
            anchors.fill: parent
            Text {
                id: text1
                anchors.verticalCenterOffset: 20
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Testing")
                font.pixelSize: 12
                }
            ListView {
                id: list_view1
                x: 125
                y: 100
                width: 110
                height: 160
                delegate: DBdelegate {}
                model: dbmodel
            }
        }
    }
}


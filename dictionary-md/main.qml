import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import "Colors.js" as Colors


Window {
    id: mainWindow
    visible: true
    minimumWidth: 800
    minimumHeight: 600
    color: Colors.applicationBackgroundColor

    Image {
        source: "file:///home/lyubomyr/Projects/dictionary-md/picture.jpg"
        anchors.fill: parent
        height: 300
        width: 300
        cache: true
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width
        height: 60
        color: Colors.darkGrayColor

        Rectangle{
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            height: 20
            width: 200
            Text {
                anchors.fill: parent
                anchors.leftMargin: 5
                text: dict.currentProgress()
            }
        }

        ActiveButton {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 40


            height: 35
            width: 130

            text: "Disease Table"

            function launchDialog(componentName, directParent, options) {
                var component = Qt.createComponent(componentName);
                if (component.status !== Component.Ready) {
                    console.debug("Component Error: " + component.errorString());
                } else {
                    var instance = component.createObject(directParent, options);
                }
            }

            onClicked: {
                launchDialog("DiseaseTablePopup.qml", mainWindow, {})
            }
        }

        ActiveButton {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.rightMargin: 200
            anchors.right: parent.right

            height: 35
            width: 130

            text: "Drug Table"

            function launchDialog(componentName, directParent, options) {
                var component = Qt.createComponent(componentName);
                if (component.status !== Component.Ready) {
                    console.debug("Component Error: " + component.errorString());
                } else {
                    var instance = component.createObject(directParent, options);
                }
            }

            onClicked: {
                launchDialog("MedicamentTablePopup.qml", mainWindow, {})
            }
        }

        ActiveButton {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.rightMargin: 360
            anchors.right: parent.right

            height: 35
            width: 130

            text: "Recipe"

            function launchDialog(componentName, directParent, options) {
                var component = Qt.createComponent(componentName);
                if (component.status !== Component.Ready) {
                    console.debug("Component Error: " + component.errorString());
                } else {
                    var instance = component.createObject(directParent, options);
                }
            }

            onClicked: {
                launchDialog("RecipePopup.qml", mainWindow, {})
            }
        }
    }
}


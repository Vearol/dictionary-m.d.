import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import "Colors.js" as Colors

Item {
    id: recipe
    anchors.fill: parent

    FocusScope {
        width: parent.width
        height: parent.height/2 + 200
        Rectangle {
            anchors.fill: parent
            color: Colors.normalGrayColor

            Text {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 25
                anchors.leftMargin: 10
                font.pixelSize: 15
                text: "Enter your disease name:"
                color: Colors.darkGrayColor
            }

            Rectangle {
                id: inputDiseaseArea
                width: 250
                height: 40
                color: Colors.darkGrayColor
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 200

                TextEdit {
                    id: inputText
                    color: Colors.normalTextColor
                    width: 100
                    anchors.fill: parent
                    anchors.margins: 10

                }
            }

            Text {
                anchors.top: inputDiseaseArea.bottom
                anchors.left: parent.left
                anchors.topMargin: 20
                anchors.leftMargin: 10
                font.pixelSize: 15
                text: "Best drug for you: "
                color: Colors.darkGrayColor
            }

            Text {
                id: outputText
                anchors.top: inputDiseaseArea.bottom
                anchors.left: parent.left
                anchors.topMargin: 15
                anchors.leftMargin: 150
                font.pixelSize: 20
                color: Colors.blueActiveColor
            }

            Text {
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 180
                anchors.leftMargin: 10
                color: Colors.darkGrayColor
                font.pixelSize: 15
                text: "If you don't know what is your disease \n check the symptoms table"
            }

            ElButton {
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 180
                anchors.leftMargin: 290

                height: 50
                width: 100

                text: "Symptoms\n Table"

                function launchDialog(componentName, directParent, options) {
                    var component = Qt.createComponent(componentName);
                    if (component.status !== Component.Ready) {
                        console.debug("Component Error: " + component.errorString());
                    } else {
                        var instance = component.createObject(directParent, options);
                    }
                }

                onClicked: {
                    launchDialog("SymptomsTable.qml", mainWindow, {})
                }
            }
            Text {
                id: restDrugs
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 260
                anchors.leftMargin: 10
                color: Colors.darkGrayColor
                font.pixelSize: 15
            }

        }
        Rectangle {
            id: bestDrugInfo
            width: 380
            height: 200
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10
            color: Colors.normalGrayColor

            Text {
                id: creatorText
                font.pixelSize: 18
                anchors.left: parent.left
                anchors.top: parent.top
                color: Colors.darkGrayColor
            }
            Text {
                id: amountText
                font.pixelSize: 18
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 30
                color: Colors.darkGrayColor
            }
            Text {
                id: doseText
                font.pixelSize: 18
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 200
                color: Colors.darkGrayColor
            }
            Text {
                id: formText
                font.pixelSize: 18
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 30
                anchors.leftMargin: 200
                color: Colors.darkGrayColor
            }
            Text {
                id: priceText
                font.pixelSize: 20
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: 60
                anchors.leftMargin: 200
                color: Colors.blueActiveColor
            }
        }


        Button {
            width: 70
            height: 30
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.bottomMargin: 20
            anchors.leftMargin: 20
            text: "Back"
            onClicked: recipe.destroy()
        }

        ActiveButton {
            width: 200
            height: 30
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 100
            anchors.topMargin: 25
            text: "Form Recipe"
            enabled: inputText.text != ""
            onClicked: {
                drugStore.formResipe(inputText.text)
                outputText.text = drugStore.getBestName()
                amountText.text = "Amount:  " + drugStore.getBestAmount()
                formText.text = "Form:  " + drugStore.getBestForm()
                doseText.text = "Dose:  " + drugStore.getBestDose()
                creatorText.text = "Creator:  " + drugStore.getBestCreator()
                priceText.text = "Price: " + drugStore.getBestPrice() + " $"
                restDrugs.text = drugStore.restDrugs();
            }
        }
    }
}

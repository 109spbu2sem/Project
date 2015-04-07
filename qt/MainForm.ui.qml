import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import scene.module 1.0

GridLayout
{
    columns: 2
    columnSpacing: 40

    x: 40
    y: 35

    Rectangle
    {
        id: backgroundRect

        width: 860
        height: 640
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.minimumWidth: 600
        Layout.minimumHeight: 400

        color: "white"

        Canvas
        {
            id: mainCanvas

            anchors.fill: parent

            MouseArea
            {
                anchors.fill: parent

                onPressed:
                {
                    xpos = mouseX
                    ypos = mouseY
                    mainCanvas.requestPaint()
                    statusBar.text = changeStatusBar("Project changed")
                }
                onMouseXChanged:
                {
                    xpos = mouseX
                    ypos = mouseY
                    mainCanvas.requestPaint()
                }
                onMouseYChanged:
                {
                    xpos = mouseX
                    ypos = mouseY
                    mainCanvas.requestPaint()
                }
            }

            onPaint:
            {
                var ctx = getContext('2d')
                ctx.fillStyle = "lightblue"
                ctx.fillRect(xpos - 2, ypos - 1, 5, 5)

            }
        }
    }

    GridLayout
    {
        width: 300
        rows: 2
        rowSpacing: 40

        Rectangle
        {
            x: 0
            y: 0
            width: 300
            height: 500
            Layout.fillHeight: true

            Text
            {
                id: textList
                enabled: true

                x: 0
                y: 0
                width: 300
                height: 500
                Layout.row: 1

                text: " List of all objects:"
                font.bold: true
                horizontalAlignment: Text.AlignLeft
                wrapMode: Text.NoWrap
                textFormat: Text.PlainText
                font.pixelSize: 16
            }
        }

        GridLayout
        {
            id: buttonGridLayout

            y: parent.height

            rows: 2
            columns: 2
            Layout.row: 2
            rowSpacing: 10
            columnSpacing: 10

            Item
            {
                x: 0
                y: -40
                width: 145
                height: 42

                ToolButton
                {
                    id: addObjectButton

                    activeFocusOnPress: true
                    onClicked: addObjectDialog.open()

                    width: 145
                    height: 42

                    text: "Add object"
                }
            }

            Item
            {
                x: 0
                y: 12
                width: 145
                height: 42

                ToolButton
                {
                    id: addRuleButton

                    activeFocusOnPress: true
                    enabled: false

                    width: 145
                    height: 42

                    text: "Add rule"
                }
            }

            Item
            {
                x: 155
                y: -40
                width: 145
                height: 42

                ToolButton
                {
                    id: loadButton

                    activeFocusOnPress: true
                    onClicked: {  fileDialog.open(); }

                    width: 145
                    height: 42

                    text: "Load..."
                }
            }

            Item
            {
                x: 155
                y: 12
                width: 145
                height: 42

                ToolButton
                {
                    id: saveButton

                    width: 145
                    height: 42

                    text: "Save..."
                }
            }
        }
    }
}

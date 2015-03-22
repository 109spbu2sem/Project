import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow
{
    visible: true

    title: qsTr("Paint")

    width: 1280
    height: 720

    menuBar: MenuBar
    {
        Menu
        {
            title: qsTr("Project")

            MenuItem
            {
                text: qsTr("&Open new...")
                shortcut: "Ctrl+Shift+N"
                onTriggered: loadButton.clicked();
            }

            MenuSeparator {}

            MenuItem
            {
                text: qsTr("&Open existing...")
                shortcut: "Ctrl+O"
                onTriggered: loadButton.clicked();
            }

            MenuItem
            {
                text: qsTr("&Save...")
                shortcut: "Ctrl+S"
                onTriggered: console.log("Save action triggered");
            }

            MenuItem
            {
                text: qsTr("&Print")
                shortcut: "Ctrl+P"
                onTriggered: console.log("Print action triggered");
            }

            MenuItem
            {
                text: qsTr("Close project")
                shortcut: "Ctrl+E"
                onTriggered: console.log("Close action triggered");
            }
        }

        Menu
        {
            title: qsTr("Settings")

            MenuItem
            {
                text: qsTr("&Change language")
                shortcut: "Alt+L"
            }

            MenuItem
            {
                text: qsTr("&Change GUI")
                shortcut: "Alt+G"
            }
        }

        Menu
        {
            title: qsTr("Help")

            MenuItem
            {
                text: qsTr("&About Paint")
            }

            MenuItem
            {
                text: qsTr("&Send feedback")
            }
        }
    }

    FileDialog
    {
        id: fileDialog
        title: "Please choose a file"

        onAccepted:
        {
            console.log("You chose: " + fileDialog.fileUrls)
        }
        onRejected:
        {
            console.log("Canceled")
        }
    }

    Dialog
    {
        id: addObjectDialog

        contentItem: Rectangle
            {
                implicitWidth: 340
                implicitHeight: 200

                color: "lightblue"

                Text
                {
                    id: title

                    x: 10
                    y: 5

                    text: "Choose type of object"
                    color: "white"
                    font.bold: true
                    style: Text.Raised
                }

                Grid
                {
                    id: objectChoose

                    x: 10
                    y: 25

                    Row
                    {
                        spacing: 10

                        ToolButton
                        {
                            id: pointAddObjectDialogButton

                            width: 100
                            height: 130

                            Rectangle
                            {
                                width: 100
                                height: 100

                                color: "red"
                            }

                            Text
                            {
                                id:textPoint

                                y: 100
                                width: 100
                                height: 30
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                text: "Point"
                            }

                            onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Point");  }
                        }

                        ToolButton
                        {
                            id: sectionAddObjectDialogButton

                            width: 100
                            height: 130

                            Rectangle
                            {  
                                width: 100
                                height: 100

                                color: "green"
                            }

                            Text
                            {
                                id: textSection

                                y: 100
                                width: 100
                                height: 30
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                text: "Section"
                            }

                            onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Section");  }
                        }

                        ToolButton
                        {
                            id: arcAddObjectDialogButton

                            width: 100
                            height: 130

                            Rectangle
                            {
                                width: 100
                                height: 100

                                color: "blue"
                            }

                            Text
                            {
                                id: textArc

                                y: 100
                                width: 100
                                height: 30
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                text: "Arc"
                            }

                            onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Arc");  }
                        }
                    }
                }

                Button
                {
                    id: okAddObjectDialogButton
                    onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Nothing");  }

                    x: 10
                    y: 175
                    width: 90
                    height: 21

                    text: "OK"
                }
            }
    }

    Item
    {
        id: workspace

        x: -300
        y: -400
        width: 1600
        height: 1400
    }


    GridLayout
    {
        columns: 2
        columnSpacing: 40

        x: 40
        y: 40
        width: parent.width - 80
        height: parent.height - 80

        Rectangle
        {
            id: rectangle

            width: 860
            height: 640
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 600
            Layout.minimumHeight: 400

            color: "#ffffff"
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
                width: 300
                height: 200

                rows: 2
                columns: 2
                Layout.row: 2
                rowSpacing: 10
                columnSpacing: 10

                ToolButton
                {
                    id: addObjectButton
                    x: 0
                    y: -40
                    activeFocusOnPress: true
                    onClicked: addObjectDialog.open()

                    width: 145
                    height: 42

                    text: "Add object"
                }

                ToolButton
                {
                    id: loadButton
                    x: 155
                    y: -40
                    activeFocusOnPress: true
                    onClicked: fileDialog.open()

                    width: 145
                    height: 42

                    text: "Load..."
                }

                ToolButton
                {
                    id: addRuleButton
                    x: 0
                    y: 12
                    activeFocusOnPress: true
                    enabled: false

                    width: 145
                    height: 42

                    text: "Add rule"
                }

                ToolButton
                {
                    id: saveButton
                    x: 155
                    y: 12

                    width: 145
                    height: 42

                    text: "Save..."
                }
            }
        }
    }
}

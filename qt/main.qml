import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2

ApplicationWindow
{
    visible: true

    width: 1280
    height: 720

    title: qsTr("Paint")

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
                color: "lightblue"
                implicitWidth: 340
                implicitHeight: 200

                Text
                {
                    id: title
                    x: 10
                    y: 5
                    color: "white"
                    font.bold: true
                    style: Text.Raised
                    text: "Choose type of object"
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
                                color: "red"
                                width: 100
                                height: 100
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
                                color: "green"
                                width: 100
                                height: 100
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
                                color: "blue"
                                width: 100
                                height: 100
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
                    x: 10
                    y: 175
                    width: 90
                    height: 21
                    text: "OK"
                    onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Nothing");  }
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

    ToolButton
    {
        id: addObjectButton
        x: 952
        y: 564
        width: 120
        height: 42
        text: "Add object"
        activeFocusOnPress: true
        onClicked: addObjectDialog.open()
    }

    ToolButton
    {
        id: loadButton
        x: 952
        y: 636
        width: 120
        height: 42
        text: "Load..."
        activeFocusOnPress: true
        onClicked: fileDialog.open()
    }

    ToolButton
    {
        id: addRuleButton
        x: 1120
        y: 564
        width: 120
        height: 42
        text: "Add rule"
        activeFocusOnPress: true
        enabled: false
    }

    ToolButton
    {
        id: saveButton
        x: 1120
        y: 636
        width: 120
        height: 42
        text: "Save..."

    }

    Text
    {
        id: textList
        x: 952
        y: 27
        width: 288
        height: 506
        text: " List of all objects:"
        enabled: true
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.NoWrap
        textFormat: Text.PlainText
        font.pixelSize: 16
    }

    Rectangle
    {
        id: rectangle
        x: 38
        y: 27
        width: 870
        height: 651
        color: "#ffffff"
    }
}

import QtQuick 2.3
import QtQuick.Controls 1.2
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
        id: loadDialog

        contentItem: Rectangle
            {
                color: "lightblue"
                implicitWidth: 340
                implicitHeight: 200

                Text
                {
                    x: 10
                    y: 5
                    color: "white"
                    font.bold: true
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
                        Button
                        {
                            id: pointLoadDialogButton
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
                                id: textPoint
                                y: 110
                                horizontalAlignment: textPoint.AlignHCenter
                                text: "Point"
                            }
                            onClicked: {  loadDialog.close(); console.log("loadDialog -> Point");  }
                        }

                        Button
                        {
                            id: sectionLoadDialogButton
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
                                y: 110
                                horizontalAlignment: textSection.AlignHCenter
                                text: "Section"
                            }
                            onClicked: {  loadDialog.close(); console.log("loadDialog -> Section");  }
                        }

                        Button
                        {
                            id: arcLoadDialogButton
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
                                y: 110
                                horizontalAlignment: textArc.AlignHCenter
                                text: "Arc"
                            }
                            onClicked: {  loadDialog.close(); console.log("loadDialog -> Arc");  }
                        }
                    }
                }

                Button
                {
                    id: okLoadDialogButton
                    x: 10
                    y: 175
                    width: 90
                    height: 21
                    text: "Ok"
                    onClicked: {  loadDialog.close(); console.log("loadDialog -> Nothing");  }
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
        onClicked: loadDialog.open()
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
        id: text1
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
        id: rectangle1
        x: 38
        y: 27
        width: 870
        height: 651
        color: "#ffffff"
    }
}

